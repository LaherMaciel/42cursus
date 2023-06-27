/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:36:11 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/27 20:38:09 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Destroys the game window, frees the map, and terminates the
 *  program.
 *
 * It destroys the window and display using `mlx_destroy_window` and
 *  `mlx_destroy_display`
 * functions. Then, it iterates through the map array and frees the
 *  allocated memory.
 * Finally, it frees the `mlx` structure and exits the program with
 *  status code 0.
 *
 * @param win The window structure to be destroyed.
 * @return void
 */
void	destroy_extra_struct(t_extras *extras)
{
	int	i;

	i = -1;
	while (extras->map_names[++i])
		free(extras->map_names[i]);
	free(extras->map_names);
}

void	destroy_win_struct(t_win *win)
{
	int	i;

	i = -1;
	if (win->mlx)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		mlx_destroy_display(win->mlx);
	}
	while (win->mapa[++i])
		free(win->mapa[i]);
	free(win->mapa);
	free(win->mlx);
}

//	destroy_aux_struct(&boss->aux);
int	end_game(t_main_struct *boss)
{
	destroy_extra_struct(&boss->extras);
	free(boss->aux.current_image);
	//mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	destroy_win_struct(&boss->win);
	exit(0);
}

void	window_destroy(t_main_struct *boss)
{
	free(boss->aux.current_image);
	//mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	destroy_win_struct(&boss->win);
}
