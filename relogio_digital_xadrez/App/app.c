/*
 * app.c
 *
 *  Created on: Apr 3, 2024
 *      Author: matheusbucater
 */

#include "main.h"
#include "tm1637.h"
#include "player.h"
#include "game.h"
#include "timer.h"
#include "button.h"

player_t player1, player2;
display_t display1, display2;
game_t game;

void tim_callback(timer_id tim_id) {
	switch (tim_id) {
		case TIM_TICK:
			game_update(&game);
			break;
		default:
			break;
	}
}

void btn_callback(button_id btn_id) {
	switch (btn_id) {
		case BTN_PLAYER1:
			game_change_active_player(&game, PLAYER1);
			break;
		case BTN_PLAYER2:
			game_change_active_player(&game, PLAYER2);
			break;
		case BTN_MATCH_RESET:
			game_stop(&game);
			break;
		default:
			break;
	}
}

void setup() {

	// Initialize time structs
	player_time_t player_time;
	player_time.minutes = 30;
	player_time.seconds = 0;

	// Iniitalize displays structs
	display1.clk_port = SCL1_GPIO_Port;
	display1.dio_port = SDA1_GPIO_Port;
	display1.clk_pin = SCL1_Pin;

	display2.clk_port = SCL2_GPIO_Port;
	display2.dio_port = SDA2_GPIO_Port;
	display2.clk_pin = SCL2_Pin;
	display2.dio_pin = SDA2_Pin;

	// Initialize Display
	tm1637Init(display1);
	tm1637Init(display2);

	// Initialize Players
	player_init(&player1, player_time, PLAYER1, display1);
	player_init(&player2, player_time, PLAYER2, display2);

	// Initialize and Start game
	game_init(&game, player1, player2);
	game_start(&game);

	// Attach callbacks
	timer_attach_callback(tim_callback);
	button_attach_callback(btn_callback);
}

void loop() {

}
