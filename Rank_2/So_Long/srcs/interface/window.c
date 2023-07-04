/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 19:46:39 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Set the window size of the 'win' object
 * 
 * @param win The 'win' object
 * @return The updated 'win' object with the window size set
*/
t_win	set_windowsize(t_win win)
{
	win.length_size = ft_strlen(win.mapa[0]);
	win.heigth_size = 0;
	while (win.mapa[win.heigth_size])
		win.heigth_size++;
	win.length_size = win.length_size * win.image_length;
	win.heigth_size = win.heigth_size * win.image_heigth;
	return (win);
}

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
 * This function calculates the dimensions of the window by multiplying the
 * length and height of the map with the specified image dimensions. It then
 * initializes the mlx structure using the mlx_init function and creates a
 * new window with the calculated dimensions using the mlx_new_window function.
 * 
 * @param boss Pointer to the main structure containing game data.
 * @param win The window structure to be initialized.
 * @return The updated window structure.
*/
t_win	window_init(t_main_struct *boss, t_win win)
{
	char	*window_name;
	char	*tmp;

	tmp = boss->extras.map_names[boss->win.current_map];
	window_name = ft_substr(tmp, 0, ft_strlen(tmp) - 4);
	if (boss->win.mapa == NULL)
		window_destroy(boss);
	win = set_windowsize(boss->win);
	if (win.length_size > 1920 || win.heigth_size > 1080)
	{
		free(window_name);
		error_call("Map too long. Map can't have more "\
			"then 30 columns and 16 rows", boss);
	}
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, win.length_size,
			win.heigth_size, window_name);
	boss->win.new_map = boss->win.current_map;
	free(window_name);
	ft_printf("WINDOOW CREATED\n");
	return (win);
}
