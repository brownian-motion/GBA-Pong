#pragma once

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef uint16 rgb15;
typedef uint32 xyCoord;
typedef struct object_attributes {
	uint16 attribute_zero;
	uint16 attribute_one;
	uint16 attribute_two;
	uint16 pad;
} __attribute__((aligned(4))) object_attributes;
typedef uint32 tile4bpp[8];
typedef tile4bpp tile_block[512];

#define BG0 1
#define BG1 2
#define BG2 4
#define BG3 8
#define BG4 16
#define BG5 32

#define MEM_ADDR_IO_RAM 		0x04000000
#define MEM_ADDR_COLOR_PALETTE 	0x05000000
#define MEM_ADDR_VRAM 			0x06000000
#define MEM_ADDR_OAM 			0x07000000

#define MEM_ADDR_KEYINPUT_IO_REGISTER 	0x04000130


#define MEM_ADDR_COLOR_PALETTE_BLOCK_1 	0x5000200
#define MEM_ADDR_TILE_BLOCK_4 			0x6010000
#define MEM_ADDR_TILE_BLOCK_5 			0x6014000

#define SCREEN_HEIGHT 	160
#define SCREEN_WIDTH 	240

#define MASK_RED 	0x001F
#define MASK_GREEN 	0x03E0
#define MASK_BLUE 	0x7C00

#define REG_DISPLAY        (*((volatile uint32 *)(MEM_ADDR_IO_RAM)))
#define REG_DISPLAY_VCOUNT (*((volatile uint32 *)(MEM_ADDR_IO_RAM + 0x0006)))  //Count of lines drawn. This varies from 0 to 227. If >= SCREEN_HEIGHT, then we're in a VBLANK
#define REG_KEY_INPUT      (*((volatile uint32 *)(MEM_ADDR_IO_RAM + 0x0130)))

#define KEY_UP     0x0040
#define KEY_DOWN   0x0080
#define KEY_ANY    0x03FF

#define OBJECT_ATTRIBUTE_ZERO_Y_MASK  0xFF
#define OBJECT_ATTRIBUTE_ONE_X_MASK  0x1FF

#define oam_memory ((volatile object_attributes *)MEM_ADDR_OAM)
#define tile_memory ((volatile tile_block *)MEM_ADDR_VRAM)
#define object_palette_memory ((volatile rgb15 *)(MEM_ADDR_COLOR_PALETTE + 0x200))

static inline rgb15 rgb(unsigned short r, unsigned short g, unsigned short b){
	return r | (g << 5) | (b << 10);
}

static inline unsigned short red(rgb15 color){
	return color & MASK_RED;
}

static inline unsigned short green(rgb15 color){
	return (color & MASK_GREEN) >> 5;
}

static inline unsigned short blue(rgb15 color){
	return (color & MASK_BLUE) >> 10;
}

static inline xyCoord xy(unsigned int x, unsigned int y){
	return SCREEN_WIDTH*y + x;
}

static inline int getXFromCoordinate(xyCoord coordinate){
	return coordinate % SCREEN_WIDTH;
}

static inline int getYFromCoordinate(xyCoord coordinate){
	return coordinate / SCREEN_WIDTH;
}

static inline int clamp(int value, int min, int max){
	return (value > max) ? max:((value < min) ? min : value);
}

static inline void setObjectPosition(volatile object_attributes* object, int x, int y){
	object->attribute_zero =
		(object->attribute_zero & ~OBJECT_ATTRIBUTE_ZERO_Y_MASK)
		| (y & OBJECT_ATTRIBUTE_ZERO_Y_MASK);

	object->attribute_one =
		(object->attribute_one & ~OBJECT_ATTRIBUTE_ONE_X_MASK)
		| (x & OBJECT_ATTRIBUTE_ONE_X_MASK);
}