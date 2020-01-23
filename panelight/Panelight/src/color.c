#include "color.h"
#include <stdlib.h>
typedef unsigned uint;

uint* create_rgb_array(uint color)
{
    uint* rgb_array = (uint*) malloc(3 * sizeof(uint));
    uint r = (color >> 16) & 0xFF;
	uint g = (color >> 8) & 0xFF;
	uint b = color & 0xFF;
    rgb_array[0] = r;
    rgb_array[1] = g;
    rgb_array[2] = b;
    return rgb_array;
}


uint hexa_merging(uint r, uint g, uint b)
{
    uint a_ = r & 0xF;
    uint b_ = (r >> 4) & 0xF;
	uint c_ = g & 0xF;
    uint d_ = (g >> 4) & 0xF;
	uint e_ = b & 0xF;
	uint f_ = (b >> 4) & 0xF;
	return e_ + (f_*16) + (c_*16*16) + (d_*16*16*16) + (a_*16*16*16*16) + (b_*16*16*16*16*16);
}
