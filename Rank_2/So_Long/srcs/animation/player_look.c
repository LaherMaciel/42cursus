/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:26:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:10:57 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==============================================================\
|	  HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER LOOK	|
\==============================================================*/

/**
 * @brief Retrieve the address of the image of the player looking up.
 *
 * This function loads and returns the address of the image that represents the
 *  player looking up. The image is retrieved using the provided window
 *  information.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "look up" image.
 */
void	*look_up(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx,
			"images/utils/player/"\
			"samurai/look_back.xpm",
			&win->image_length, &win->image_heigth);
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player looking down.
 *
 * This function loads and returns the address of the image that represents the
 *  player looking down. The image is retrieved using the provided window
 *  information.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "look down" image.
 */
void	*look_down(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx,
			"images/utils/player/samurai/look_front.xpm",
			&win->image_length, &win->image_heigth);
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player looking left.
 *
 * This function loads and returns the address of the image that represents the
 *  player looking left. The image is retrieved using the provided window
 *  information.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "look left" image.
 */
void	*look_left(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx,
			"images/utils/player/samurai/look_left.xpm",
			&win->image_length, &win->image_heigth);
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player looking right.
 *
 * This function loads and returns the address of the image that represents the
 * player looking right. The image is retrieved using the provided window
 * information.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "look right" image.
 */
void	*look_right(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx,
			"images/utils/player/samurai/look_right.xpm",
			&win->image_length, &win->image_heigth);
	return (img_player);
}

/**
 * @brief Determine the appropriate image to use based on the player_look
 *  variable.
 *
 * This function decides which image to send based on the value of the
 *  player_look variable.
 * The values of player_look correspond to the player's direction:
 *   - 0: down
 *   - 1: up
 *   - 2: left
 *   - 3: right
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the chosen image.
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
