/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:08:08 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 01:35:28 by lwencesl         ###   ########.fr       */
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

/**
 * @brief Fill the main image with the floor images.
 *
 * This function fills the main image with the floor image. It iterates over the positions
 * (x, y) of the main image and checks if the current position is a multiple of the floor image's
 * dimensions (image_length and image_height). If it is, it uses the `mlx_put_image_to_window`
 * function to put the floor image at that position on the window. The function keeps track of the
 * current positions (i, j) within the map and increments them accordingly. It continues this process
 * until it has filled the entire main image with the floor image. Finally, it returns the modified main image.
 *
 * @param win A pointer to the window structure.
 * @param img The main image data structure.
 * @return t_data The modified main image data structure.
 */
t_data	floor_on_window(t_main_struct *boss)
{
	int	ignx0;
	int	ignx1;
	int	igny0;
	int	igny1;

	ignx0 = ignore_x(boss, 0);
	ignx1 = ignore_x(boss, 1);
	igny0 = ignore_y(boss, 0);
	igny1 = ignore_y(boss, 1);
	boss->aux.current_image = boss->aux.img_floor;
	ft_printf("put_floor -> IN\n");
	boss->aux.y = -1;
	boss->win.i = 0;
	while (++boss->aux.y < boss->win.heigth_size && boss->win.mapa[boss->win.i])
	{
		boss->aux.x = -1;
		boss->win.j = 0;
		while (++boss->aux.x < boss->win.length_size
			&& boss->win.mapa[boss->win.i][boss->win.j])
		{
			if ((boss->aux.x % boss->win.image_length == 0))
			{
				boss->aux.current_image_x = 0;
				boss->win.j++;
			}
			if (((boss->aux.current_image_x >= ignx0 && boss->aux.current_image_x <= ignx1)
				|| (ignx0 == 32 && ignx1 == 32))
					&& ((boss->aux.current_image_y >= igny0 && boss->aux.current_image_y <= igny1)
						|| ((igny0 == 32 && igny1 == 32))))
			{
				get_color_of_aux_image(&boss->aux);
				if (boss->aux.color && boss->aux.color != 4278190080)
					my_mlx_pixel_put(&boss->img, boss->aux.x, boss->aux.y, boss->aux.color);
			}
			if (boss->aux.current_image_x % boss->win.image_length == 0 && boss->aux.current_image_x != 0)
				boss->aux.current_image_x = -1;
			boss->aux.current_image_x++;
		}
		if (boss->aux.y % boss->win.image_heigth == 0)
		{
			boss->aux.current_image_y = -1;
			boss->win.i++;
		}
		boss->aux.current_image_y++;
	}
	mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win, boss->img.main_image, 0, 0);
	ft_printf("put_floor -> OUT\n");
	return (boss->img);
}


/**
 * @brief Choose the appropriate auxiliary image based on the value in the map.
 *
 * This function examines the value in the map at the current position (i, j) and determines
 * which auxiliary image should be used. If the value is '1', it returns the wall image. If the
 * value is 'p', it returns the player image. If the value is 'c', it returns the collectibles image.
 * If the value is 'e', it returns the exit image. If none of these conditions are met, it returns
 * the floor image.
 *
 * @param boss A pointer to the boss structure.
 * @param img A pointer to the main image data structure.
 * @return void* A pointer to the chosen auxiliary image.
 */
void	*choose_aux_image2(t_main_struct *boss)
{
	/*boss->aux.ignore_x0 = ignore_x(boss, 0);
	boss->aux.ignore_x1 = ignore_x(boss, 1);
	boss->aux.ignore_y0 = ignore_y(boss, 0);
	boss->aux.ignore_y1 = ignore_y(boss, 1);*/
	if (boss->win.mapa[boss->win.i][boss->win.j] == '1')
		return (boss->aux.img_wall);
	else if (boss->win.mapa[boss->win.i][boss->win.j] == 'p')
		return (boss->aux.img_player);
	else if (boss->win.mapa[boss->win.i][boss->win.j] == 'c')
		return (boss->aux.img_collectibles);
	else if (boss->win.mapa[boss->win.i][boss->win.j] == 'e')
		return (boss->aux.img_exit);
	return (boss->aux.img_floor);
}

/**
 * @brief Fill main images with colors from secondary images.
 *
 * This function fills the main images by iterating over the window's length and height
 * and retrieving the appropriate colors from the secondary images. It uses auxiliary variables
 * for iteration and checks if coordinates are divisible by the image length and height to
 * determine when to retrieve a new auxiliary image. Colors are obtained using the
 * `choose_aux_image` and `get_color_of_aux_image` functions. Non-zero colors are set in the
 * corresponding main image pixels using `my_mlx_pixel_put`. The function resets the current
 * image coordinates and updates the main image in the window after each row and column. The
 * modified main image data structure is returned.
 *
 * @param boss Pointer to the main structure.
 * @return t_data Modified main image data structure.
 */
