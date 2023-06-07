/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:56:15 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 22:56:45 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_map(t_win *win)
{
	int	i;

	i = 0;
	while (win->mapa[i])
	{
		free(win->mapa[i]);
		i++;
	}
	free(win->mapa);
}

int	window_destroy(t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	mlx_destroy_display(win->mlx);
	destroy_map(win);
	free(win->mlx);
	exit(0);
}
