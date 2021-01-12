#ifndef LEDSWITCH_LEDSWITCH_H
#define LEDSWITCH_LEDSWITCH_H

#include <stdint.h>

/**
 * @brief Initialize onboard LED.
 * @return void
 */
void ledSwitchInit(void);

/**
 * @brief Blink to indicate count down number. Between consecutive numbers there will be 1000ms delay. 
 * Each number will be indicated with fast blinks with 50ms delay.
 * @param from
 * @return void
 */
void countDownBlink(uint8_t from);

/**
 * @brief Callback when switch is pressed.
 * @param pinIndex
 * @return void
 */
static void onSwitchPress(int pinIndex);

/**
 * @brief SysTick interrupt Handler (every 1ms).
 * @return void
 */
static void onTimerTick(void);

/**
 * @brief Blinks LED for countdown from 3 to 1, opens LED and starts counting user response time.
 * Returns time in us. (FIRST EXPERIMENT)
 * @return resTimeUs
 */
uint32_t captureResponseTimeFromTurnedOn(void);

/**
 * @brief Blinks LED for countdown from 3 to 1, opens LED for 3000ms, turns it off. 
 * After LED shuts, starts counting user response time. Returns time in us. (SECOND EXPERIMENT)
 * @return resTimeUs
 */
uint32_t captureResponseTimeFromTurnedOff(void);

#endif //LEDSWITCH_LEDSWITCH_H
