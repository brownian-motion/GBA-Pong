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

	// Create our sprites by writing their object attributes into OAM memory.
	volatile object_attributes *paddle_attributes = &oam_memory[0];
	paddle_attributes->attribute_zero = 0x8000; // This sprite is made up of 4bpp tiles and has the TALL shape.
	paddle_attributes->attribute_one = 0x4000; // This sprite has a size of 8x32 when the TALL shape is set.
	paddle_attributes->attribute_two = 1; // This sprite's base tile is the first tile in tile block 4, and this sprite should use colour palette 0.
	volatile object_attributes *ball_attributes = &oam_memory[1];
	ball_attributes->attribute_zero = 0; // This sprite is made up of 4bpp tiles and has the SQUARE shape.
	ball_attributes->attribute_one = 0; // This sprite has a size of 8x8 when the SQUARE shape is set.
	ball_attributes->attribute_two = 5; // This sprite's base tile is the fifth tile in tile block 4, and this sprite should use colour palette 0.

	// Initialize our variables to keep track of the state of the paddle and ball,
	// and set their initial positions (by modifying their attributes in OAM).
	const int player_width = 8, player_height = 32, ball_width = 8, ball_height = 8;
	const int player_max_clamp_y = SCREEN_HEIGHT - player_height;
	const int ball_max_clamp_x = SCREEN_WIDTH - ball_width, ball_max_clamp_y = SCREEN_HEIGHT - ball_height;
	int player_velocity = 2, ball_velocity_x = 2, ball_velocity_y = 1;
	int player_x = 5, player_y = 96;
	int ball_x = 22, ball_y = 96;
	setObjectPosition(paddle_attributes, player_x, player_y);
	setObjectPosition(ball_attributes, ball_x, ball_y);

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
		if (key_states & KEY_UP) { player_y = clamp(player_y - player_velocity, 0, player_max_clamp_y); }
		if (key_states & KEY_DOWN) { player_y = clamp(player_y + player_velocity, 0, player_max_clamp_y); }
		if (key_states & (KEY_UP | KEY_DOWN)) { setObjectPosition(paddle_attributes, player_x, player_y); }

		if ((ball_x >= player_x && ball_x <= player_x + player_width) && (ball_y >= player_y && ball_y <= player_y + player_height)) {
			// Respond to the ball hitting the left player's paddle
			// This is not good physics / collision handling code.
			ball_x = player_x + player_width;
			ball_velocity_x = -ball_velocity_x;
		} else {
			// Bounce off the walls
			if (ball_x <= 0 || ball_x >= ball_max_clamp_x) { ball_velocity_x = -ball_velocity_x; }
			if (ball_y <= 0 || ball_y >= ball_max_clamp_y) { ball_velocity_y = -ball_velocity_y; }
		}
		ball_x = clamp(ball_x + ball_velocity_x, 0, ball_max_clamp_x);
		ball_y = clamp(ball_y + ball_velocity_y, 0, ball_max_clamp_y);
		setObjectPosition(ball_attributes, ball_x, ball_y);
	}

	return 0;
}