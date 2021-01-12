#ifndef LEDSWITCH_UTILS_H
#define LEDSWITCH_UTILS_H

#include <stdint.h>
#include "stm32f4xx.h"                  // Device header
#include "gpio.h"

#define MY_LED_PIN PA_5
#define MY_SW__PIN P_SW

/**
 * @brief Initialize onboard LED.
 * @return void
 */
void ledInit(void);

/**
 * @brief Toggle onboard LED.
 * @param on
 * @return void
 */
void ledSet(int32_t on);

/**
 * @brief Initialize onboard (User) Switch.
 * @return void
 */
void switchInit(void);

/**
 * @brief Sleep processor for $ms milliseconds.
 * @return void
 */
void delayForMs(uint32_t ms);

/**
 * @brief Sleep processor for $us microseconds.
 * @return void
 */
void delayForUs(uint32_t us);

/**
 * @brief Sleep processor for $cycles cycles.
 * @return void
 */
void delayInCyclesAsm(uint32_t cycles);

#endif //LEDSWITCH_LEDSWITCH_H
