#pragma once

#include <chip.h>

#include "colors_def.h"

/*
const values
*/
#define CODE_0 0x7800
#define CODE_1 0x7FF0

/*
macros definitions
*/
#define GET_BIT(k, n) (k & (1 << (n)))

/*
enums definitions 
*/
typedef enum {
    UP,
    DOWN
} MODE;

/*
private variables sections
*/
static uint16_t LED_data;

/*
private functions sections
*/
void send(unsigned* values, int size);
extern MODE mode;
unsigned* create_colors_levels(const unsigned color, double bright);

/*
utility functions
*/
void init_data();
void deinit();
void clean_up(unsigned* values, int size);

/*
functions to mainpulate diodes
*/
void up_down(const unsigned color, unsigned* values, int size);
void up_down_two_col(const unsigned color1, const unsigned color2, unsigned* values, int size);
void gradient_center(const unsigned* colors, unsigned* values, int size);
void gradient(const unsigned* colors, unsigned* values, int size);
void wake_up(const unsigned color, double bright, bool flag, unsigned* values, int size);
void sleeping(const unsigned color, double bright, bool flag, unsigned* values, int size);
