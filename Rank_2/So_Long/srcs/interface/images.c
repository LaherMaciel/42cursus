/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:44:27 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/07 22:37:35 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
use this command to resize and convert a image 
in to the size and format u want
 $ convert input.jpeg -resize 64x64 output.xpm
*/

void	*player_image(t_win *win)
{
	void	*img_player;

	if (win->player_look == 0)
		img_player = look_up(win);
	else if (win->player_look == 1)
		img_player = look_down(win);
	else if (win->player_look == 2)
		img_player = look_left(win);
	else
		img_player = look_right(win);
	return (img_player);
}

void	*exit_image(t_win *win)
{
	void	*img_exit;

	if (win->exit != 0)
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"exit1.xpm", &win->image_length, &win->image_heigth);
	else
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"exit1.xpm", &win->image_length, &win->image_heigth);
	return (img_exit);
}

void	*wall_image(t_win *win)
{
	void	*img_wall;

	img_wall = mlx_xpm_file_to_image(win->mlx,
			"tree_wall.xpm", &win->image_length, &win->image_heigth);
	return (img_wall);
}

void	*floor_image(t_win *win)
{
	void	*img_floor;

	img_floor = mlx_xpm_file_to_image(win->mlx,
			"main_floor.xpm", &win->image_length, &win->image_heigth);
	return (img_floor);
}

void	*collectibles_image(t_win *win)
{
	void	*img_collectibles;

	img_collectibles = mlx_xpm_file_to_image(win->mlx,
			"tile000.xpm", &win->image_length, &win->image_heigth);
	return (img_collectibles);
}
