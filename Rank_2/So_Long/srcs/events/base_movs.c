/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:08:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 01:59:21 by lwencesl         ###   ########.fr       */
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
	t_aux_vales aux;

	if (win->mapa[win->player_y - 1][win->player_x] == 'e')
		window_destroy(boss);
	if (win->mapa[win->player_y - 1][win->player_x] != '1')
	{
		if (win->player_look != 0)
		{
			win->player_look = 0;
			aux.img_player = look_up(win);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				aux.img_player, win->player_y, win->player_x);
			return ;
		}
		win->mapa[win->player_y - 1][win->player_x] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		aux.img_player = walk_up(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			aux.img_player, win->player_y, win->player_x);
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
	t_aux_vales aux;

	if (win->mapa[win->player_y - 1][win->player_x] == 'e')
		window_destroy(boss);
	if (win->mapa[win->player_y + 1][win->player_x] != '1')
	{
		if (win->player_look != 1)
		{
			win->player_look = 1;
			aux.img_player = look_down(win);
			mlx_put_image_to_window(win->mlx, win->mlx_win, aux.img_player,
				win->player_y, win->player_x);
			return ;
		}
		win->mapa[win->player_y + 1][win->player_x] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		win->player_y++;
		aux.img_player = walk_down(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win, aux.img_player,
			win->player_y, win->player_x);
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
	t_aux_vales aux;

	if (win->mapa[win->player_y][win->player_x - 1] == 'e')
		window_destroy(boss);
	if (win->mapa[win->player_y][win->player_x - 1] != '1')
	{
		if (win->player_look != 2)
		{
			win->player_look = 2;
			aux.img_player = look_left(win);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				aux.img_player, win->player_y, win->player_x);
			return ;
		}
		win->mapa[win->player_y][win->player_x - 1] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		aux.img_player = walk_left(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			aux.img_player, win->player_y, win->player_x);
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
	t_aux_vales aux;

	if (win->mapa[win->player_y][win->player_x + 1] == 'e')
		window_destroy(boss);
	if (win->mapa[win->player_y][win->player_x + 1] != '1')
	{
		if (win->player_look != 3)
		{
			win->player_look = 3;
			aux.img_player = look_right(win);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				aux.img_player, win->player_y, win->player_x);
			return ;
		}
		win->mapa[win->player_y][win->player_x + 1] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		win->player_x++;
		aux.img_player = walk_right(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			aux.img_player, win->player_y, win->player_x);
	}
}
