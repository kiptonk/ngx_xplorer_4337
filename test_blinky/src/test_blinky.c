#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

void SysTick_Handler(void)
{
	static int x = 0;
	if (x++ > 1000) {
		Board_LED_Toggle(0);
		x = 0;
	}
}

int main(void) {

#if defined (__USE_LPCOPEN)
#if !defined(NO_BOARD_LIB)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
#endif
#endif

	SysTick_Config(SystemCoreClock / 1000);

	while (1) {
		__WFI();
	}

    return 0 ;
}
