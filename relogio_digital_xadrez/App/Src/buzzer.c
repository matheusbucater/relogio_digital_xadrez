/*
 * buzzer.c
 *
 *  Created on: Apr 10, 2024
 *      Author: matheusbucater
 */

#include "buzzer.h"
#include "main.h"

void buzzer_brr_ms(buzzer_id buzz_id, uint32_t delay_ms) {
	switch (buzz_id) {
		case BUZZ_STOP:
			HAL_GPIO_WritePin(BUZZ_GPIO_Port, BUZZ_Pin, SET);
			HAL_Delay(delay_ms);
			HAL_GPIO_WritePin(BUZZ_GPIO_Port, BUZZ_Pin, RESET);
			break;
		default:
			break;
	}
}