t_data	put_color_on_main_images(t_main_struct *boss)
{
	int	ignx0;
	int	ignx1;
	int	igny0;
	int	igny1;

	ft_printf("put_color_on_main_images -> IN\n");
	boss->aux.y = -1;
	boss->win.i = 0;
	while (++boss->aux.y < boss->win.heigth_size && boss->win.mapa[boss->win.i])
	{
		boss->aux.x = -1;
		boss->win.j = 0;
		while (++boss->aux.x < boss->win.length_size
			&& boss->win.mapa[boss->win.i][boss->win.j])
		{
			if ((boss->aux.x % boss->win.image_length == 0))
			{
				boss->aux.current_image = choose_aux_image2(boss);
				boss->aux.current_image_x = 0;
				ignx0 = ignore_x(boss, 0);
				ignx1 = ignore_x(boss, 1);
				igny0 = ignore_y(boss, 0);
				igny1 = ignore_y(boss, 1);
				boss->win.j++;
			}
			if (((boss->aux.current_image_x >= ignx0 && boss->aux.current_image_x <= ignx1)
				|| (ignx0 == 32 && ignx1 == 32))
					&& ((boss->aux.current_image_y >= igny0 && boss->aux.current_image_y <= igny1)
						|| ((igny0 == 32 && igny1 == 32))))
			{
				get_color_of_aux_image(&boss->aux);
				if (boss->aux.color && boss->aux.color != 4278190080)
					my_mlx_pixel_put(&boss->img, boss->aux.x, boss->aux.y, boss->aux.color);
			}
			if (boss->aux.current_image_x % boss->win.image_length == 0 && boss->aux.current_image_x != 0)
				boss->aux.current_image_x = -1;
			boss->aux.current_image_x++;
		}
		if (boss->aux.y % boss->win.image_heigth == 0 && boss->aux.current_image_y != 0)
		{
			boss->aux.current_image_y = -1;
			boss->win.i++;
		}
		boss->aux.current_image_y++;
	}
	mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win, boss->img.main_image, 0, 0);
	ft_printf("put_color_on_main_images -> OUT\n");
	return (boss->img);
}


/**
 * @brief Create main game images and initialize secondary images.
 *
 * This function creates the main images for the game and initializes secondary
 * images such as walls, collectibles, exit, and the player. It takes a pointer
 * to the main game structure. The main image and secondary images are created and
 * initialized using specific functions. The floor image is filled onto the main
 * image based on the map layout, and the colors are applied to the main images.
 * Finally, the function sets the length of the map and prints a confirmation message.
 *
 * @param boss Pointer to the main game structure.
 */
t_data	create_main_image(t_main_struct *boss)
{
	boss->aux.img_wall = wall_image(&boss->win);
	if (!boss->aux.img_wall)
		return (boss->img);
	boss->aux.img_player = player_image(&boss->win);
	if (!boss->aux.img_player)
		return (boss->img);
	boss->aux.img_collectibles = collectibles_image(&boss->win);
	if (!boss->aux.img_collectibles)
		return (boss->img);
	boss->aux.img_exit = exit_image(&boss->win);
	if (!boss->aux.img_exit)
		return (boss->img);
	boss->aux.img_floor = floor_image(&boss->win);
	if (!boss->aux.img_floor)
		return (boss->img);
	boss->aux.current_image = floor_image(&boss->win);
	if (!boss->aux.img_wall)
		return (boss->img);
	boss->img = floor_on_window(boss);
	boss->img = put_color_on_main_images(boss);
	//win->mapa_heigth = 0;
	//while (win->mapa[0][win->mapa_heigth])
	//	win->mapa_heigth++;
	ft_printf("IMAGE CREATED\n");
	return (boss->img);
}

/**
 * @brief Initializes the window and displays the first image.
 *
 * This function is called by the main function to set up the program's initial state.
 * It performs the following steps:
 * 1. Calls win_start_aux(boss.win) and window_init(boss.win) in this file for window setup.
 * 2. Calls player_image(&boss.win) in another file to retrieve the player image.
 * 3. Calls create_main_image(&boss, player_image(&boss.win)) in main_image.c to create the main image.
 *
 * Uses minilibx functions: mlx_new_image(), mlx_get_data_addr().
 *
 * @param boss The main_struct with program data and structures.
 * @return The updated main_struct after window setup and image display.
 */
t_data	start_image(t_main_struct *boss)
{
	ft_printf("%s\n\n", boss->win.mapa[0]);
	boss->img.main_image = mlx_new_image(boss->win.mlx, boss->win.length_size, boss->win.heigth_size);
	boss->img.addr = mlx_get_data_addr(boss->img.main_image, &boss->img.bits_per_pixel, &boss->img.line_length,
								&boss->img.endian);
	boss->img = create_main_image(boss);
	if (!boss->aux.img_floor)
		ft_printf("ERROR");
	ft_printf("img: %p\n", boss->aux.img_floor);
	return (boss->img);
}
