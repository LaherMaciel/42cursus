/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:36:11 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 03:24:17 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Destroys the game window, frees the map, and terminates the program.
 *
 * It destroys the window and display using `mlx_destroy_window` and `mlx_destroy_display`
 * functions. Then, it iterates through the map array and frees the allocated memory.
 * Finally, it frees the `mlx` structure and exits the program with status code 0.
 *
 * @param win The window structure to be destroyed.
 * @return void
 */
void	destroy_win_struct(t_win *win)
{
	int	i;

	i = -1;
	mlx_destroy_window(win->mlx, win->mlx_win);
	mlx_destroy_display(win->mlx);
	while (win->mapa[++i])
		free(win->mapa[i]);
	free(win->mapa);
//	free(win->mlx_win);
	free(win->mlx);
}

void	destroy_data_struct(t_data *img)
{
	if (img->main_image)
		free(img->main_image);
}

void	destroy_aux_struct(t_aux_vales *aux)
{
	if (aux->img_wall)
		free(aux->img_wall);
	if (aux->img_player)
		free(aux->img_player);
	if (aux->img_collectibles)
		free(aux->img_collectibles);
	if (aux->img_exit)
		free(aux->img_exit);
	if (aux->img_floor)
		free(aux->img_floor);
	if (aux->current_image)
		free(aux->current_image);
	if (aux->address)
		free(aux->address);
}

int	window_destroy(t_main_struct *boss)
{
	destroy_data_struct(&boss->img);
	destroy_aux_struct(&boss->aux);
	destroy_win_struct(&boss->win);
	exit(0);
}
