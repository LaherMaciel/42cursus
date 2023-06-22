/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/22 12:08:29 by lwencesl         ###   ########.fr       */
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
 * @brief Initializes the game window based on the map size and image dimensions.
 *
 * This function is called by the `window_start` function in the same file.
 *
 * It calculates the dimensions of the window by multiplying the length and height
 * of the map with the specified image dimensions. Then, it initializes the mlx structure
 * using `mlx_init` function and creates a new window with the calculated dimensions
 * using `mlx_new_window` function. Finally, it returns the updated window structure.
 *
 * @param win The window structure to be initialized.
 * @return The updated window structure.
 */
t_win	window_init(t_main_struct *boss, t_win win)
{
	if (boss->win.mapa == NULL)
		window_destroy(boss);
	win.length_size = ft_strlen(win.mapa[0]);
	win.heigth_size = 0;
	while (win.mapa[win.heigth_size])
		win.heigth_size++;
	win.length_size = win.length_size * win.image_length;
	win.heigth_size = win.heigth_size * win.image_heigth;
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, win.length_size,
			win.heigth_size, "so_long");
	ft_printf("WINDOOW CREATED\n");
	return (win);
}

/**
 * @brief Determines the size of the window.
 *
 * This function is called by the window_start() function in this file.
 *
 * @param win The window structure.
 * @return The aux_values structure with window size information.
 */
t_aux_vales	win_start_aux(t_win win)
{
	t_aux_vales	aux;

	aux.current_image = floor_image(&win);
	aux.address = mlx_get_data_addr(aux.current_image, &aux.bits_per_pixel, &aux.line_length,
		&aux.endian);
	return (aux);
}
