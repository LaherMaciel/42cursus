/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:26:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 20:14:38 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER LOOK
*/

void	*look_up(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile012.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

void	*look_down(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile000.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

void	*look_left(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile004.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

void	*look_right(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "/character2/tile008.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}
