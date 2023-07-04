/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:08:08 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 21:35:20 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*=============================================
include the 'mlx.h' on your '.h' project file
mlx_init() -> used to inicialize the library. It returns a (void *)
mlx_new_window(pointer_returned_by_mlx_init(),
	width, heigth, "the_name_of_the_window") -> used to initialize a window.
	return the (void *) to the new window created.
mlx_new_image() ->
mlx_loop() -> initiate the window rendering.
==============================================*/

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
 * @brief Determines the appropriate auxiliary image based on the value in
 * the map.
 * This function examines the value in the map at the current position
 * (i, j) and determines which auxiliary image should be used.
 * 
 * @param boss The main structure containing game resources.
 * @return t_data A pointer to the chosen auxiliary image.
*/
t_data	choose_aux_image(t_main_struct *boss)
{
	if (boss->win.mapa[boss->win.i][boss->win.j] == 'p')
		return (upgrade_player(boss, 0));
	else if (boss->win.mapa[boss->win.i][boss->win.j] == 'e')
		return (put_exit(boss, boss->win.i, boss->win.j));
	else if (boss->win.mapa[boss->win.i][boss->win.j] == '1')
		return (put_wall(boss, boss->win.i, boss->win.j));
	return (boss->img);
}

/**
 * @brief Fills the main images with colors from secondary images.
 * This function fills the main images by iterating over the window's length
 * and height. It retrieves the appropriate colors from the secondary images
 * using the choose_aux_image() and get_color_of_aux_image() functions.
 * 
 * @param boss Pointer to the main structure.
 * @return t_data Modified main image data structure.
 */
t_data	put_color_on_main_images(t_main_struct *boss)
{
	boss->win.i = 0;
	while (boss->win.mapa[boss->win.i])
	{
		boss->win.j = 0;
		while (boss->win.mapa[boss->win.i][boss->win.j])
		{
			boss->img = choose_aux_image(boss);
			boss->win.j++;
		}
		boss->win.i++;
	}
	boss->img = upgrade_collectibles(boss);
	mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win,
		boss->img.main_image, 0, 0);
	return (boss->img);
}

/**
 * @brief Creates main game images.
 *
 * This function creates the main game image by filling the floor image and
 * applying colors based on secondary images. It first calls
 * floor_on_main_image_full() to fill the main image with the floor image.
 * Then, it calls put_color_on_main_images() to apply colors to the main
 * image based on secondary images.
 *
 * @param boss The main game structure.
 * @return t_data The modified main image data structure.
 */
t_data	create_main_image(t_main_struct *boss)
{
	boss->img = floor_on_main_image_full(boss);
	boss->img = put_color_on_main_images(boss);
	ft_printf("IMAGE CREATED\n");
	return (boss->img);
}

/**
 * @brief This function initializes the game image and displays it on the window.
 * It sets the number of movements to 0 and creates the main image using
 * create_main_image().
 * 
 * @param boss The main game structure.
 * @return t_data The main image data structure.
*/
t_data	start_image(t_main_struct *boss)
{
	boss->aux.numb_of_mov = 0;
	boss->img.main_image = mlx_new_image(boss->win.mlx,
			boss->win.length_size, boss->win.heigth_size);
	if (!boss->img.main_image)
		error_call("Main Image Not Created", boss);
	boss->img.addr = mlx_get_data_addr(boss->img.main_image,
			&boss->img.bits_per_pixel, &boss->img.line_length,
			&boss->img.endian);
	boss->img = create_main_image(boss);
	mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win,
		boss->img.main_image, 0, 0);
	my_prints(boss);
	return (boss->img);
}
