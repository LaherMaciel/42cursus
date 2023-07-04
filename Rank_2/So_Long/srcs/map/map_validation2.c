/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:02:17 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 20:54:20 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Perform flood fill algorithm on a test map.
 * 
 * This function applies the flood fill algorithm to a test map represented by
 * a 2D character array. It starts at the given position (y, x) and fills
 * connected empty cells ('0') or cells with collectibles ('c') or exit ('e')
 * with 'p' to mark the path. If an exit cell is encountered, it is marked
 * with 'E' and the exit flag is set to 1. If a cell with a collectible is
 * encountered after finding an exit, it is marked with 'C'.
 * 
 * @param test_map The test map represented by a 2D character array.
 * @param y The y-coordinate of the starting position.
 * @param x The x-coordinate of the starting position.
 * @param exit Flag to indicate if an exit has been found.
 * @return char** The modified test map after applying the flood fill algorithm.
*/
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

/**
 * @brief Perform the last base check on the map.
 * 
 * This function checks if the number of players, exits, and collectibles
 * in the map meet the required conditions. If any of these conditions
 * is not satisfied, an error is raised.
 * 
 * @param boss The main game structure.
 * @param win The game window structure.
*/
void	map_last_base_check(t_main_struct*boss, t_win win)
{
	if (win.player_look != 1)
		error_call("Number of Players Different then 1", boss);
	if (win.exit != 1)
		error_call("Number of exits Different then 1", boss);
	if (win.collectibles < 1)
		error_call("Number of collectibles smaller then 1", boss);
}

/**
 * @brief Clean up the memory allocated for the test map.
 * 
 * This function frees the memory allocated for each row of the test map
 * and then frees the memory for the entire test map array.
 * 
 * @param test_map The test map array.
*/
void	clean_testmap(char **test_map)
{
	int	i;

	i = -1;
	while (test_map[++i])
		free(test_map[i]);
	free(test_map);
}

/**
 * @brief Perform additional checks on the map to ensure its validity.
 * 
 * This function creates a test map using the provided filename and performs
 * a flood fill algorithm starting from the player's position to check if
 * all areas of the map are reachable. It also checks for any unreachable
 * exit or collectible tiles. If any issues are found, an error is raised
 * and the program is terminated.
 * 
 * @param boss The main game structure.
 * @param win The game window structure.
 * @param filename The name of the map file.
 * @return int Returns 0 if the map passes all checks.
*/
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
