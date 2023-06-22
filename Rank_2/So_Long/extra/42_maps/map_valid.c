/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:33:49 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/22 23:36:58 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_win	map_base_check(t_main_struct *boss, t_win win)
{
	int	x;
	int	y;
	int	x_max_len;
	int	y_max_len;
	int	base_max_y_len;
	int	player;
	int	exit;

	x = -1;
	player = 0;
	exit = 0;
	win.collectibles = 0;
	x_max_len = 0;
	while (win.mapa[++x])
		x_max_len++;
	x_max_len--;
	x = -1;
	base_max_y_len = ft_strlen(win.mapa[0]) - 1;
	if ((win.mapa[0][0] != '1') || (win.mapa[x_max_len][base_max_y_len] != '1'))
		error_call("Mapa Not Surrounded by Walls", boss);
	while (++x < x_max_len)
	{
		y = -1;
		y_max_len = ft_strlen(win.mapa[x]) - 1;
		if (base_max_y_len != y_max_len)
			error_call("The Mapa Is Not a Rectangle", boss);
		while (win.mapa[x][++y])
		{
			if ((win.mapa[0][y] != '1') || (win.mapa[x][0] != '1'))
				error_call("Mapa Not Surrounded by Walls", boss);
			else if ((win.mapa[x_max_len][y] != '1')
				|| (win.mapa[x][y_max_len] != '1'))
				error_call("Mapa Not Surrounded by Walls", boss);
			else if (win.mapa[x][y] == 'p')
			{
				win.player_y = x;
				win.player_x = y;
				player++;
			}
			else if (win.mapa[x][y] == 'e')
				exit++;
			else if (win.mapa[x][y] == 'c')
				win.collectibles++;
			else if ((win.mapa[x][y] != '0' && win.mapa[x][y] != '1')
				|| (win.mapa[x][y] != 'W' && win.mapa[x][y] != 'X')
				|| (win.mapa[x][y] != 'Y' && win.mapa[x][y] != 'Z'))
				error_call("Unidentified Characters on The Map", boss);
		}
	}
	win.mapa_heigth = x;
	win.mapa_length = y;
	if (player != 1)
		error_call("Number of Players Different then 1", boss);
	if (exit != 1)
		error_call("Number of exits Different then 1", boss);
	if (win.collectibles < 1)
		error_call("Number of collectibles smaller then 1", boss);
	return (win);
}

t_win	validate_map(t_main_struct *boss, t_win win, char *filename)
{
	win = map_base_check(boss, win);
	map_check2(boss, win, filename);
	return (win);
}

