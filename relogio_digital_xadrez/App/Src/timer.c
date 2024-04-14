/*
 * timer.c
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#include "timer.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

// pointer to the callback
void (*timer_callback) (timer_id id) = NULL;

// start the timer based on the timer_id
void timer_start(timer_id tim_id) {
	switch (tim_id) {
		case TIM_TICK:
			HAL_TIM_Base_Start_IT(&htim2);
			break;
		case TIM_DELAY:
			HAL_TIM_Base_Start(&htim3);
			break;
		default:
			break;
	}
}

// start the timer based on the timer_id
void timer_stop(timer_id tim_id) {
	switch (tim_id) {
		case TIM_TICK:
			HAL_TIM_Base_Stop_IT(&htim2);
			break;
		case TIM_DELAY:
			HAL_TIM_Base_Stop(&htim3);
			break;
		default:
			break;
	}
}

// set the timer counter to 0 based on the timer_id
void timer_restart(timer_id tim_id) {
	switch (tim_id) {
		case TIM_TICK:
			__HAL_TIM_SET_COUNTER(&htim2, 0);
			break;
		case TIM_DELAY:
			__HAL_TIM_SET_COUNTER(&htim3, 0);
			break;
		default:
			break;
	}
}

// block while TIM_DELAY less than delays_us
void timer_delay_us(uint16_t delay_us) {
	timer_restart(TIM_DELAY);
	timer_start(TIM_DELAY);
	while(__HAL_TIM_GET_COUNTER(&htim3) < delay_us);
	timer_stop(TIM_DELAY);
}

// block with HAL_Delay for delay_ms
void timer_delay_ms(uint16_t delay_ms) {
	HAL_Delay(delay_ms);
}

// attach the callback function (IT mode)
void timer_attach_callback(void (*callback) (timer_id tim_id)) {
	timer_callback = callback;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {

	if (timer_callback == NULL) return;

	if (htim == &htim2) {
		timer_callback(TIM_TICK);
	}
}
