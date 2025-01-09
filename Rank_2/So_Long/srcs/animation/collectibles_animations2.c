/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_animations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:30:39 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:13:05 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Upgrade the collectibles in the game.
 *
 * This function upgrades the collectibles in the game by replacing the 'c'
 * characters in the map with the appropriate image. It loops through the map
 * and calls the upgrade_main_image() function to replace the collectibles with
 * the current image. The collectibles_image() function is used to get the
 * appropriate image based on the number of 'win-collect' value.
 *
 * @param boss The main game structure.
 * @return t_data Returns the updated image data.
*/
t_data	upgrade_collectibles2(t_main_struct *boss)
{
	int	i;
	int	j;

	i = 0;
	if (boss->win.exit == 2)
		return (boss->img);
	boss->aux.current_image = collectibles_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("Collectibles Image Not Created", boss);
	while (boss->win.mapa[i])
	{
		j = 0;
		while (boss->win.mapa[i][j])
			if (boss->win.mapa[i][j++] == 'c')
				boss->img = upgrade_main_image2(boss, (i + 1), j);
		i++;
	}
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}

/**
 * @brief Perform the collect action in the game.
 *
 * This function performs the collect action in the game. It updates the image
 * data by putting the floor tile on the next block based on the player's
 * direction. The put_floor function is used to replace the collectible tile
 * with the image of the floor tile.
 *
 * @param boss The main game structure.
 * @return t_data Returns the updated image data.
*/
t_data	collect2(t_main_struct *boss)
{
	if (boss->win.player_look == 0)
		boss->img = put_floor2(boss,
				(boss->win.player_y - 1), (boss->win.player_x));
	if (boss->win.player_look == 1)
		boss->img = put_floor2(boss,
				(boss->win.player_y + 1), (boss->win.player_x));
	if (boss->win.player_look == 2)
		boss->img = put_floor2(boss,
				(boss->win.player_y), (boss->win.player_x - 1));
	if (boss->win.player_look == 3)
		boss->img = put_floor2(boss,
				(boss->win.player_y), (boss->win.player_x + 1));
	return (boss->img);
}
