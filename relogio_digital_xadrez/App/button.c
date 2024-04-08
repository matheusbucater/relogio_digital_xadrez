/*
 * button.c
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#include "main.h"

void (*button_player1_callback) (void);
void (*button_player2_callback) (void);
void (*button_match_reset_callback) (void);

void button_attach_player1_callback(void (*button_player1_callback) (void)) {
	button_player1_callback();
}

void button_attach_player2_callback(void (*button_player2_callback) (void)) {
	button_player2_callback();
}

void button_attach_match_reset_callback(void (*button_match_reset_callback) (void)) {
	button_match_reset_callback();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	switch (GPIO_Pin) {
		case BTN_PLAYER1_Pin:
			button_player1_callback();
			break;
		case BTN_PLAYER2_Pin:
			button_player2_callback();
			break;
		case BTN_MATCH_RESET_Pin:
			button_match_reset_callback();
			break;
		default:
			break;
	}
}
