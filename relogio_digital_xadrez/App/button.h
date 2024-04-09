/*
 * button.h
 *
 *  Created on: Apr 8, 2024
 *      Author: coppolimeros
 */

#ifndef BUTTON_H_
#define BUTTON_H_

typedef enum {
	BTN_MATCH_RESET = 0,
	BTN_PLAYER1,
	BTN_PLAYER2
} button_id;

void button_attach_callback(void (*callback) (button_id btn_id));

#endif /* BUTTON_H_ */
