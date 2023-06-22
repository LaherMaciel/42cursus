/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:40:16 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/22 23:50:59 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


/**
 * @brief Determine the appropriate image to use based on the player_look variable.
 *
 * This function decides which image to send based on the value of the player_look variable.
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

/**
 * @brief Retrieve the address of the exit image.
 *
 * This function loads and returns the address of the exit image. The image file used
 * is determined based on the value of the `exit` variable. If `exit` is non-zero, it loads
 * the "exit0.xpm" image file. Otherwise, it also loads the "exit1.xpm" image file.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the exit image.
 */
void	*exit_image(t_win *win)
{
	void	*img_exit;

	if (win->exit != 0)
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"images/42_textures/STAIRS2.xpm", &win->image_length,
				&win->image_heigth);
	else
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"images/42_textures/STAIRS.xpm", &win->image_length,
				&win->image_heigth);
	return (img_exit);
}

/**
 * @brief Retrieve the address of the wall image.
 *
 * This function loads and returns the address of the wall image. The image file used is
 * "tree_wall.xpm". It retrieves the image by calling `mlx_xpm_file_to_image` function,
 * passing the window's `mlx` pointer, the image file path, and the addresses of the
 * `image_length` and `image_height` variables.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the wall image.
 */
void	*wall_image_42(t_win *win)
{
	void	*img_wall;

	img_wall = mlx_xpm_file_to_image(win->mlx,
			"images/42_textures/FLOOR.xpm", &win->image_length,
			&win->image_heigth);
	return (img_wall);
}

/**
 * @brief Retrieve the address of the floor image.
 *
 * This function loads and returns the address of the floor image. The image file used is
 * "main_floor.xpm". It retrieves the image by calling the `mlx_xpm_file_to_image` function,
 * passing the window's `mlx` pointer, the image file path, and the addresses of the
 * `image_length` and `image_height` variables.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the floor image.
 */
void	*floor_image(t_win *win)
{
	void	*img_floor;

	img_floor = mlx_xpm_file_to_image(win->mlx,
			"images/42_textures/floor4.xpm", &win->image_length,
			&win->image_heigth);
	return (img_floor);
}

/**
 * @brief Retrieve the address of the collectibles image.
 *
 * This function loads and returns the address of the collectibles image. The image file used is
 * "Collectibles/soul_flame/tile000.xpm". It retrieves the image by calling the `mlx_xpm_file_to_image`
 * function, passing the window's `mlx` pointer, the image file path, and the addresses of the
 * `image_length` and `image_height` variables.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the collectibles image.
 */
void	*collectibles_image(t_win *win)
{
	return (collectibles_image_animation(win));
}

