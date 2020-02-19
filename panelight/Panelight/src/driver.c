#include "driver.h"
#include <stdbool.h>
#include <stdlib.h>

#define ARRAY_LEVELS_SIZE 65

MODE mode = UP;

void init_data()
{
    mode = UP;
    LED_data = 0;
    Chip_IOCON_PinMuxSet(LPC_IOCON, 0, 9, IOCON_FUNC1); /* PIO0_9 connected to MOSI0 */
    Chip_SSP_Init(LPC_SSP0);
    Chip_SSP_SetMaster(LPC_SSP0, 1);
    Chip_SSP_SetClockRate(LPC_SSP0, 0, 6);
    Chip_SSP_SetFormat(LPC_SSP0, SSP_BITS_15, SSP_FRAMEFORMAT_SPI, SSP_CLOCK_CPHA0_CPOL0);
    Chip_SSP_Enable(LPC_SSP0);
}

void deinit()
{
    Chip_SSP_Disable(LPC_SSP0);
}

void clean_up(unsigned* values, int size)
{
    for (int i = 0; i < size; ++i) {
        values[i] = 0;
    }
}

bool all_of(unsigned* array, int size, int val)
{
    bool all_is = true;
    for (int i = 0; i < size; ++i) {
        if (array[i] != val) {
            all_is = false;
        }
    }
    return all_is;
}

void send(unsigned* values, int size)
{
    for (int val = 0; val < size; ++val) {
        for (int i = 23; i >= 0; --i) {
            LED_data = GET_BIT(values[val], i) ? CODE_1 : CODE_0;
            while (!Chip_SSP_GetStatus(LPC_SSP0, SSP_STAT_TNF)) {
                ; /* TX FIFO not FULL */
            }
            Chip_SSP_SendFrame(LPC_SSP0, LED_data);
        }
    }
}

unsigned* create_colors_levels(const unsigned color, double bright)
{
    unsigned col = color;
    bool flag = true;
    uint32_t cnt = 1;

    /*Can't find optimal SIZE for Array.
	 * Probably it is depending on bright variable.
	 * For bright == 95, 65 is best size for our effect.
	 *  */

    unsigned* to_zeros = (unsigned*)malloc(ARRAY_LEVELS_SIZE * sizeof(unsigned));
    if (to_zeros != NULL) {
        to_zeros[0] = col;
        for (int i = 1; i < ARRAY_LEVELS_SIZE; ++i) {
            to_zeros[i] = 0;
        }
        while (flag) {
            unsigned* col_array = create_rgb_array(col);
            if (col_array != NULL) {
                for (int val = 0; val < 3; ++val) {
                    col_array[val] *= bright;
                }

                if (all_of(col_array, 3, 0.0)) {
                    col = 0;
                    flag = false;
                }
                else {
                    col = hexa_merging(col_array[0], col_array[1], col_array[2]);
                }

                to_zeros[cnt] = col;
                cnt++;
                free(col_array);
            }
        }
    }
    return to_zeros;
}

void up_down(const unsigned color, unsigned* values, int size)
{
    bool first = true;
    bool third = false;
    uint32_t cnt = 0;
    for (int val = 0; val < size; ++val) {
        if (first || third) {
            values[val] = color;
        }
        ++cnt;
        if (cnt == 10) {
            cnt = 0;
            if (first) {
                first = false;
            }
            else if (third) {
                third = false;
                first = true;
            }
            else {
                third = true;
            }
        }
    }
    send(values, size);
}

void up_down_two_col(const unsigned color1, const unsigned color2, unsigned* values, int size)
{
    bool first = true;
    bool zeros = false;
    bool second = false;
    int counter = 0;
    for (int val = 0; val < size; ++val) {
        if (first) {
            values[val] = color1;
        }
        if (zeros) {
            values[val] = 0;
        }
        if (second) {
            values[val] = color2;
        }

        counter++;
        if (counter == 10) {
            counter = 0;
            if (first) {
                zeros = true;
                first = false;
            }
            else if (zeros) {
                second = true;
                zeros = false;
            }
            else {
                first = true;
                second = false;
            }
        }
    }
    send(values, size);
}

void gradient_center(const unsigned* colors, unsigned* values, int size)
{
    int index = 0;
    /*for first color*/
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[2];
    }
    index += 60;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[2];
    }
    index += 120;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[2];
    }
    index += 90;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[2];
    }

    /*for second color*/
    index = 120;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[1];
    }

    /*for third color*/
    index -= 30;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[0];
    }
    index += 60;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[0];
    }
    index = 30;
    /*for fourth color*/
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[0];
    }
    index += 180;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[0];
    }
    /*for five color*/
    index += 30;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[1];
    }
    send(values, size);
}
void gradient(const unsigned* colors, unsigned* values, int size)
{
    int index = 0;
    /*for center color*/
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[2];
    }
    index += 60;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[2];
    }
    index += 120;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[2];
    }
    index += 90;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[2];
    }

    /*for first color*/
    index = 120;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[0];
    }

    /*for second color*/
    index -= 30;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[1];
    }
    index += 60;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[1];
    }
    index = 30;
    /*for fourth color*/
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[3];
    }
    index = index + 180;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[3];
    }
    /*for five color*/
    index += 30;
    for (int i = index; i < index + 30; ++i) {
        values[i] = colors[4];
    }
    send(values, size);
}

void wake_up(const unsigned color, double bright, bool flag, unsigned* values, int size)
{
    unsigned* vec_colors = create_colors_levels(color, bright);
    if (vec_colors != NULL) {
        static uint32_t index = 60;
        if (!flag) {
            index = 60;
        }
        for (uint32_t i = 10; i < 281; i += 30) {
            for (int j = i; j < i + 10; ++j) {
                values[j] = vec_colors[index];
            }
        }

        send(values, size);
        index = index > 0 ? index - 1 : 60;
        if (index == 60) {
            for (volatile int i = 0; i < 4000000; ++i) {
                ;
            }
        }
        for (volatile int i = 0; i < 1500000; ++i) {
            ;
        }
        free(vec_colors);
    }
}

void sleeping(const unsigned color, double bright, bool flag, unsigned* values, int size)
{
    static uint32_t cnt = 10;
    unsigned* vec_colors = create_colors_levels(color, bright);
    if (vec_colors != NULL) {
        static uint32_t index = 0;
        if (!flag) {
            index = 0;
        }
        for (uint32_t i = 10; i < 281; i += 30) {
            for (int j = i; j < i + 10; ++j) {
                values[j] = vec_colors[index];
            }
        }

        ++cnt;
        send(values, size);

        index = index < 60 ? index + 1 : 0;
        if (index == 0) {
            for (volatile int i = 0; i < 4000000; ++i) {
                ;
            }
        }

        for (volatile int i = 0; i < 1500000; ++i) {
            ;
        }
        free(vec_colors);
    }
}
