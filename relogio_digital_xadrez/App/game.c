/*
 * game.c
 *
 *  Created on: Apr 8, 2024
 *      Author: matheusbucater
 */


#include "game.h"
#include "main.h"
#include "timer.h"

extern TIM_HandleTypeDef htim2;

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
	timer_start(&htim2);
}

void game_stop(game_t *game) {
	game->state = STOPPED;
	timer_stop(&htim2);
}

void game_change_active_player(game_t *game, players_t player) {

	if (game->active_player == player) return;

	game->active_player = player;

	if (game->state == STOPPED) {
		game_start(game);
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

	if (active_player == NULL) return;

	if (player_time_ended(*active_player)) {
		game_stop(game);
	} else {
		player_time_dec(active_player);
		player_display_curr(*active_player);
	}
}
