/*
 * button.c
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#include "main.h"
#include "button.h"

void (*button_callback) (button_id btn_id) = NULL;

void button_attach_callback(void (*callback) (button_id btn_id)) {
	button_callback = callback;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	if (button_callback == NULL) return;

	switch (GPIO_Pin) {
		case BTN_MATCH_RESET_Pin:
			button_callback(BTN_MATCH_RESET);
			break;
		case BTN_PLAYER1_Pin:
			button_callback(BTN_PLAYER1);
			break;
		case BTN_PLAYER2_Pin:
			button_callback(BTN_PLAYER2);
			break;
		default:
			break;
	}
}
