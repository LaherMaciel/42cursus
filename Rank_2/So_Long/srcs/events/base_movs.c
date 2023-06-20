/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:08:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/19 23:53:10 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
t_data	fill_y_upper(t_main_struct *boss, t_win *win)
{
	boss->img = put_floor(boss, win->player_y, win->player_x);
	if (win->mapa[win->player_y - 1][win->player_x] == '1')
		put_wall(boss, win->player_y - 1, win->player_x);
	if (win->mapa[win->player_y - 1][win->player_x + 1] == '1')
		put_wall(boss, (win->player_y - 1), win->player_x + 1);
	if (win->mapa[win->player_y - 1][win->player_x - 1] == '1')
		put_wall(boss, (win->player_y - 1), win->player_x - 1);
	return (boss->img);
}

t_data	fill_y_lower(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y - 1][win->player_x + 1] == '1')
		put_wall(boss, (win->player_y - 1), win->player_x + 1);
	if (win->mapa[win->player_y - 1][win->player_x - 1] == '1')
		put_wall(boss, (win->player_y - 1), win->player_x - 1);
	if (win->mapa[win->player_y][win->player_x + 1] == '1')
		put_wall(boss, (win->player_y), win->player_x + 1);
	if (win->mapa[win->player_y][win->player_x - 1] == '1')
		put_wall(boss, (win->player_y), win->player_x - 1);
	if (win->mapa[win->player_y + 1][win->player_x - 1] == '1')
		put_wall(boss, (win->player_y + 1), win->player_x - 1);
	if (win->mapa[win->player_y + 1][win->player_x] == '1')
		put_wall(boss, (win->player_y + 1), win->player_x);
	if (win->mapa[win->player_y + 1][win->player_x + 1] == '1')
		put_wall(boss, (win->player_y + 1), win->player_x + 1);
	if ((win->player_y + 2 <= win->mapa_heigth)
		&& (win->mapa[win->player_y + 2][win->player_x - 1] == '1'))
		put_wall(boss, (win->player_y + 2), win->player_x - 1);
	if ((win->player_y + 2 <= win->mapa_heigth)
		&& (win->mapa[win->player_y + 2][win->player_x] == '1'))
		put_wall(boss, (win->player_y + 2), win->player_x);
	if ((win->player_y + 2 <= win->mapa_heigth)
		&& (win->mapa[win->player_y + 2][win->player_x + 1] == '1'))
		put_wall(boss, (win->player_y + 2), win->player_x + 1);
	return (boss->img);
}

t_data	fill_x_upper(t_main_struct *boss, t_win *win)
{
	boss->img = put_floor(boss, win->player_y, win->player_x);
	if (win->mapa[win->player_y - 1][win->player_x] == '1')
		put_wall(boss, win->player_y - 1, win->player_x);
	if (win->mapa[win->player_y - 1][win->player_x - 1] == '1')
		put_wall(boss, (win->player_y - 1), win->player_x - 1);
	if ((win->player_x - 2 >= 0)
		&& (win->mapa[win->player_y - 1][win->player_x - 2] == '1'))
		put_wall(boss, (win->player_y - 1), win->player_x - 2);
	return (boss->img);
}

