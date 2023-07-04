/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:36:13 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 21:38:24 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	boss->img = img_vals_init(boss->img);
	boss->win = win_vals_init(boss->win);
}

/**
 * @brief Create a new game window.
 * This function takes a pointer to the main structure (boss) as input and
 * creates a new game window. It performs the necessary steps to initialize
 * the window, map, image, and other components of the game. It sets the
 * current map based on the new_map value in the window structure, creates
 * the map using the creat_map function, validates the map using the
 * validate_map function, initializes the window using the window_init
 * function, and starts the image using the start_image function. It also
 * sets up event hooks for keyboard input and window closure. Finally, it
 * enters the event loop using the mlx_loop function to start the game.
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
	boss->img = start_image(boss);
	ft_printf(CLEAR"MAPA %i READY\n", (boss->win.current_map + 1));
	my_prints(boss);
	mlx_hook(boss->win.mlx_win, 2, 1L << 0, keycode_decisions, boss);
	boss->img = upgrade_player(boss, 0);
	mlx_hook(boss->win.mlx_win, 17, 1L, end_game, &boss);
	mlx_loop(boss->win.mlx);
}
