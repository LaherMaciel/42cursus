/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:36:11 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 23:54:26 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 *@brief This function frees the memory allocated for the
 * map array in the extras structure.
 * @param extras The structure containing additional resources.
 * @return void
 */
void	destroy_extra_struct(t_extras *extras)
{
	int	i;

	i = -1;
	if (extras->map_names[0])
	{
		while (extras->map_names[++i])
			free(extras->map_names[i]);
		free(extras->map_names);
	}
}

/**
 * @brief This function destroys the game window and frees the 
 * allocated memory for the map array in the win structure.
 * It also frees the 'mlx' structure. 
 * 
 * @param *win
 * @return void
 */
void	destroy_win_struct(t_win *win)
{
	int	i;

	i = -1;
	if (win->mlx)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	if (win->mapa)
	{
		while (win->mapa[++i])
			free(win->mapa[i]);
		free(win->mapa);
	}
}

/**
 * @brief Ends the game, frees resources, and terminates the program.
 * This function frees allocated memory for resources in the boss structure,
 * destroys the main image, and terminates the program. It calls the
 * destroy_extra_struct() function to free extra resources and the 
 * destroy_win_struct() function to destroy the game window. If error is
 * not equal to 1, it prints game statistics. Finally, it exits the program.
 
 * @param boss The main structure with game resources.
 * @param error The error code indicating game's end condition.
 * @return int Exit status code (not actually returned as program exits
 * immediately).
*/
int	end_game(t_main_struct *boss, int error)
{
	destroy_extra_struct(&boss->extras);
	if (boss->img.main_image)
		mlx_destroy_image(boss->win.mlx, boss->img.main_image);
	destroy_win_struct(&boss->win);
	if (error != 1)
	{
		ft_printf(RED"\n		!!GAME OVER!!		\n\n"DEFAULT_COLOR);
		ft_printf("Total collected: %i\n", boss->win.total_collected);
		ft_printf("Total Movements: %i\n", boss->aux.total_mov);
		if (boss->win.exit == 2)
			ft_printf("Total Maps Complited: %i\n\n",
				(boss->win.current_map + 1));
		else
			ft_printf("Total Maps Complited: %i\n\n",
				(boss->win.current_map));
	}
	exit(0);
}

/**
 * @brief Destroys the game window and associated resources.
 * This function destroys the main image using mlx_destroy_image()
 * and calls the destroy_win_struct() function to destroy the game
 * window and free associated resources.
 * 
 * @param boss The main structure containing game resources.
 * @return void
*/
void	window_destroy(t_main_struct *boss)
{
	if (boss->img.main_image)
		mlx_destroy_image(boss->win.mlx, boss->img.main_image);
	destroy_win_struct(&boss->win);
}
