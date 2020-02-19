
#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif


#include <cr_section_macros.h>
#include "driver.h"

#define LED_COUNT 300

enum MenuOptions
{
	WAKE_UP = 1,
	SLEEP = 2,
	GRADIENT_CENT_BLUE = 3,
	GRADIENT_CENT_BLUE2 = 4,
	GRADIENT_CENT_GREEN = 5,
	GRADIENT_CENT_ORANGE = 6,
	GRADIENT_CENT_PURPLE = 7,
	GRADIENT_CENT_PURPLE_RED = 8,
	GRADIENT_CENT_RED_YELLOW = 9,
	GRADIENT_CENT_YELLOW = 10,
	GRADIENT_CENT_YELLOW_GREEN = 11,
	GRADIENT_BLUE_DARK = 12,
	GRADIENT_BLUE_GREEN = 13,
	GRADIENT_GREEN_ORANGE = 14,
	GRADIENT_GREEN_RED = 15,
	GRADIENT_ORANGE_RED = 16,
	GRADIENT_PINK_DARKBLUE = 17,
	GRADIENT_PINK_RED = 18,
	GRADIENT_YELLOW_BLUE = 19,
	UP_DOWN_AMBER = 20,
	UP_DOWN_GOLD = 21,
	UP_DOWN_GREEN = 22,
	UP_DOWN_MAGENTA = 23,
	UP_DOWN_OCEAN = 24,
	UP_DOWN_PLUM = 25,
	UP_DOWN_AMBER_GREEN = 26,
	UP_DOWN_MAGENTA_GOLD = 27,
	UP_DOWN_AMBER_OCEAN = 28,
	UP_DOWN_PLUM_OCEAN = 29,
	UP_DOWN_RED_GOLD = 30,
	UP_DOWN_RED_GREEN = 31,
	GRADIENT_GREEN_VIOLET = 32
};

//unsigned LedRing[LED_COUNT] = {0};
volatile int choice;
int options[] =
{
		1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
};

static bool findOption(int c)
{
	bool found = false;
	for (int i = 0; i < 31; ++i)
	{
		if (options[i] == c)
        {
            found = true;
            break;
        }
	}
    return found;
}

void SysTick_Handler(void)
{
	choice = Board_UARTGetChar();
}
int main(void) {

#if defined (__USE_LPCOPEN)
	SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
	Board_Init();
	Board_LED_Set(0, true);
#endif
#endif

    init_data();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 6);
    
    int finalChoice = 0;
	bool flag = true;
	while(1) {
        unsigned LedRing[LED_COUNT] = {0};
        finalChoice = findOption(choice) ? choice : finalChoice;
        switch (finalChoice)
	    {
	    case UP_DOWN_GREEN:
		    flag = false;
		    up_down(GREEN, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_MAGENTA:
		    flag = false;
		    up_down(MAGENTA, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_AMBER:
		    flag = false;
		    up_down(AMBER, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_OCEAN:
		    flag = false;
		    up_down(OCEAN, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_GOLD:
		    flag = false;
		    up_down(GOLD, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_PLUM:
		    flag = false;
		    up_down(PLUM, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_GREEN_VIOLET:
		    flag = false;
		    gradient(GREEN_VIOLET, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_ORANGE_RED:
		    flag = false;
		    gradient(ORANGE_RED, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_GREEN_ORANGE:
		    flag = false;
		    gradient(GREEN_ORANGE, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_BLUE_GREEN:
		    flag = false;
		    gradient(BLUE_GREEN, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_BLUE_DARK:
		    flag = false;
		    gradient(BLUE_DARK, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_PINK_DARKBLUE:
		    flag = false;
		    gradient(PINK_DARKBLUE, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_PINK_RED:
		    flag = false;
		    gradient(PINK_RED, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_GREEN_RED:
		    flag = false;
		    gradient(GREEN_RED, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_YELLOW_BLUE:
		    flag = false;
		    gradient(YELLOW_BLUE, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_BLUE:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_BLUE, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_BLUE2:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_BLUE2, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_GREEN:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_GREEN, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_ORANGE:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_ORANGE, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_PURPLE:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_PURPLE, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_PURPLE_RED:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_PURPLE_RED, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_RED_YELLOW:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_RED_YELLOW, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_YELLOW:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_YELLOW, LedRing, LED_COUNT);
		    break;
	    case GRADIENT_CENT_YELLOW_GREEN:
		    flag = false;
		    gradient_center(GRADIENT_CENTER_YELLOW_GREEN, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_RED_GREEN:
		    flag = false;
		    up_down_two_col(RED, GREEN, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_RED_GOLD:
		    flag = false;
		    up_down_two_col(RED, GOLD, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_PLUM_OCEAN:
		    flag = false;
		    up_down_two_col(PLUM, OCEAN, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_AMBER_OCEAN:
		    flag = false;
		    up_down_two_col(AMBER, OCEAN, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_AMBER_GREEN:
		    flag = false;
		    up_down_two_col(AMBER, GREEN, LedRing, LED_COUNT);
		    break;
	    case UP_DOWN_MAGENTA_GOLD:
		    flag = false;
		    up_down_two_col(MAGENTA, GOLD, LedRing, LED_COUNT);
		    break;
	    case WAKE_UP:
		    wake_up(0x5af604, 0.95, flag, LedRing, LED_COUNT);
		    flag = true;
		    break;
	    case SLEEP:
		    sleeping(0x5af604, 0.95, flag, LedRing, LED_COUNT);
		    flag = true;
		    break;
	    }
	}
	return 0 ;
}

