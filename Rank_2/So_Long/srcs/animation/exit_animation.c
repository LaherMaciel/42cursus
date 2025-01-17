/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:25:57 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:12:40 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Retrieve the address of the exit image.
 *
 * The image file used is determined based on the value of the `exit` variable.
 * If `exit` is non-zero, it loads the "exit0.xpm" image file. Otherwise, it
 * also loads the "exit1.xpm" image file.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the exit image.
 */
void	*exit_image(t_win *win)
{
	void	*img_exit;

	if (win->exit != 1)
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"images/utils/exit1.xpm", &win->image_length,
				&win->image_heigth);
	else
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"images/utils/exit1.xpm", &win->image_length,
				&win->image_heigth);
	return (img_exit);
}

/**
 * @brief This function retrieves the exit image using the exit_image() function
 * and assigns it to the current auxiliary image in the boss structure. It then
 * calls the upgrade_main_image() function to place the exit image on the main
 * image Finally, it destroys (like freeing the memory) the exit image and
 * returns the modified main image.
 *
 * @param boss
 * @param i
 * @param j
 * @return t_data
 */
t_data	put_exit(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = exit_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("Exit Image Not Created", boss);
	boss->img = upgrade_main_image(boss, (i + 1), (j + 1));
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
t_data	pass_exit(t_main_struct *boss)
{
	if (boss->win.player_look == 0)
		boss->img = put_exit(boss,
				(boss->win.player_y), (boss->win.player_x));
	if (boss->win.player_look == 1)
		boss->img = put_exit(boss,
				(boss->win.player_y), (boss->win.player_x));
	if (boss->win.player_look == 2)
		boss->img = put_exit(boss,
				(boss->win.player_y), (boss->win.player_x));
	if (boss->win.player_look == 3)
		boss->img = put_exit(boss,
				(boss->win.player_y), (boss->win.player_x));
	return (boss->img);
}
