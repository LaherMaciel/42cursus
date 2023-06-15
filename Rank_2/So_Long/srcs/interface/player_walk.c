/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:06:08 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/14 23:31:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER ALKING
*/

void	*walk_up(t_win *win)
{
	void	*img_player;

	if (win->player_walk == 0)
	{
		img_player = mlx_xpm_file_to_image(win->mlx, "Player/samurai/tile013.xpm", &win->image_length, &win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile015.xpm", &win->image_length, &win->image_heigth);
		win->player_walk = 0;
	}
	return (img_player);
}

void	*walk_down(t_win *win)
{
	void	*img_player;

	if (win->player_walk == 0)
	{
		img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile001.xpm", &win->image_length, &win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile003.xpm", &win->image_length, &win->image_heigth);
		win->player_walk = 0;
	}
	return (img_player);
}

void	*walk_left(t_win *win)
{
	void	*img_player;

	if (win->player_walk == 0)
	{
		img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile005.xpm", &win->image_length, &win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile007.xpm", &win->image_length, &win->image_heigth);
		win->player_walk = 0;
	}
	return (img_player);
}

void	*walk_right(t_win *win)
{
	void	*img_player;

	if (win->player_walk == 0)
	{
		img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile009.xpm", &win->image_length, &win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile011.xpm", &win->image_length, &win->image_heigth);
		win->player_walk = 0;
	}
	return (img_player);
}
