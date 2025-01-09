/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:26:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:10:57 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==============================================================\
|	  HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER LOOK	|
\==============================================================*/

/**
 * @brief Determine the appropriate image to use based on the player_look
 *  variable.
 *
 * This function decides which image to send based on the value of the
 *  player_look variable.
 * The values of player_look correspond to the player's direction:
 *   - 0: down
 *   - 1: up
 *   - 2: left
 *   - 3: right
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the chosen image.
 */
void	*player_image2(t_win *win)
{
	void	*img_player;

	if (win->player_look == 0)
		img_player = look_up(win);
	else if (win->player_look == 1)
		img_player = look_down(win);
	else if (win->player_look == 2)
		img_player = look_left(win);
	else
		img_player = look_right(win);
	return (img_player);
}
