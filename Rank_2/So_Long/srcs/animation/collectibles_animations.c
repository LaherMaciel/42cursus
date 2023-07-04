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
 * @brief This function loads the collectibles image.
 *
 * It selects the appropriate image file based on the value of win->collect and
 * returns the corresponding image.
 *
 * @param win The game window structure.
 * @return void* Returns the collectibles image.
*/
void	*collectibles_image(t_win *win)
{
	void	*img_collectibles;

	if (win->collect == 0)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"images/utils/Collectibles/soul_flame/tile000.xpm",
				&win->image_length, &win->image_heigth);
	if (win->collect == 1)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"images/utils/Collectibles/soul_flame/tile001.xpm",
				&win->image_length, &win->image_heigth);
	if (win->collect == 2)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"images/utils/Collectibles/soul_flame/tile002.xpm",
				&win->image_length, &win->image_heigth);
	if (win->collect == 3)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"images/utils/Collectibles/soul_flame/tile003.xpm",
				&win->image_length, &win->image_heigth);
	win->collect++;
	if (win->collect == 4)
		win->collect = 0;
	return (img_collectibles);
}

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
t_data	upgrade_collectibles(t_main_struct *boss)
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
				boss->img = upgrade_main_image(boss, (i + 1), j);
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
t_data	collect(t_main_struct *boss)
{
	if (boss->win.player_look == 0)
		boss->img = put_floor(boss,
				(boss->win.player_y - 1), (boss->win.player_x));
	if (boss->win.player_look == 1)
		boss->img = put_floor(boss,
				(boss->win.player_y + 1), (boss->win.player_x));
	if (boss->win.player_look == 2)
		boss->img = put_floor(boss,
				(boss->win.player_y), (boss->win.player_x - 1));
	if (boss->win.player_look == 3)
		boss->img = put_floor(boss,
				(boss->win.player_y), (boss->win.player_x + 1));
	return (boss->img);
}
