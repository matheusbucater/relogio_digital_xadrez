/*
 * player.c
 *
 *  Created on: Apr 8, 2024
 *      Author: matheusbucater
 */

#include "player.h"
#include "tm1637.h"

void player_init(player_t *player, player_time_t start_time, player_id plr_id, display_t display) {
	player->start_time = start_time;
	player->curr_time = start_time;
	player->player = plr_id;
	player->display = display;
}

void player_time_restart(player_t *player) {
	player->curr_time = player->start_time;
}

int player_time_ended(player_t player) {
	uint32_t min = player.curr_time.minutes;
	uint32_t sec = player.curr_time.seconds;

	if (min == 0 && sec == 0) {
		return 1;
	} else {
		return 0;
	}
}

void player_time_dec(player_t *player) {
	if (player->curr_time.seconds == 0) {
		player->curr_time.minutes--;
		player->curr_time.seconds = 59;
	} else {
		player->curr_time.seconds--;
	}
}

void player_display_curr(player_t player) {
	tm1637DisplayDecimal(player.display, player.curr_time.minutes * 100 + player.curr_time.seconds, 1);
}
