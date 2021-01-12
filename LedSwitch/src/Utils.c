#include "Utils.h"
#include "stdlib.h"

static uint8_t ledsInitialized = 0;
static uint8_t switchesInitialized = 0;

/**
 * @brief Initialize onboard LED.
 * @return void
 */
 void ledInit(void)
{
	// Check state
	if ( 1 == ledsInitialized )
		return;
	
	// - Set 3 LED pins to outputs
	gpio_set_mode(MY_LED_PIN, Output);
	// - Turn LED OFF
	ledSet(0);
	// - Save State
	ledsInitialized = 1;
}

/**
 * @brief Toggle onboard LED.
 * @param on
 * @return void
 */
void ledSet(int32_t on)
{
	// Boolean operation to decide on state for both active
	// high and low LEDs.
	gpio_set(MY_LED_PIN, (!on) != LED_ON);
}

/**
 * @brief Initialize onboard (User) Switch.
 * @return void
 */
void switchInit(void)
{
	// Check state
	if ( 1 == switchesInitialized )
		return;
	
	// - Set onboard (User) Switch
	gpio_set_mode(MY_SW__PIN, PullUp);
	// - Save State
	switchesInitialized = 1;
}

/**
 * @brief Sleep processor for $ms milliseconds.
 * @return void
 */
void delayForMs(uint32_t ms)
{
	uint32_t max_step = 1000 * (UINT32_MAX / SystemCoreClock);
	uint32_t max_sleep_cycles = max_step * (SystemCoreClock / 1000);
	while (ms > max_step) {
		ms -= max_step;
		delayInCyclesAsm(max_sleep_cycles);
	}
	delayInCyclesAsm(ms * (SystemCoreClock / 1000));
}

/**
 * @brief Sleep processor for $us microseconds.
 * @return void
 */
void delayForUs(uint32_t us)
{
	uint32_t max_step = 1000000 * (UINT32_MAX / SystemCoreClock);
	uint32_t max_sleep_cycles = max_step * (SystemCoreClock / 1000000);
	while (us > max_step) {
		us -= max_step;
		delayInCyclesAsm(max_sleep_cycles);
	}
	delayInCyclesAsm(us * (SystemCoreClock / 1000000));
}

/**
 * @brief Sleep processor for $cycles cycles.
 * @return void
 */
__asm void delayInCyclesAsm(uint32_t cycles)
{
	LSRS r0, #2
	BEQ done
loop
	SUBS r0, #1
#if __CORTEX_M == 3 || __CORTEX_M == 4
	NOP
#endif
	BNE loop
done
	BX lr
}

// *******************************ARM University Program Copyright © ARM Ltd 2016*************************************
