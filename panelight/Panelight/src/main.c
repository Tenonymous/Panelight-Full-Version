#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

/*
#include <cr_section_macros.h>
uncomment this
*/
#include "driver.h"

#define LED_COUNT 300

enum MenuOptions
{
	UP_DOWN_GREEN = '1',
	UP_DOWN_MAGENTA = '2',
	UP_DOWN_AMBER = '3',
	UP_DOWN_OCEAN = '4',
	UP_DOWN_GOLD = '5',
	UP_DOWN_PLUM = '6',
	GRADIENT_GREEN_VIOLET = '7',
	GRADIENT_ORANGE_RED = '8',
	GRADIENT_GREEN_ORANGE = '9',
	GRADIENT_BLUE_GREEN = 'a',
	GRADIENT_BLUE_DARK = 'b',
	GRADIENT_PINK_DARKBLUE = 'c',
	GRADIENT_PINK_RED = 'd',
	GRADIENT_GREEN_RED = 'e',
	GRADIENT_YELLOW_BLUE = 'f',
	GRADIENT_CENT_BLUE = 'g',
	GRADIENT_CENT_BLUE2 = 'h',
	GRADIENT_CENT_GREEN = 'i',
	GRADIENT_CENT_ORANGE = 'j',
	GRADIENT_CENT_PURPLE = 'k',
	GRADIENT_CENT_PURPLE_RED = 'l',
	GRADIENT_CENT_RED_YELLOW = 'm',
	GRADIENT_CENT_YELLOW = 'n',
	GRADIENT_CENT_YELLOW_GREEN = 'o',
	UP_DOWN_RED_GREEN = 'p',
	UP_DOWN_RED_GOLD = 'r',
	UP_DOWN_PLUM_OCEAN = 's',
	UP_DOWN_AMBER_OCEAN = 't',
	UP_DOWN_AMBER_GREEN = 'u',
	UP_DOWN_MAGENTA_GOLD = 'w',
	WAKE_UP = 'z'
};

unsigned LedRing[LED_COUNT] = {0};
volatile char choice;
char options[] =
{
		'1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
		'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's',
		't', 'u', 'w', 'z'
};

static bool findOption(char c)
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
	choice = DEBUGIN();
	static char finalChoice = ' ';
	finalChoice = findOption(choice) ? choice : finalChoice;
	static bool flag = true;

	switch (finalChoice)
	{
	case UP_DOWN_GREEN:
		flag = false;
		up_down(GREEN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_MAGENTA:
		flag = false;
		up_down(MAGENTA, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_AMBER:
		flag = false;
		up_down(AMBER, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_OCEAN:
		flag = false;
		up_down(OCEAN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_GOLD:
		flag = false;
		up_down(GOLD, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_PLUM:
		flag = false;
		up_down(PLUM, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_GREEN_VIOLET:
		flag = false;
		gradient(GREEN_VIOLET, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_ORANGE_RED:
		flag = false;
		gradient(ORANGE_RED, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_GREEN_ORANGE:
		flag = false;
		gradient(GREEN_ORANGE, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_BLUE_GREEN:
		flag = false;
		gradient(BLUE_GREEN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_BLUE_DARK:
		flag = false;
		gradient(BLUE_DARK, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_PINK_DARKBLUE:
		flag = false;
		gradient(PINK_DARKBLUE, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_PINK_RED:
		flag = false;
		gradient(PINK_RED, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_GREEN_RED:
		flag = false;
		gradient(GREEN_RED, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_YELLOW_BLUE:
		flag = false;
		gradient(YELLOW_BLUE, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_BLUE:
		flag = false;
		gradient_center(GRADIENT_CENTER_BLUE, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_BLUE2:
		flag = false;
		gradient_center(GRADIENT_CENTER_BLUE2, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_GREEN:
		flag = false;
		gradient_center(GRADIENT_CENTER_GREEN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_ORANGE:
		flag = false;
		gradient_center(GRADIENT_CENTER_ORANGE, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_PURPLE:
		flag = false;
		gradient_center(GRADIENT_CENTER_PURPLE, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_PURPLE_RED:
		flag = false;
		gradient_center(GRADIENT_CENTER_PURPLE_RED, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_RED_YELLOW:
		flag = false;
		gradient_center(GRADIENT_CENTER_RED_YELLOW, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_YELLOW:
		flag = false;
		gradient_center(GRADIENT_CENTER_YELLOW, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case GRADIENT_CENT_YELLOW_GREEN:
		flag = false;
		gradient_center(GRADIENT_CENTER_YELLOW_GREEN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_RED_GREEN:
		flag = false;
		up_down_two_col(RED, GREEN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_RED_GOLD:
		flag = false;
		up_down_two_col(RED, GOLD, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_PLUM_OCEAN:
		flag = false;
		up_down_two_col(PLUM, OCEAN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_AMBER_OCEAN:
		flag = false;
		up_down_two_col(AMBER, OCEAN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_AMBER_GREEN:
		flag = false;
		up_down_two_col(AMBER, GREEN, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case UP_DOWN_MAGENTA_GOLD:
		flag = false;
		up_down_two_col(MAGENTA, GOLD, LedRing, LED_COUNT);
		clean_up(LedRing, LED_COUNT);
		break;
	case WAKE_UP:
		wake_up(0x5af604, 0.95, flag, LedRing, LED_COUNT);
		flag = true;
		clean_up(LedRing, LED_COUNT);
		break;
	}
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
	while(1) {}
	return 0 ;
}
