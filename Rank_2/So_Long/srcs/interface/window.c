/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/05 01:34:35 by lwencesl         ###   ########.fr       */
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
include the 'mlx.h' on your '.h' project file mlx_init() -> used to inicialize
the library. It returns a (void *)
mlx_new_window(pointer_returned_by_mlx_init(), width, heigth,
"the_name_of_the_window") -> used to initialize a window. return the (void *) to
the new window created. mlx_new_image() -> mlx_loop() -> initiate the window
rendering.
==============================================*/

/**
 * @brief Initializes the game window based on the map size and image
 * dimensions. This function calculates the dimensions of the window by
 * multiplying the length and height of the map with the specified image
 * dimensions. It then initializes the mlx structure using the mlx_init function
 * and creates a new window with the calculated dimensions using the
 * mlx_new_window function.
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
		error_call("Map too long. Map can't have more " \
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

/**
 * @brief This function destroys the current game window, then initializes the
 * image values, and initializes the window values using the corresponding
 * initialization functions.
 *
 * @param boss
 */
void	fresh_start(t_main_struct *boss)
{
	window_destroy(boss);
	boss->img.main_image = NULL;
	boss->win = win_vals_init(boss->win);
}

/**
 * @brief Create a new game window. This function takes a pointer to the main
 * structure (boss) as input and creates a new game window. It performs the
 * necessary steps to initialize the window, map, image, and other components of
 * the game. It sets the current map based on the new_map value in the window
 * structure, creates the map using the creat_map function, validates the map
 * using the validate_map function, initializes the window using the window_init
 * function, and starts the image using the start_image function. It also sets
 * up event hooks for keyboard input and window closure. Finally, it enters the
 * event loop using the mlx_loop function to start the game.
 *
 * @param boss Pointer to the main structure.
*/
void	new_window(t_main_struct *boss)
{
	int	n;

	n = boss->win.new_map;
	fresh_start(boss);
	boss->win.current_map = n;
	boss->win.mapa = creat_map(boss,
			boss->extras.map_names[boss->win.current_map]);
	boss->win = validate_map(boss, boss->win,
			boss->extras.map_names[boss->win.current_map]);
	boss->win = window_init(boss, boss->win);
	boss->img = start_image2(boss);
	ft_printf(CLEAR"MAPA %i READY\n", (boss->win.current_map + 1));
	my_prints(boss, 2);
	mlx_hook(boss->win.mlx_win, 2, 1L << 0, keycode_decisions, boss);
	boss->img = upgrade_player2(boss, 0);
	mlx_hook(boss->win.mlx_win, 17, 1L, end_game, &boss);
	mlx_loop(boss->win.mlx);
}
