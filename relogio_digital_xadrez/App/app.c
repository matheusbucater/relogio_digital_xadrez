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

extern TIM_HandleTypeDef htim3;

void tick() {
	game_update(&game);
}

void debounce_player1() {
	timer_start(&htim3);
}

void debounce_player2() {
	timer_start(&htim3);
}
void debounce_match_reset() {
	timer_start(&htim3);
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

	// Attach tim callbacks
	timer_attach_callback2(tick);

	// Attach button callbacks
	button_attach_player1_callback(debounce_player1);
	// button_attach_player2_callback(debounce);
	// button_attach_match_reset_callback(debounce);

	// Initialize Display
	tm1637Init(display1);
	tm1637Init(display2);

	// Initialize Players
	player_init(&player1, player_time, PLAYER1, display1);
	player_init(&player2, player_time, PLAYER2, display2);

	// Initialize and Start game
	game_init(&game, &player1, &player2);
	game_start(&game);

	// TODO - call game_change_active_player on BTN_PLAYER1, BTN_PLAYER2 interruption

	// TODO - call game_stop on BTN_MATCH_RESET interruption
}

void loop() {

}
