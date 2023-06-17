/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:44:27 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/16 23:35:26 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
To resize and convert an image to the desired size and format,
you can use the convert command from the ImageMagick package.
Here's an example command:
 $ convert input.jpeg -resize 64x64 output.xpm

 To confirm the path of the XPM image and view it,
 you can use the display command, also part of the~
 ImageMagick package. Here's an example command:
 $ display /path/to/image.xpm

to see the size of the image
identify -format "%wx%h" example.jpg
*/

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
		img_player = look_down(win);
	else if (win->player_look == 1)
		img_player = look_up(win);
	else if (win->player_look == 2)
		img_player = look_left(win);
	else if (win->player_look == 3)
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
				"../../images/utils/exit0.xpm", &win->image_length, &win->image_heigth);
	else
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"../../images/utils/exit1.xpm", &win->image_length, &win->image_heigth);
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
void	*wall_image(t_win *win)
{
	void	*img_wall;

	img_wall = mlx_xpm_file_to_image(win->mlx,
			"../../images/utils/tree_test2.xpm", &win->image_length, &win->image_heigth);
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
			"../../images/utils/main_floor.xpm", &win->image_length, &win->image_heigth);
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
	void	*img_collectibles;

	img_collectibles = mlx_xpm_file_to_image(win->mlx,
			"../../images/utils/Collectibles/soul_flame/tile000.xpm", &win->image_length, &win->image_heigth);
	return (img_collectibles);
}
