/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secundary_images_adjusts.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:24:19 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:25:59 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Correct the x-coordinate for drawing walls.
 *
 * This function adjusts the x-coordinate for drawing walls on the game window.
 * It takes into account any ignored pixels and includes additional pixels to
 * ensure proper alignment and positioning of the walls.
 *
 * @param boss The main game structure.
 * @param stop_x The original x-coordinate.
 * @return int The corrected x-coordinate.
*/
int	correct_x(t_main_struct *boss, int stop_x)
{
	boss->aux.x = boss->aux.x + ignore_x(boss, 0);
	boss->aux.x = boss->aux.x + (include_x(boss, 0) / 2);
	stop_x = stop_x + ignore_x(boss, 0);
	stop_x = stop_x - (include_x(boss, 0) / 2);
	if (boss->aux.x < -1)
	{
		boss->aux.current_image_x = boss->aux.current_image_x
			+ (boss->aux.x * (-1));
		boss->aux.x = -1;
	}
	return (stop_x);
}

/**
 * @brief Correct the y-coordinate for drawing walls.
 *
 * This function adjusts the y-coordinate for drawing walls on the game window.
 * It takes into account any ignored pixels and includes additional pixels to
 * ensure proper alignment and positioning of the walls.
 *
 * @param boss The main game structure.
 * @param stop_y The original y-coordinate.
 * @return int The corrected y-coordinate.
*/
int	correct_y(t_main_struct *boss, int stop_y)
{
	boss->aux.y = boss->aux.y + ignore_y(boss, 0);
	boss->aux.y = boss->aux.y + (include_y(boss, 0) / 2);
	stop_y = stop_y + ignore_y(boss, 0);
	stop_y = stop_y - (include_y(boss, 0) / 2);
	if (boss->aux.y < -1)
	{
		boss->aux.current_image_y = boss->aux.current_image_y
			+ (boss->aux.y * (-1));
		boss->aux.y = -1;
	}
	return (stop_y);
}
