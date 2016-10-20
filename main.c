#include "memory_constants.h"

int main(void) {
	// Write into the I/O registers, setting video display parameters.
	volatile unsigned char *ioram = (unsigned char *) MEM_ADDR_IO_RAM;
	ioram[0] = 0x03; // Set the 'video mode' to 3 (in which BG2 is a 16 bpp bitmap in VRAM)
	ioram[1] = BG2; // Enable BG2 (BG0 = 1, BG1 = 2, BG2 = 4, ...)

	// Write pixel colours into VRAM
	volatile unsigned short *vram = (unsigned short *) MEM_ADDR_VRAM;
	vram[xy(115,80)] = rgb(MASK_RED,0,0); // X = 115, Y = 80, C = 000000000011111 = R
	vram[xy(120,80)] = rgb(0,MASK_RED,0); // X = 120, Y = 80, C = 000001111100000 = G
	vram[xy(125,80)] = rgb(0,0,MASK_RED); // X = 125, Y = 80, C = 111110000000000 = B

	// Wait forever
	while(1);

	return 0;
}