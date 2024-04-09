/*
 * timer.c
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#include "timer.h"

extern TIM_HandleTypeDef htim2;

void (*timer_callback) (timer_id id) = NULL;

void timer_start(timer_id id) {
	switch (id) {
		case TIM_TICK:
			HAL_TIM_Base_Start_IT(&htim2);
			break;
		default:
			break;
	}
}

void timer_stop(timer_id id) {
	switch (id) {
		case TIM_TICK:
			HAL_TIM_Base_Stop_IT(&htim2);
			break;
		default:
			break;
	}
}

void timer_restart(timer_id id) {
	switch (id) {
		case TIM_TICK:
			__HAL_TIM_SET_COUNTER(&htim2, 0);
			break;
		default:
			break;
	}
}

void timer_attach_callback(void (*callback) (timer_id id)) {
	timer_callback = callback;
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {

	if (timer_callback == NULL) return;

	if (htim == &htim2) {
		timer_callback(TIM_TICK);
	}
}
