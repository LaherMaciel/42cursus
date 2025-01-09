/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:06:08 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:09:57 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==============================================================\
|	HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER WALKING	|
\==============================================================*/

/**
 * @brief Upgrade the player image.
 *
 * This function upgrades the player image based on the given player position.
 * It first checks if it's the initial upgrade (i = 0) and loads the initial
 * player image. Then, it upgrades the main game image to include the player at
 * the specified position. Finally, it destroys the current player image to free
 * up memory.
 *
 * @param boss The main game structure.
 * @param i The upgrade index.
 * @return t_data The updated game image.
*/
t_data	upgrade_player2(t_main_struct *boss, int i)
{
	if (i == 0)
	{
		boss->aux.current_image = floor_image(&boss->win);
		if (!boss->aux.current_image)
			error_call("Player Image Not Created", boss);
		boss->img = upgrade_player2(boss, 1);
		boss->aux.current_image = player_image2(&boss->win);
		if (!boss->aux.current_image)
			error_call("Player Image Not Created", boss);
	}
	boss->img = upgrade_main_image2(boss, (boss->win.player_y + 1),
			(boss->win.player_x + 1));
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}
