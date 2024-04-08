/*
 * game.c
 *
 *  Created on: Apr 8, 2024
 *      Author: matheusbucater
 */


#include "game.h"

void game_display_timers(game_t game);

void game_init(game_t *game, player_t *player1, player_t *player2) {
	game->state = STOPPED;
	game->player1 = player1;
	game->player2 = player2;
	game->active_player = PLAYER1;


	player_display_curr(*game->player1);
	player_display_curr(*game->player2);
}

void game_start(game_t *game) {
	game->state = ACTIVE;
	// TODO - start timer
	// HAL_TIM_Base_Start_IT(htim);
}

void game_stop(game_t *game) {
	game->state = STOPPED;
	// TODO - stop timer
	// HAL_TIM_Base_Stop_IT(htim);
}

void game_switch_active_player(game_t *game) {
	switch (game->state) {
		case STOPPED:
			// TODO - start timer
			// HAL_TIM_Base_Start_IT(htim);
			game->state = ACTIVE;
			break;

		case ACTIVE:
			// TODO - restart timer
			game->active_player = !game->active_player;
			break;

		default:
			break;
	}
}

void game_update(game_t *game) {
	if (game->state == STOPPED) return;

	player_t *active_player = NULL;

	if (game->active_player == PLAYER1) {
		active_player = game->player1;
	} else {
		active_player = game->player2;
	}

	if (active_player != NULL) {
		if (player_time_ended(*active_player)) {
			// TODO - stop timer
			// HAL_TIM_Base_Stop_IT(htim);
			game->state = STOPPED;
		} else {
			player_time_dec(active_player);
			player_display_curr(*active_player);
		}
	}
}
