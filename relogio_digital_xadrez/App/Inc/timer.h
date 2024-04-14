/*
 * timer.h
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"

// TIM_TICK (TIM2)
// resolution = 1ms
// arr+1 = 1s
// intention of use: interruption
// work as a game tick

// TIM_DELAY (TIM3)
// resolution = 1us
// arr+1 = 65k
// intention of use: polling
// delay (blocking) for some amount of time (microseconds)

typedef enum {
	TIM_TICK = 0,
	TIM_DELAY
} timer_id;

void timer_start(timer_id tim_id);
void timer_stop(timer_id tim_id);
void timer_restart(timer_id tim_id);
void timer_delay_us(uint16_t delay_us);
void timer_delay_ms(uint16_t delay_ms);
void timer_attach_callback(void (*callback) (timer_id tim_id));

#endif /* TIMER_H_ */
