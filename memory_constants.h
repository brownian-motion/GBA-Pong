#pragma once

#define BG0 1
#define BG1 2
#define BG2 4
#define BG3 8
#define BG4 16
#define BG5 32

#define MEM_ADDR_IO_RAM 0x04000000
#define MEM_ADDR_VRAM 0x06000000

#define SCREEN_WIDTH 240

#define MASK_RED 0x001F
#define MASK_GREEN 0x03E0
#define MASK_BLUE 0x7C00

inline unsigned short rgb(unsigned short r, unsigned short g, unsigned short b){
	return (r & MASK_RED) | ((g << 5) & MASK_GREEN) | ((b << 10) & MASK_BLUE);
}

inline unsigned short red(unsigned short color){
	return color & MASK_RED;
}

inline unsigned short green(unsigned short color){
	return (color & MASK_GREEN) >> 5;
}

inline unsigned short blue(unsigned short color){
	return (color & MASK_BLUE) >> 10;
}

inline int xy(unsigned int x, unsigned int y){
	return SCREEN_WIDTH*y + x;
}

inline int getXFromCoordinate(unsigned int coordinate){
	return coordinate % SCREEN_WIDTH;
}

inline int getYFromCoordinate(unsigned int coordinate){
	return coordinate / SCREEN_WIDTH;
}