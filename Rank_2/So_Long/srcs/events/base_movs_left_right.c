/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:08:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 21:57:32 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief upgrade the player making him look to the direction that
 * the user directed.
 *
 * @param boss
 */
void	look(t_main_struct *boss)
{
	boss->aux.current_image = player_image(&boss->win);
	boss->img = upgrade_player(boss, 1);
}

void	pass_through_exit_left(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y][win->player_x] == 'P')
	{
		boss->img = pass_exit(boss);
		win->mapa[win->player_y][win->player_x] = 'e';
		win->mapa[win->player_y][--win->player_x] = 'p';
	}
	else if (win->mapa[win->player_y][win->player_x - 1] == 'e')
	{
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[win->player_y][--win->player_x] = 'P';
	}
	else
	{
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[win->player_y][--win->player_x] = 'p';
	}
}

/**
 * @brief Moves the player character to the left if it is possible.
 *
 * It checks the map to ensure that the next position is not blocked
 * by an obstacle ('1') and also handles special cases, such as
 * encountering the exit ('e') that triggers the termination
 * of the game.
 *
 * @param win The window structure containing game data.
 */
void	mov_left(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y][win->player_x - 1] == 'e' && win->exit == 2)
	{
		boss->win.new_map = boss->win.current_map + 1;
		return ;
	}
	win->player_look = 2;
	boss->img = put_floor(boss, win->player_y, win->player_x);
	if (win->mapa[win->player_y][win->player_x - 1] != '1')
	{
		if (win->mapa[win->player_y][win->player_x - 1] == 'c')
		{
			boss->img = collect(boss);
			win->collected++;
			win->total_collected++;
		}
		pass_through_exit_left(boss, win);
		boss->aux.current_image = walk_left(win);
		boss->img = upgrade_player(boss, 1);
		boss->aux.numb_of_mov++;
		boss->aux.total_mov++;
	}
	else
		look(boss);
}

void	pass_through_exit_right(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y][win->player_x] == 'P')
	{
		boss->img = pass_exit(boss);
		win->mapa[win->player_y][win->player_x] = 'e';
		win->mapa[win->player_y][++win->player_x] = 'p';
	}
	else if (win->mapa[win->player_y][win->player_x + 1] == 'e')
	{
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[win->player_y][++win->player_x] = 'P';
	}
	else
	{
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[win->player_y][++win->player_x] = 'p';
	}
}

/**
 * @brief Moves the player character to the right if it is possible.
 *
 * It checks the map to ensure that the next position is not blocked
 * by an obstacle ('1') and also handles special cases, such as
 * encountering the exit ('e') that triggers the termination
 * of the game.
 *
 * @param win The window structure containing game data.
 */
void	mov_right(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y][win->player_x + 1] == 'e' && win->exit == 2)
	{
		boss->win.new_map = boss->win.current_map + 1;
		return ;
	}
	win->player_look = 3;
	boss->img = put_floor(boss, win->player_y, win->player_x);
	if (win->mapa[win->player_y][win->player_x + 1] != '1')
	{
		if (win->mapa[win->player_y][win->player_x + 1] == 'c')
		{
			boss->img = collect(boss);
			win->collected++;
			win->total_collected++;
		}
		pass_through_exit_right(boss, win);
		boss->aux.current_image = walk_right(win);
		boss->img = upgrade_player(boss, 1);
		boss->aux.numb_of_mov++;
		boss->aux.total_mov++;
	}
	else
		look(boss);
}
