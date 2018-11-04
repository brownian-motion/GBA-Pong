#include "memory_constants.h"

int main(void) {
	// Write the tiles for our sprites into the 4th tile block in VRAM.
	// Particularly, four tiles for an 8x32 paddle sprite, and 1 tile for an 8x8 ball sprite.
	// 0x1111 = 0001000100010001 [4bpp = colour index 1, colour index 1, colour index 1, colour index 1]
	// 0x2222 = 0002000200020002 [4bpp = colour index 2, colour index 2, colour index 2, colour index 2]
	// NOTE: We're using our own memory writing code here to avoid the byte-granular writes that
	// something like 'memset' might make (GBA VRAM doesn't support byte-granular writes).
	volatile uint16 *paddle_tile_memory = (uint16 *)tile_memory[4][1];
	for (int i = 0; i < 4 * (sizeof(tile4bpp) / 2); ++i) { paddle_tile_memory[i] = 0x1111; }
	volatile uint16 *ball_tile_memory = (uint16 *)tile_memory[4][5];
	for (int i = 0; i < (sizeof(tile4bpp) / 2); ++i) { ball_tile_memory[i] = 0x2222; }

	// Write the colour palette for our sprites into the first palette of
	// 16 colours in colour palette memory (this palette has index 0).
	object_palette_memory[1] = rgb(0x1F, 0x1F, 0x1F); // White
	object_palette_memory[2] = rgb(0x1F, 0x00, 0x1F); // Magenta
	object_palette_memory[3] = rgb(0x1F, 0x00, 0x00); // Red
	object_palette_memory[4] = rgb(0x00, 0x1F, 0x1F); // Cyan

	// Create our sprites by writing their object attributes into OAM memory.
	volatile object_attributes *player_paddle_attributes = &oam_memory[0];
	player_paddle_attributes->attribute_zero = 0x8000; // This sprite is made up of 4bpp tiles and has the TALL shape.
	player_paddle_attributes->attribute_one = 0x4000; // This sprite has a size of 8x32 when the TALL shape is set.
	player_paddle_attributes->attribute_two = 1; // This sprite's base tile is the first tile in tile block 4, and this sprite should use colour palette 0.
	volatile object_attributes *ball_attributes = &oam_memory[1];
	ball_attributes->attribute_zero = 0; // This sprite is made up of 4bpp tiles and has the SQUARE shape.
	ball_attributes->attribute_one = 0; // This sprite has a size of 8x8 when the SQUARE shape is set.
	ball_attributes->attribute_two = 5; // This sprite's base tile is the fifth tile in tile block 4, and this sprite should use colour palette 0.
	volatile object_attributes *enemy_paddle_attributes = &oam_memory[2];
	enemy_paddle_attributes->attribute_zero = 0x8000; // This sprite is made up of 4bpp tiles and has the TALL shape.
	enemy_paddle_attributes->attribute_one = 0x4000; // This sprite has a size of 8x32 when the TALL shape is set.
	enemy_paddle_attributes->attribute_two = 1; // This sprite's base tile is the first tile in tile block 4, and this sprite should use colour palette 0.

	// Initialize our variables to keep track of the state of the paddle and ball,
	// and set their initial positions (by modifying their attributes in OAM).
	const int paddle_width = 8, paddle_height = 32, ball_width = 8, ball_height = 8;
	const int paddle_max_y = SCREEN_HEIGHT - paddle_height;
	const struct v2 ball_max_clamp = {SCREEN_WIDTH - ball_width, SCREEN_HEIGHT - ball_height};
	int player_velocity = 2;
	struct v2 ball_vel = {2, 1};
	struct v2 player_pos = {5, 96};
	struct v2 ball_pos = {22, 96};
	struct v2 enemy_pos = {SCREEN_WIDTH - paddle_width - player_pos.x, player_pos.y}; // for symmetry
	setObjectPosition(player_paddle_attributes, player_pos.x, player_pos.y);
	setObjectPosition(ball_attributes, ball_pos.x, ball_pos.y);
	setObjectPosition(enemy_paddle_attributes, enemy_pos.x, enemy_pos.y);

	// Set the display parameters to enable objects, and use a 1D object->tile mapping.
	REG_DISPLAY = 0x1000 | 0x0040;

	// Our main game loop
	uint32 key_states = 0;
	while (1) {
		// Skip past the rest of any current V-Blank, then skip past the V-Draw
		while (REG_DISPLAY_VCOUNT >= 160);
		while (REG_DISPLAY_VCOUNT < 160);

		// Get current key states (REG_KEY_INPUT stores the states inverted)
		key_states = ~REG_KEY_INPUT & KEY_ANY;

		// Note that our physics update is tied to the framerate rather than a fixed timestep.
		if (key_states & KEY_UP) {
			player_pos.y = clamp(player_pos.y - player_velocity, 0, paddle_max_y);
			setObjectPosition(player_paddle_attributes, player_pos.x, player_pos.y);
		}
		if (key_states & KEY_DOWN) {
			player_pos.y = clamp(player_pos.y + player_velocity, 0, paddle_max_y);
			setObjectPosition(player_paddle_attributes, player_pos.x, player_pos.y);
		}

		// Move the enemy paddle to meet the ball rushing towards it
		if (ball_pos.y <= enemy_pos.y) {
			enemy_pos.y = clamp(enemy_pos.y - player_velocity, 0, paddle_max_y);
			setObjectPosition(enemy_paddle_attributes, enemy_pos.x, enemy_pos.y);
		} else if (ball_pos.y >= enemy_pos.y + paddle_height) {
			enemy_pos.y = clamp(enemy_pos.y + player_velocity, 0, paddle_max_y);
			setObjectPosition(enemy_paddle_attributes, enemy_pos.x, enemy_pos.y);
		}

		if ((ball_pos.x >= player_pos.x && ball_pos.x <= player_pos.x + paddle_width) && (ball_pos.y >= player_pos.y && ball_pos.y <= player_pos.y + paddle_height)) {
			// Respond to the ball hitting the left player's paddle
			// This is not good physics / collision handling code.
			ball_pos.x = player_pos.x + paddle_width;
			ball_vel.x = -ball_vel.x;
		} else if ((ball_pos.x >= enemy_pos.x && ball_pos.x <= enemy_pos.x + paddle_width) && (ball_pos.y >= enemy_pos.y && ball_pos.y <= enemy_pos.y + paddle_height)) {
			ball_pos.x = enemy_pos.x;
			ball_vel.x = -ball_vel.x;
		} else {
			// Bounce off the walls
			if (ball_pos.x <= 0 || ball_pos.x >= ball_max_clamp.x) { ball_vel.x = -ball_vel.x; }
			if (ball_pos.y <= 0 || ball_pos.y >= ball_max_clamp.y) { ball_vel.y = -ball_vel.y; }
		}

		// Move the ball
		ball_pos.x = clamp(ball_pos.x + ball_vel.x, 0, ball_max_clamp.x);
		ball_pos.y = clamp(ball_pos.y + ball_vel.y, 0, ball_max_clamp.y);
		setObjectPosition(ball_attributes, ball_pos.x, ball_pos.y);
	}

	return 0;
}