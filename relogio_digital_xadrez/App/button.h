/*
 * button.h
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#ifndef BUTTON_H_
#define BUTTON_H_

void button_attach_player1_callback(void (*button_player1_callback) (void));
void button_attach_player2_callback(void (*button_player2_callback) (void));
void button_attach_match_reset_callback(void (*button_match_reset_callback) (void));
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* BUTTON_H_ */
