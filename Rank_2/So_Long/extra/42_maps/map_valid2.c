/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:02:17 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/24 19:03:15 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	map_last_base_check(t_main_struct*boss, t_win win)
{
	if (win.player_look != 1)
		error_call("Number of Players Different then 1", boss);
	if (win.exit != 1)
		error_call("Number of exits Different then 1", boss);
	if (win.collectibles < 1)
		error_call("Number of collectibles smaller then 1", boss);
}
