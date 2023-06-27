/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:06:08 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/27 20:27:13 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==============================================================\
|	HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER WALKING	|
\==============================================================*/

/**
 * @brief Retrieve the address of the image of the player walking up.
 *
 * This function loads and returns the address of the image that
 * represents the player
 * walking up. Depending on the value of the `player_walk` variable
 * (0 or 1), different
 * images may be returned. After each call, the `player_walk` variable
 *  is updated
 * accordingly to alternate between the two images.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "walk up" image.
 */
void	*walk_up(t_win *win)
{
	void	*img_player;

	if (win->player_walk == 0)
	{
		img_player = mlx_xpm_file_to_image(win->mlx,
				"images/utils/player/samurai/walk_back_0.xpm",
				&win->image_length, &win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img_player = mlx_xpm_file_to_image(win->mlx,
				"images/utils/player/samurai/walk_back_1.xpm",
				&win->image_length, &win->image_heigth);
		win->player_walk = 0;
	}
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player walking down.
 *
 * This function loads and returns the address of the image that
 *  represents the player
 * walking down. Depending on the value of the `player_walk` variable
 *  (0 or 1), different
 * images may be returned. After each call, the `player_walk` variable
 *  is updated
 * accordingly to alternate between the two images.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "walk down" image.
 */
void	*walk_down(t_win *win)
{
	void	*img_player;

	if (win->player_walk == 0)
	{
		img_player = mlx_xpm_file_to_image(win->mlx,
				"images/utils/player/samurai/walk_front_0.xpm",
				&win->image_length, &win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img_player = mlx_xpm_file_to_image(win->mlx,
				"images/utils/player/samurai/walk_front_1.xpm",
				&win->image_length, &win->image_heigth);
		win->player_walk = 0;
	}
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player walking
 *  to the left.
 *
 * This function loads and returns the address of the image that 
 * represents the player
 * walking to the left. Depending on the value of the `player_walk` 
 * variable (0 or 1), different
 * images may be returned. After each call, the `player_walk` variable
 *  is updated
 * accordingly to alternate between the two images.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "walk left" image.
 */
void	*walk_left(t_win *win)
{
	void	*img_player;

	if (win->player_walk == 0)
	{
		img_player = mlx_xpm_file_to_image(win->mlx,
				"images/utils/player/samurai/walk_left_0.xpm",
				&win->image_length, &win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img_player = mlx_xpm_file_to_image(win->mlx,
				"images/utils/player/samurai/walk_left_1.xpm",
				&win->image_length, &win->image_heigth);
		win->player_walk = 0;
	}
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player walking
 * to the right.
 *
 * This function loads and returns the address of the image that
 *  represents the player
 * walking to the right. Depending on the value of the `player_walk`
 *  variable (0 or 1), different
 * images may be returned. After each call, the `player_walk` variable
 * is updated
 * accordingly to alternate between the two images.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "walk right" image.
 */
void	*walk_right(t_win *win)
{
	void	*img_player;

	if (win->player_walk == 0)
	{
		img_player = mlx_xpm_file_to_image(win->mlx,
				"images/utils/player/samurai/walk_right_0.xpm",
				&win->image_length, &win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img_player = mlx_xpm_file_to_image(win->mlx,
				"images/utils/player/samurai/walk_right_1.xpm",
				&win->image_length, &win->image_heigth);
		win->player_walk = 0;
	}
	return (img_player);
}

/**
 * @brief
 *
 * @param boss
 * @param i
 * @return t_data
 */
t_data	upgrade_player(t_main_struct *boss, int i)
{
	if (i == 0)
	{
		boss->aux.current_image = floor_image(&boss->win);
		if (!boss->aux.current_image)
			error_call("Player Image Not Created", boss);
		boss->img = upgrade_player(boss, 1);
		boss->aux.current_image = player_image(&boss->win);
		if (!boss->aux.current_image)
			error_call("Player Image Not Created", boss);
	}
	boss->img = upgrade_main_image(boss, (boss->win.player_y + 1),
			(boss->win.player_x + 1));
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}
