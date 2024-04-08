/*
 * timer.h
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#ifndef TIMER_H_
#define TIMER_H_

void timer_start(TIM_HandleTypeDef* htim);
void timer_stop(TIM_HandleTypeDef* htim);
void timer_restart(TIM_HandleTypeDef* htim);
void timer_attach_callback1(void (*timer_callback1) (void));
void timer_attach_callback2(void (*timer_callback2) (void));
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim);

#endif /* TIMER_H_ */
