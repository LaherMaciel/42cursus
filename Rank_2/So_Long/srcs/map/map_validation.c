/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:59:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/05 02:02:33 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_if_surrounded_by_walls(t_main_struct *boss, int y_max_len)
{
	size_t	j;
	int		i;

	j = 0;
	while (boss->win.mapa[++j])
		if ((ft_strlen(boss->win.mapa[0]) - 1)
			!= (ft_strlen(boss->win.mapa[j]) - 1))
			error_call("The Map is not a rectangle", boss);
	j--;
	if ((ft_strlen(boss->win.mapa[j])) == j)
		error_call("The Map is not a rectangle", boss);
	i = -1;
	while (boss->win.mapa[++i])
	{
		if (boss->win.mapa[i][0] == ' ')
			error_call("The Map is not a rectangle", boss);
		if (boss->win.mapa[i][0] != '1')
			error_call("Map not surrounded by walls", boss);
		if (boss->win.mapa[i][(ft_strlen(boss->win.mapa[j]) - 1)] == ' ')
			error_call("The Map is not a rectangle", boss);
		if (boss->win.mapa[i][ft_strlen(boss->win.mapa[0]) - 1] != '1')
			error_call("Map not surrounded by walls", boss);
	}
	check_if_surrounded_by_walls2(boss, y_max_len);
}

/**
 * @brief Perform base checks on individual tiles of the map.
 * 
 * This function checks each tile of the map and performs the following actions:
 * 
 * Checks if the map is surrounded by walls.
 * Identifies the player's position and updates the player-related counters.
 * Identifies the exit tile and updates the exit counter.
 * Identifies collectible tiles and updates the collectibles counter.
 * Raises an error for any unidentified characters on the map.
 * 
 * @param boss The main game structure.
 * @param win The game window structure.
 * @param x The x-coordinate of the tile.
 * @param y The y-coordinate of the tile.
 * @return t_win Returns the updated game window structure.
*/
t_win	map_base_check_aux2(t_main_struct *boss, t_win win, int y, int x)
{
	if (win.mapa[y][x] == 'p' || win.mapa[y][x] == 'P')
	{
		win.player_y = y;
		win.player_x = x;
		win.player_look++;
		win.mapa[y][x] = 'p';
	}
	else if (win.mapa[y][x] == 'e' || win.mapa[y][x] == 'E')
	{
		win.mapa[y][x] = 'e';
		win.exit++;
	}
	else if (win.mapa[y][x] == 'c' || win.mapa[y][x] == 'C')
	{
		win.mapa[y][x] = 'c';
		win.collectibles++;
	}
	else if (win.mapa[y][x] != '0' && win.mapa[y][x] != '1')
	{
		error_call("Unidentified characters on the Map", boss);
	}
	return (win);
}

/**
 * @brief Perform base checks on each row of the map.
 * 
 * This function iterates over each row of the map and calls the 
 * map_base_check_aux2 function to perform base checks on individual tiles
 * of the row. It also checks if the map is surrounded by walls by validating
 * the last row and last column.
 * 
 * @param boss The main game structure.
 * @param win The game window structure.
 * @param x The current row index.
 * @param x_max_len The maximum row index.
 * @return t_win Returns the updated game window structure.
*/
t_win	map_base_check_aux(t_main_struct *boss, t_win win, int y, int y_max_len)
{
	int	x;
	int	x_max_len;

	x = -1;
	x_max_len = ft_strlen(win.mapa[y]) - 1;
	while (win.mapa[y][++x])
	{
		win = map_base_check_aux2(boss, win, y, x);
		if ((win.mapa[y_max_len][x] == ' ') || (win.mapa[y][x_max_len] == ' '))
			error_call("The Map is not a rectangle", boss);
	}
	return (win);
}

/**
 * @brief This function checks if the map has only one player, only one exit,
 * at least one collectible, and if the map is surrounded by walls.
 * 
 * It iterates over each row of the map and calls the map_base_check_aux
 * function to perform checks on individual tiles of the row. It also
 * validates the map dimensions and ensures that it is rectangular.
 * 
 * @param boss The main game structure.
 * @param win The game window structure.
 * @return t_win Returns the updated game window structure.
*/
t_win	map_base_check(t_main_struct *boss, t_win win)
{
	int	y;
	int	y_max_len;

	win.player_look = 0;
	win.exit = 0;
	y_max_len = 0;
	while (win.mapa[y_max_len])
		y_max_len++;
	y_max_len--;
	win.mapa_heigth = y_max_len;
	y = -1;
	check_if_surrounded_by_walls(boss, y_max_len);
	while (++y <= y_max_len)
		win = map_base_check_aux(boss, win, y, y_max_len);
	if ((win.mapa[0][0] != '1')
		|| (win.mapa[y_max_len][(ft_strlen(win.mapa[0]) - 1)] != '1'))
		error_call("Map not surrounded by walls", boss);
	map_last_base_check(boss, win);
	return (win);
}

/**
 * @brief Validate the map by performing necessary checks.
 * 
 * This function validates the map by first performing basic checks using the
 * map_base_check function. It then calls the map_check2 function to perform
 * additional checks, including flood fill to ensure all areas of the map are
 * reachable. The function returns the updated game window structure after
 * validation.
 * 
 * @param boss The main game structure.
 * @param win The game window structure.
 * @param filename The name of the map file.
 * @return t_win Returns the updated game window structure after validation.
*/
t_win	validate_map(t_main_struct *boss, t_win win, char *filename)
{
	win = map_base_check(boss, win);
	map_check2(boss, win, filename);
	return (win);
}