t_data	fill_x_lower(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y][win->player_x + 1] == '1')
		put_wall(boss, (win->player_y), win->player_x + 1);
	if (win->mapa[win->player_y][win->player_x - 1] == '1')
		put_wall(boss, (win->player_y), win->player_x - 1);
	if (win->mapa[win->player_y + 1][win->player_x] == '1')
		put_wall(boss, (win->player_y + 1), win->player_x);
	if (win->mapa[win->player_y + 1][win->player_x - 1] == '1')
		put_wall(boss, (win->player_y + 1), win->player_x - 1);
	if ((win->player_x - 2 >= 0)
		&& (win->mapa[win->player_y + 1][win->player_x - 2] == '1'))
		put_wall(boss, (win->player_y + 1), win->player_x - 2);
	if ((win->player_x - 3 >= 0)
		&& (win->mapa[win->player_y + 1][win->player_x - 3] == '1'))
		put_wall(boss, (win->player_y + 1), win->player_x - 3);
	if ((win->player_x - 4 >= 0)
		&& (win->mapa[win->player_y + 1][win->player_x - 4] == '1'))
		put_wall(boss, (win->player_y + 1), win->player_x - 4);
	return (boss->img);
}
*/
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
void	mov_up(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y - 1][win->player_x] == 'e' && win->exit == 1)
		window_destroy(boss);
	if (win->mapa[win->player_y - 1][win->player_x] != '1'
			&& win->mapa[win->player_y - 1][win->player_x] != 'e')
	{
		win->player_look = 0;
		if (win->mapa[win->player_y - 1][win->player_x] == 'c')
		{
			boss->img = collect(boss);
			win->collected++;
		}
		boss->img = put_floor(boss, win->player_y, win->player_x);
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[--win->player_y][win->player_x] = 'p';
		boss->aux.current_image = walk_up(win);
		boss->img = upgrade_player(boss, 1);
	}
	else
	{
		win->player_look = 0;
		boss->img = put_floor(boss, win->player_y, win->player_x);
		boss->aux.current_image = player_image(&boss->win);
		boss->img = upgrade_player(boss, 1);
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
void	mov_down(t_main_struct *boss, t_win *win)
{
	if (win->mapa[win->player_y + 1][win->player_x] == 'e' && win->exit == 1)
		window_destroy(boss);
	if (win->mapa[win->player_y + 1][win->player_x] != '1'
		&& win->mapa[win->player_y + 1][win->player_x] != 'e')
	{
		win->player_look = 1;
		if (win->mapa[win->player_y + 1][win->player_x] == 'c')
		{
			boss->img = collect(boss);
			win->collected++;
		}
		boss->img = put_floor(boss, win->player_y, win->player_x);
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[++win->player_y][win->player_x] = 'p';
		boss->aux.current_image = walk_down(win);
		boss->img = upgrade_player(boss, 1);
	}
	else
	{
		win->player_look = 1;
		boss->img = put_floor(boss, win->player_y, win->player_x);
		boss->aux.current_image = player_image(&boss->win);
		boss->img = upgrade_player(boss, 1);
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
	if (win->mapa[win->player_y][win->player_x - 1] == 'e' && win->exit == 1)
		window_destroy(boss);
	if (win->mapa[win->player_y][win->player_x - 1] != '1'
		&& win->mapa[win->player_y][win->player_x - 1] != 'e')
	{
		win->player_look = 2;
		if (win->mapa[win->player_y][win->player_x - 1] == 'c')
		{
			boss->img = collect(boss);
			win->collected++;
		}
		boss->img = put_floor(boss, win->player_y, win->player_x);
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[win->player_y][--win->player_x] = 'p';
		boss->aux.current_image = walk_left(win);
		boss->img = upgrade_player(boss, 1);
	}
	else
	{
		win->player_look = 2;
		boss->img = put_floor(boss, win->player_y, win->player_x);
		boss->aux.current_image = player_image(&boss->win);
		boss->img = upgrade_player(boss, 1);
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
	if (win->mapa[win->player_y][win->player_x + 1] == 'e' && win->exit == 1)
		window_destroy(boss);
	if (win->mapa[win->player_y][win->player_x + 1] != '1'
		&& win->mapa[win->player_y][win->player_x + 1] != 'e')
	{
		win->player_look = 3;
		if (win->mapa[win->player_y][win->player_x + 1] == 'c')
		{
			boss->img = collect(boss);
			win->collected++;
		}
		boss->img = put_floor(boss, win->player_y, win->player_x);
		win->mapa[win->player_y][win->player_x] = '0';
		win->mapa[win->player_y][++win->player_x] = 'p';
		boss->aux.current_image = walk_right(win);
		boss->img = upgrade_player(boss, 1);
	}
	else
	{
		win->player_look = 3;
		boss->img = put_floor(boss, win->player_y, win->player_x);
		boss->aux.current_image = player_image(&boss->win);
		boss->img = upgrade_player(boss, 1);
	}
}
