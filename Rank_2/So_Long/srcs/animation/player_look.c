/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:26:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/16 18:07:34 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==============================================================\
|	  HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER LOOK	|
\==============================================================*/

/**
 * @brief Retrieve the address of the image of the player looking up.
 *
 * This function loads and returns the address of the image that represents the player
 * looking up. The image is retrieved using the provided window information.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "look up" image.
 */
void	*look_up(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "../../images/utils/player/"\
			"samurai/look_back.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player looking down.
 *
 * This function loads and returns the address of the image that represents the player
 * looking down. The image is retrieved using the provided window information.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "look down" image.
 */
void	*look_down(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "../../images/utils/player/samurai/look_front.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player looking left.
 *
 * This function loads and returns the address of the image that represents the player
 * looking left. The image is retrieved using the provided window information.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "look left" image.
 */
void	*look_left(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "../../images/utils/samurai/look_left.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}

/**
 * @brief Retrieve the address of the image of the player looking right.
 *
 * This function loads and returns the address of the image that represents the player
 * looking right. The image is retrieved using the provided window information.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the player's "look right" image.
 */
void	*look_right(t_win *win)
{
	void	*img_player;

	img_player = mlx_xpm_file_to_image(win->mlx, "../../images/utils/samurai/look_right.xpm", &win->image_length, &win->image_heigth);
	return (img_player);
}
