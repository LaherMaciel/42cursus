/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:26:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/14 23:41:32 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER LOOK
*/

void	*look_up(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "Player/samurai/Look_back.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

void	*look_down(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "Player/samurai/Look_front.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

void	*look_left(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "Player/samurai/Look_left.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

void	*look_right(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "Player/samurai/Look_right.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}
