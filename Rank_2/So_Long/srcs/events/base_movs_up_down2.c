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

void	pass_through_exit_up2(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y][win->player_x] == 'P')
	{
		boss->img = pass_exit2(boss);
		win->mapa[win->player_y][win->player_x] = 'e';
		win->mapa[--win->player_y][win->player_x] = 'p';
	}
	else if (win->mapa[win->player_y - 1][win->player_x] == 'e')
	{
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[--win->player_y][win->player_x] = 'P';
	}
	else
	{
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[--win->player_y][win->player_x] = 'p';
	}
}

/**
 * @brief Moves the player character upwards if it is possible.
 *
 * It checks the map to ensure that the next position is not blocked
 * by an obstacle ('1') and also handles special cases, such as
 * encountering the exit ('e') that triggers the termination
 * of the game.
 *
 * @param win The window structure containing game data.
 */
void	mov_up2(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y - 1][win->player_x] == 'e' && win->exit == 2)
	{
		boss->win.new_map = boss->win.current_map + 1;
		return ;
	}
	win->player_look = 0;
	if (win->mapa[win->player_y - 1][win->player_x] != '1')
	{
		boss->img = put_floor2(boss, win->player_y, win->player_x);
		if (win->mapa[win->player_y - 1][win->player_x] == 'c')
		{
			boss->img = collect2(boss);
			win->collected++;
			win->total_collected++;
		}
		pass_through_exit_up2(boss, win);
		boss->aux.current_image = walk_up(win);
		boss->img = upgrade_player2(boss, 1);
		boss->aux.numb_of_mov++;
		boss->aux.total_mov++;
	}
	else
		look2(boss);
}

void	pass_through_exit_down2(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y][win->player_x] == 'P')
	{
		boss->img = pass_exit2(boss);
		win->mapa[win->player_y][win->player_x] = 'e';
		win->mapa[++win->player_y][win->player_x] = 'p';
	}
	else if (win->mapa[win->player_y + 1][win->player_x] == 'e')
	{
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[++win->player_y][win->player_x] = 'P';
	}
	else
	{
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[++win->player_y][win->player_x] = 'p';
	}
}

/**
 * @brief Moves the player character downwards if it is possible.
 *
 * It checks the map to ensure that the next position is not blocked
 * by an obstacle ('1') and also handles special cases, such as
 * encountering the exit ('e') that triggers the termination
 * of the game.
 *
 * @param win The window structure containing game data.
 */
void	mov_down2(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y + 1][win->player_x] == 'e' && win->exit == 2)
	{
		boss->win.new_map = boss->win.current_map + 1;
		return ;
	}
	win->player_look = 1;
	if (win->mapa[win->player_y + 1][win->player_x] != '1')
	{
		boss->img = put_floor2(boss, win->player_y, win->player_x);
		if (win->mapa[win->player_y + 1][win->player_x] == 'c')
		{
			boss->img = collect2(boss);
			win->collected++;
			win->total_collected++;
		}
		pass_through_exit_down2(boss, win);
		boss->aux.current_image = walk_down(win);
		boss->img = upgrade_player2(boss, 1);
		boss->aux.numb_of_mov++;
		boss->aux.total_mov++;
	}
	else
		look2(boss);
}
