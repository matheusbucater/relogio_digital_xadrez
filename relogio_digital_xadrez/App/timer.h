/*
 * timer.h
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"

typedef enum {
	TIM_TICK = 0,
	TIM_DEBOUNCE
} timer_id;

void timer_start(timer_id id);
void timer_stop(timer_id id);
void timer_restart(timer_id it);
void timer_attach_callback(void (*callback) (timer_id id));

#endif /* TIMER_H_ */
