/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:08:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/07 01:35:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mov_up(t_win *win)
{
	t_data	img;

	if (win->mapa[win->player_y - 1][win->player_x] == 'e')
		my_close(win);
	if (win->mapa[win->player_y - 1][win->player_x] != '1')
	{
		if (win->player_look != 0)
		{
			win->player_look = 0;
			img.img_player = walk_up(win);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				img.img_player, win->player_y, win->player_x);
			return ;
		}
		win->mapa[win->player_y - 1][win->player_x] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		img.img_player = walk_up(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			img.img_player, win->player_y, win->player_x);
	}
}

void	mov_down(t_win *win)
{
	t_data	img;

	if (win->mapa[win->player_y - 1][win->player_x] == 'e')
		my_close(win);
	if (win->mapa[win->player_y + 1][win->player_x] != '1')
	{
		if (win->player_look != 1)
		{
			win->player_look = 1;
			img.img_player = walk_down(win);
			mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_player,
				win->player_y, win->player_x);
			return ;
		}
		win->mapa[win->player_y + 1][win->player_x] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		win->player_y++;
		img.img_player = walk_down(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_player,
			win->player_y, win->player_x);
	}
}

void	mov_left(t_win *win)
{
	t_data	img;

	if (win->mapa[win->player_y][win->player_x - 1] == 'e')
		my_close(win);
	if (win->mapa[win->player_y][win->player_x - 1] != '1')
	{
		if (win->player_look != 2)
		{
			win->player_look = 2;
			img.img_player = walk_left(win);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				img.img_player, win->player_y, win->player_x);
			return ;
		}
		win->mapa[win->player_y][win->player_x - 1] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		img.img_player = walk_left(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			img.img_player, win->player_y, win->player_x);
	}
}

void	mov_right(t_win *win)
{
	t_data	img;

	if (win->mapa[win->player_y][win->player_x + 1] == 'e')
		my_close(win);
	if (win->mapa[win->player_y][win->player_x + 1] != '1')
	{
		if (win->player_look != 3)
		{
			win->player_look = 3;
			win->player_x++;
			img.img_player = walk_right(win);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				img.img_player, win->player_y, win->player_x);
		}
		win->mapa[win->player_y][win->player_x + 1] = 'p';
		win->mapa[win->player_y][win->player_x] = '0';
		win->player_x++;
		img.img_player = walk_right(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			img.img_player, win->player_y, win->player_x);
	}
}
