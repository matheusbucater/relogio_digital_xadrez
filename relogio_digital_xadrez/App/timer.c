/*
 * timer.c
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#include "main.h"

void (*timer_callback1) (void);
void (*timer_callback2) (void);
// void (*timer_callback3 (void);

void timer_start(TIM_HandleTypeDef* htim) {
	HAL_TIM_Base_Start_IT(htim);
}

void timer_stop(TIM_HandleTypeDef* htim) {
	HAL_TIM_Base_Stop_IT(htim);
}

void timer_restart(TIM_HandleTypeDef* htim) {
	__HAL_TIM_SET_COUNTER(htim, 0);
}

void timer_attach_callback1(void (*timer_callback1) (void)) {
	timer_callback1();
}

void timer_attach_callback2(void (*timer_callback2) (void)) {
	timer_callback2();
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {

	if (htim->Instance == TIM1) {
		timer_callback1();
	}

	if (htim->Instance == TIM2) {
		timer_callback2();
	}
}
