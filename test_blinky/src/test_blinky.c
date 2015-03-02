#include "chip.h"
#include "board.h"

void SysTick_Handler(void)
{
	static int x = 0;
	if (x++ > 1000) {
		Board_LED_Toggle(0);
		x = 0;
	}
}

int main(void) {
    SystemCoreClockUpdate();
    Board_Init();
    // branch revision
    // new change
	SysTick_Config(SystemCoreClock / 1000);

	while (1) {
		__WFI();
	}

    return 0 ;
}
