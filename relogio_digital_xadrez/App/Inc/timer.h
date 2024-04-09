/*
 * timer.h
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#ifndef TIMER_H_
#define TIMER_H_

typedef enum {
	TIM_TICK = 0,
	TIM_DEBOUNCE
} timer_id;

void timer_start(timer_id tim_id);
void timer_stop(timer_id tim_id);
void timer_restart(timer_id tim_id);
void timer_attach_callback(void (*callback) (timer_id tim_id));

#endif /* TIMER_H_ */
