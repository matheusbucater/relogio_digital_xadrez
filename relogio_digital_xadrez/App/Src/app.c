/*
 * app.c
 *
 *  Created on: Apr 3, 2024
 *      Author: matheusbucater
 */

#include "app.h"
#include "display.h"
#include "player.h"
#include "game.h"
#include "timer.h"
#include "button.h"

player_t player1, player2;
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

	// Initialize players time with 30 minutes
	player_time_t player_time;
	player_time.minutes = 30;
	player_time.seconds = 0;

	// Initialize Displays
	display_init(DISPLAY1);
	display_init(DISPLAY2);

	// Initialize Players
	player_init(&player1, player_time, PLAYER1, DISPLAY1);
	player_init(&player2, player_time, PLAYER2, DISPLAY2);

	// Initialize and Start game
	game_init(&game, player1, player2);
	game_start(&game);

	// Attach callbacks
	timer_attach_callback(tim_callback);
	button_attach_callback(btn_callback);
}

void loop() {

}
