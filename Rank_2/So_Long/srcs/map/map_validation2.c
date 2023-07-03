/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:02:17 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/03 21:50:53 by lwencesl         ###   ########.fr       */
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

void	clean_testmap(char **test_map)
{
	int	i;

	i = -1;
	while (test_map[++i])
		free(test_map[i]);
	free(test_map);
}

int	map_check2(t_main_struct *boss, t_win win, char *filename)
{
	int		i;
	int		j;
	char	**test_map;

	test_map = creat_map(boss, filename);
	test_map = flood_fill(test_map, win.player_y, win.player_x, 0);
	i = -1;
	while (test_map[++i])
	{
		j = -1;
		while (test_map[i][++j])
		{
			if (test_map[i][j] == 'c' || test_map[i][j] == 'e')
			{
				clean_testmap(test_map);
				error_call("Non-playable map, unreachable "\
					"Exit or Collectible", boss);
			}
		}
	}
	clean_testmap(test_map);
	return (0);
}
