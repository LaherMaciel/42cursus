/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:36:56 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 21:44:32 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Print the game map to the console.
 * 
 * This function prints the contents of the game map to the console.
 * It iterates over the rows and columns of the map and prints each character
 * with the appropriate color code based on its type (player, exit, collectible,
 * wall, etc.). The colors are applied using ANSI escape sequences.
 * 
 * RED -> 31m |
 * YELLOW -> 33m |
 * BLUE -> 34m |
 * GRAY -> 90m |
 * DEFAULT COLOR -> 0m |
 * ['1'-> the 1 is to put it in bold
 * 
 * @param boss The main game structure.
*/
void	print_map(t_main_struct *boss)
{
	int	i;
	int	j;

	i = -1;
	if (!boss->win.mapa)
		return ;
	while (boss->win.mapa[++i])
	{
		j = -1;
		while (boss->win.mapa[i][++j])
		{
			if (boss->win.mapa[i][j] == 'p')
				ft_printf("\033[1;31m%c\033[0m", boss->win.mapa[i][j]);
			else if (boss->win.mapa[i][j] == 'e')
				ft_printf("\033[1;33m%c\033[0m", boss->win.mapa[i][j]);
			else if (boss->win.mapa[i][j] == 'c')
				ft_printf("\033[1;34m%c\033[0m", boss->win.mapa[i][j]);
			else if (boss->win.mapa[i][j] == '1')
				ft_printf("\033[1;0m%c\033[0m", boss->win.mapa[i][j]);
			else
				ft_printf("\033[1;90m%c\033[0m", boss->win.mapa[i][j]);
		}
		ft_printf("\n");
	}
}

/**
 * @brief Display movement information on the game window.
 * It creates a message string by combining
 * the movement count with the "Movements: " prefix, and then displays the
 * message on the window using the mlx_string_put function. The message
 * string is freed after being displayed.
 * 
 * @param boss Pointer to the main structure.
 */
void	put_movs_on_window(t_main_struct *boss)
{
	char	*message;
	char	*tmp;
	char	*vals;

	vals = ft_itoa(boss->aux.numb_of_mov);
	message = ft_strjoin("Movements: ", vals);
	free(vals);
	tmp = message;
	message = ft_strjoin(tmp, "; ");
	free(tmp);
	mlx_string_put(boss->win.mlx, boss->win.mlx_win,
		10, 20,
		0x00FFFFFF, message);
	free(message);
	ft_printf("\nMovements: %i;\n", boss->aux.numb_of_mov);
	ft_printf("Total Movements: %i;\n", boss->aux.total_mov);
}

/**
 * @brief This function displays the number of collected collectibles and the
 * total number of collectibles available on the map on the game window.
 * 
 * @param boss Pointer to the main structure.
*/
void	put_collectibles_on_window(t_main_struct *boss)
{
	char	*message;
	char	*tmp;
	char	*vals;

	vals = ft_itoa(boss->win.collected);
	message = ft_strjoin("Collectibles: ", vals);
	free(vals);
	tmp = message;
	message = ft_strjoin(tmp, " / ");
	free(tmp);
	tmp = message;
	vals = ft_itoa(boss->win.collectibles);
	message = ft_strjoin(tmp, vals);
	free(vals);
	free(tmp);
	tmp = message;
	message = ft_strjoin(tmp, "; ");
	free(tmp);
	mlx_string_put(boss->win.mlx, boss->win.mlx_win,
		10, 40, 0x00FFFFFF, message);
	free(message);
	ft_printf("Collectibles: %i / %i;\n", boss->win.collected,
		boss->win.collectibles);
}

/**
 * @brief Display the total number of collectibles collected during the game on
 * the game window.
 * 
 * @param boss Pointer to the main structure.
*/
void	put_total_collected_on_window(t_main_struct *boss)
{
	char	*message;
	char	*tmp;
	char	*vals;

	vals = ft_itoa(boss->win.total_collected);
	message = ft_strjoin("Total Collected: ", vals);
	free(vals);
	tmp = message;
	message = ft_strjoin(tmp, "; ");
	free(tmp);
	mlx_string_put(boss->win.mlx, boss->win.mlx_win, 10,
		60, 0x00FFFFFF, message);
	free(message);
	ft_printf("Total collected: %i;\n", boss->win.total_collected);
}

/**
 * @brief Print game-related information on the window.
 * 
 * This function prints the game map, upgrades the collectibles,
 * and displays various game-related information on the window,
 * such as player movements, collectibles, and the total number
 * of collectibles collected.
 * 
 * @param boss The main game structure.
*/
void	my_prints(t_main_struct *boss)
{
	print_map(boss);
	boss->img = upgrade_collectibles(boss);
	mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win,
		boss->img.main_image, 0, 0);
	put_movs_on_window(boss);
	put_collectibles_on_window(boss);
	put_total_collected_on_window(boss);
}
