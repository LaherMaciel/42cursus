/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:59:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/03 21:50:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*=============================================


==============================================*/

/*t_win	creat_mapa(t_main_struct *boss)
{
	t_win	win;

	//win = creat_map_mod(boss);
	win = creat_map(boss, win);
	return (win);
}*/

t_win	map_base_check_aux2(t_main_struct *boss, t_win win, int x, int y)
{
	if ((win.mapa[0][y] != '1') || (win.mapa[x][0] != '1'))
		error_call("Map not surrounded by walls", boss);
	if (win.mapa[x][y] == 'p' || win.mapa[x][y] == 'P')
	{
		win.player_y = x;
		win.player_x = y;
		win.player_look++;
		win.mapa[x][y] = 'p';
	}
	else if (win.mapa[x][y] == 'e' || win.mapa[x][y] == 'E')
	{
		win.mapa[x][y] = 'e';
		win.exit++;
	}
	else if (win.mapa[x][y] == 'c' || win.mapa[x][y] == 'C')
	{
		win.mapa[x][y] = 'c';
		win.collectibles++;
	}
	else if (win.mapa[x][y] != '0' && win.mapa[x][y] != '1')
		error_call("Unidentified characters on the Map", boss);
	return (win);
}

t_win	map_base_check_aux(t_main_struct *boss, t_win win,
	int x, int x_max_len)
{
	int	y;
	int	y_max_len;

	y = -1;
	y_max_len = ft_strlen(win.mapa[x]) - 1;
	while (win.mapa[x][++y])
	{
		win = map_base_check_aux2(boss, win, x, y);
		if ((win.mapa[x_max_len][y] != '1')
			|| (win.mapa[x][y_max_len] != '1'))
			error_call("Map not surrounded by walls", boss);
	}
	return (win);
}

/**
 * @brief does the basic checks to see if the map is valid like
 *  see if the map has only 1 player, only 1 exit, if it has at least
 *  1 collectible and if the map is surrounded by walls.
 *
 * @param win
 * @return int
 */
t_win	map_base_check(t_main_struct *boss, t_win win)
{
	int	x;
	int	x_max_len;

	win.player_look = 0;
	win.exit = 0;
	x_max_len = 0;
	while (win.mapa[x_max_len])
		x_max_len++;
	x_max_len--;
	win.mapa_heigth = x_max_len;
	x = -1;
	if ((win.mapa[0][0] != '1')
		|| (win.mapa[x_max_len][(ft_strlen(win.mapa[0]) - 1)] != '1'))
		error_call("Map not surrounded by walls", boss);
	while (++x < x_max_len)
	{
		if ((ft_strlen(win.mapa[0]) - 1) != (ft_strlen(win.mapa[x]) - 1))
			error_call("The Map is not a rectangle", boss);
		win = map_base_check_aux(boss, win, x, x_max_len);
	}
	win.mapa_length = ft_strlen(win.mapa[x]) - 1;
	map_last_base_check(boss, win);
	return (win);
}

t_win	validate_map(t_main_struct *boss, t_win win, char *filename)
{
	win = map_base_check(boss, win);
	map_check2(boss, win, filename);
	return (win);
}
