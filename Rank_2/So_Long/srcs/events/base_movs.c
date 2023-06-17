/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:08:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 08:00:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		if (win->player_look != 0)
		{
			win->player_look = 0;
			boss->aux.current_image = floor_image(&boss->win);
			boss->img = upgrade_player(boss, 1);
			boss->aux.current_image = look_up(win);
			boss->img = upgrade_player(boss, 1);
			return ;
		}
		if (win->mapa[win->player_y - 1][win->player_x] == 'c')
			win->collected++;
		boss->aux.current_image = floor_image(&boss->win);
		boss->img = upgrade_player(boss, 1);
		win->mapa[win->player_y - 1][win->player_x] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		win->player_y--;
		boss->aux.current_image = walk_up(win);
		boss->img = upgrade_player(boss, 1);
		ft_printf("\n%s\n\n", win->mapa[win->player_y]);
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
	if (win->mapa[win->player_y - 1][win->player_x] == 'e' && win->exit == 1)
		window_destroy(boss);
	if (win->mapa[win->player_y + 1][win->player_x] != '1'
		&& win->mapa[win->player_y - 1][win->player_x] != 'e')
	{
		if (win->player_look != 1)
		{
			win->player_look = 1;
			boss->aux.current_image = floor_image(&boss->win);
			boss->img = upgrade_player(boss, 1);
			boss->aux.current_image = look_down(win);
			boss->img = upgrade_player(boss, 1);
			return ;
		}
		if (win->mapa[win->player_y + 1][win->player_x] == 'c')
			win->collected++;
		boss->aux.current_image = floor_image(&boss->win);
		boss->img = upgrade_player(boss, 1);
		win->mapa[win->player_y + 1][win->player_x] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		win->player_y++;
		boss->aux.current_image = walk_down(win);
		boss->img = upgrade_player(boss, 1);
		ft_printf("\n%s\n\n", win->mapa[win->player_y]);
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
		if (win->player_look != 2)
		{
			win->player_look = 2;
			boss->aux.current_image = floor_image(&boss->win);
			boss->img = upgrade_player(boss, 1);
			boss->aux.current_image = look_left(win);
			boss->img = upgrade_player(boss, 1);
			return ;
		}
		if (win->mapa[win->player_y][win->player_x - 1] == 'c')
			win->collected++;
		boss->aux.current_image = floor_image(&boss->win);
		boss->img = upgrade_player(boss, 1);
		win->mapa[win->player_y][win->player_x - 1] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		win->player_x--;
		boss->aux.current_image = walk_left(win);
		boss->img = upgrade_player(boss, 1);
		ft_printf("\n%s\n\n", win->mapa[win->player_y]);
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
		if (win->player_look != 3)
		{
			win->player_look = 3;
			boss->aux.current_image = floor_image(&boss->win);
			boss->img = upgrade_player(boss, 1);
			boss->aux.current_image = look_right(win);
			boss->img = upgrade_player(boss, 1);
			return ;
		}
		if (win->mapa[win->player_y][win->player_x + 1] == 'c')
			win->collected++;
		boss->aux.current_image = floor_image(&boss->win);
		boss->img = upgrade_player(boss, 1);
		win->mapa[win->player_y][win->player_x + 1] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		win->player_x++;
		boss->aux.current_image = walk_right(win);
		boss->img = upgrade_player(boss, 1);
		ft_printf("\n%s\n\n", win->mapa[win->player_y]);
	}
}
