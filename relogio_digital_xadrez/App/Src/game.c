/*
 * game.c
 *
 *  Created on: Apr 8, 2024
 *      Author: matheusbucater
 */

#include "game.h"
#include "main.h"
#include "timer.h"
#include "buzzer.h"

extern TIM_HandleTypeDef htim2;

void game_display_timers(game_t game);

// init game struct
// and display players time
void game_init(game_t *game, player_t player1, player_t player2) {
	game->state = STOPPED;
	game->player1 = player1;
	game->player2 = player2;
	game->active_player = PLAYER1;

	player_display_curr(game->player1);
	player_display_curr(game->player2);
}

// start the game (timer)
void game_start(game_t *game) {
	game->state = ACTIVE;
	player_time_restart(&game->player1);
	player_time_restart(&game->player2);
	timer_start(TIM_TICK);
}

// stop the game (timer)
void game_stop(game_t *game) {
	game->state = STOPPED;
	timer_stop(TIM_TICK);
	buzzer_brr_ms(BUZZ_STOP, 1500);
}

// change the current player
void game_change_active_player(game_t *game, player_id next_player) {

	if (game->active_player == next_player) return;

	game->active_player = next_player;
	timer_restart(TIM_TICK);

	if (game->state == STOPPED) {
		game_start(game);
	}
}

// decrement current time from the active_player
void game_update(game_t *game) {
	if (game->state == STOPPED) return;

	player_t *active_player = NULL;

	if (game->active_player == PLAYER1) {
		active_player = &game->player1;
	} else {
		active_player = &game->player2;
	}

	if (active_player == NULL) return;

	if (player_time_ended(*active_player)) {
		game_stop(game);
	} else {
		player_time_dec(active_player);
		player_display_curr(*active_player);
	}
}
