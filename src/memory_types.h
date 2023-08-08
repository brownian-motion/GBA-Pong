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
typedef uint32 tile4bpp[8]; // tile4bpp is 8 32-bit segments (or 16 16-bit segments)
typedef tile4bpp tile_block[512]; // tile_block is 512 tile4bpp segments
typedef struct v2 {
	int x, y;
} v2;
typedef struct rect {
	struct v2 pos;
	int width;
	int height;
} rect_t;