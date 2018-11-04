#pragma once
#include "memory_types.h"

static inline int rect_left(rect_t r) {
	return r.pos.x;
}
static inline int rect_right(rect_t r) {
	return r.pos.x + r.width;
}
static inline int rect_top(rect_t r) {
	return r.pos.y;
}
static inline int rect_bottom(rect_t r) {
	return r.pos.y + r.height;
}

// See: https://stackoverflow.com/questions/306316/determine-if-two-rectangles-overlap-each-other
static inline int intersects(rect_t r1, rect_t r2) {
	return rect_left(r1) < rect_right(r2) && rect_right(r1) > rect_left(r2)
	       && rect_top(r1) < rect_bottom(r2) && rect_bottom(r1) > rect_top(r2);
}