/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:59:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 21:05:24 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
