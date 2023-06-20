/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:59:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 19:55:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*=============================================


==============================================*/

t_win	creat_mapa(t_main_struct *boss)
{
	t_win	win;

	win = creat_map_mod(boss, win);
	//win = creat_map(boss, win);
	return (win);
}

char	**flood_fill(char **test_map, int y, int x, int exit)
{
	if (test_map[y][x] == 'e' || test_map[y][x] == 'E')
	{
		test_map[y][x] = 'E';
		exit = 1;
		return (test_map);
	}
	else if (exit == 1 && test_map[y][x] == 'c')
		test_map[y][x] = 'C';
	else
		test_map[y][x] = 'p';
	if ((test_map[(y + 1)][x] == '0') || (test_map[(y + 1)][x] == 'c')
		|| (test_map[(y + 1)][x] == 'e'))
		test_map = flood_fill(test_map, (y + 1), x, exit);
	if ((test_map[y][(x + 1)] == '0') || (test_map[y][(x + 1)] == 'c')
		|| (test_map[y][(x + 1)] == 'e'))
		test_map = flood_fill(test_map, y, (x + 1), exit);
	if ((test_map[(y - 1)][(x)] == '0') || (test_map[(y - 1)][(x)] == 'c')
		|| (test_map[(y - 1)][(x)] == 'e'))
		test_map = flood_fill(test_map, (y - 1), x, exit);
	if ((test_map[y][(x - 1)] == '0') || (test_map[y][(x - 1)] == 'c')
		|| (test_map[y][(x - 1)] == 'e'))
		test_map = flood_fill(test_map, y, (x - 1), exit);
	return (test_map);
}

int	map_check2(t_main_struct *boss, t_win win)
{
	int		i;
	int		j;
	char **test_map;

	test_map = win.mapa;
	i = -1;
	ft_printf("\n");
	while (test_map[++i])
		ft_printf("%s\n", test_map[i]);
	ft_printf("\n");
	test_map = flood_fill(test_map, win.player_y, win.player_x, 0);
	i = -1;
	while (test_map[++i])
		ft_printf("%s\n", test_map[i]);
	i = -1;
	while (test_map[++i])
	{
		j = -1;
		while (test_map[i][++j])
			if (test_map[i][j] == 'c' || test_map[i][j] == 'C'
				|| test_map[i][j] == 'e')
				error_call("Non-playable map", boss);
	}
	return (0);
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
			else if (win.mapa[x][y] != '0' && win.mapa[x][y] != '1')
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

t_win	validate_map(t_main_struct *boss, t_win win)
{
	win = map_base_check(boss, win);
	map_check2(boss, win);
	return (win);
}
