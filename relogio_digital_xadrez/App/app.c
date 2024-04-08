/*
 * app.c
 *
 *  Created on: Apr 3, 2024
 *      Author: matheusbucater
 */

#include "tm1637.h"
#include "player.h"
#include "game.h"
#include "main.h"

player_t player1, player2;
display_t display1, display2;
game_t game;

void setup() {

	player_time_t player_time;
	player_time.minutes = 30;
	player_time.seconds = 0;

	display1.clk_port = SCL1_GPIO_Port;
	display1.dio_port = SDA1_GPIO_Port;
	display1.clk_pin = SCL1_Pin;

	display2.clk_port = SCL2_GPIO_Port;
	display2.dio_port = SDA2_GPIO_Port;
	display2.clk_pin = SCL2_Pin;
	display2.dio_pin = SDA2_Pin;

	tm1637Init(display1);
	tm1637Init(display2);

	player_init(&player1, player_time, PLAYER1, display1);
	player_init(&player2, player_time, PLAYER2, display2);

	game_init(&game, &player1, &player2);
	game_start(&game);

	// TODO - call game_update on timer interruption
	/*
    void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    	if(htim->Instance == TIM1) {
    		game_update(&game);
    	}
    }
    */
}

void loop() {

}
