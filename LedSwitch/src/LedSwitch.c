#include "LedSwitch.h"
#include "Utils.h"
#include "timer.h"
#include "stdlib.h"

/**
 * @brief Initialize onboard LED.
 * @return void
 */
void ledSwitchInit(void)
{	
	// - Initialize onboard LEDs
	ledInit();
	// - Initialize onboard (User) Switch
	switchInit();
	//	- Initialize timer (tick of 1ms)
	timer_set_callback(&onTimerTick);
	timer_init(1000);										// 1000us = 1ms
	timer_enable();
	//  - Capture button press
	gpio_set_callback(MY_SW__PIN, &onSwitchPress);
	gpio_set_trigger(MY_SW__PIN, Rising);
}

/**
 * @brief Blink to indicate count down number. Between consecutive numbers there will be 1000ms delay. 
 * Each number will be indicated with fast blinks with 50ms delay.
 * @param from
 * @return void
 */
void countDownBlink(uint8_t from)
{
	uint8_t outer, inner;
	for(outer = from; outer > 0; outer--)
	{
		for(inner = outer; inner > 0; inner--)
		{
			// Led ON
			ledSet(1);
			
			// Delay
			delayForMs(100);
			
			// Led OFF
			ledSet(0);
			
			// Delay
			delayForMs(100);
		}
		
		// Big Delay of 1000ms
		delayForMs(1000);
	}
}


volatile uint32_t switchMsTicks;
/**
 * @brief SysTick interrupt Handler (every 1ms).
 * @return void
 */
void onTimerTick(void)
{
  switchMsTicks++;
}

static uint8_t switchPressed = 0;
/**
 * @brief Callback when switch is pressed.
 * @param pinIndex
 * @return void
 */
static void onSwitchPress(int pinIndex)
{
	//	- update switchPressed
	switchPressed = 1;
	//	- turn LED off
	ledSet(0);
	//	- delay of 1sec before next experiment
	delayForMs(1000);
}

/**
 * @brief Blinks LED for countdown from 3 to 1, opens LED and starts counting user response time.
 * Returns time in us. (FIRST EXPERIMENT)
 * @return resTimeUs
 */
uint32_t captureResponseTimeFromTurnedOn(void)
{	
	// Start Count-Down
	countDownBlink(3);
	
	// Clear previous state	
	switchPressed = 0;
	switchMsTicks = 0;
	
	// Led ON
	ledSet(1);
	
	// Wait
	while( !switchPressed );
	
	// Return timer value
	return switchMsTicks;
}

/**
 * @brief Blinks LED for countdown from 3 to 1, opens LED for 3000ms, turns it off. 
 * After LED shuts, starts counting user response time. Returns time in us. (SECOND EXPERIMENT)
 * @return resTimeUs
 */
uint32_t captureResponseTimeFromTurnedOff(void)
{
	// Start Count-Down
	countDownBlink(3);
	
	// Led ON
	ledSet(1);
	
	// Big Delay of 3000ms
	delayForMs(3000);
	
	// Clear previous state	
	switchPressed = 0;
	switchMsTicks = 0;
	
	// Led OFF
	ledSet(0);
	
	// Wait
	while( !switchPressed );
	
	// Return timer value
	return switchMsTicks;
}
