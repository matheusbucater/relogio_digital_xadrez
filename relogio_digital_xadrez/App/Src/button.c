/*
 * button.c
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#include "button.h"
#include "main.h"
#include "timer.h"

// pointer to the callback
void (*button_callback) (button_id btn_id) = NULL;

// debouncing
// according to datasheet - max 5ms bouncing
void button_debounce() {
	HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
	timer_delay_ms(5);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

// attach the callback function (IT mode)
void button_attach_callback(void (*callback) (button_id btn_id)) {
	button_callback = callback;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	if (button_callback == NULL) return;

	button_debounce();
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
