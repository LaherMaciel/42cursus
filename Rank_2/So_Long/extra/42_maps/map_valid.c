/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:59:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/24 19:03:03 by lwencesl         ###   ########.fr       */
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
			if (test_map[i][j] == 'c' || test_map[i][j] == 'e')
				error_call("Non-playable map", boss);
	}
	i = -1;
	while (test_map[++i])
		free(test_map[i]);
	free(test_map);
	return (0);
}

t_win	map_base_check_aux2(t_main_struct *boss, t_win win, int x, int y)
{
	if ((win.mapa[0][y] != '1') || (win.mapa[x][0] != '1'))
		error_call("Mapa Not Surrounded by Walls", boss);
	else if (win.mapa[x][y] == 'c')
		win.collectibles++;
	else if (win.mapa[x][y] != '0' && win.mapa[x][y] != '1')
		error_call("Unidentified Characters on The Map", boss);
	return (win);
}

void	map_base_check_aux(t_main_struct *boss, t_win win,
	int x, int x_max_len)
{
	int	y;
	int	y_max_len;

	y = -1;
	y_max_len = ft_strlen(win.mapa[x]) - 1;
	while (win.mapa[x][++y])
	{
		map_base_check_aux2(boss, win, x, y);
		if ((win.mapa[x_max_len][y] != '1')
			|| (win.mapa[x][y_max_len] != '1'))
			error_call("Mapa Not Surrounded by Walls", boss);
		if (win.mapa[x][y] == 'p')
		{
			win.player_y = x;
			win.player_x = y;
			win.player_look++;
		}
		if (win.mapa[x][y] == 'e')
			win.exit++;
	}
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

	x = -1;
	win.player_look = 0;
	win.exit = 0;
	x_max_len = 0;
	while (win.mapa[++x])
		x_max_len++;
	x_max_len--;
	win.mapa_heigth = x_max_len;
	x = -1;
	if ((win.mapa[0][0] != '1')
		|| (win.mapa[x_max_len][(ft_strlen(win.mapa[0]) - 1)] != '1'))
		error_call("Mapa Not Surrounded by Walls", boss);
	while (++x < x_max_len)
	{	
		if ((ft_strlen(win.mapa[0]) - 1) != (ft_strlen(win.mapa[x]) - 1))
			error_call("The Mapa Is Not a Rectangle", boss);
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
