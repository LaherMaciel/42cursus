/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:30:31 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:12:12 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==========================================================\
|			HERE WILL DEAL WITH THE IMAGE OF FLOOR			|
\==========================================================*/

/**
 * @brief Fills the main image with the floor image.
 *
 * @param boss The main structure containing game resources.
 * @return t_data The modified main image data structure.
*/
t_data	floor_on_main_image_full2(t_main_struct *boss)
{
	int	i;
	int	j;

	i = 0;
	boss->aux.current_image = floor_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("FUCKING FLOOR IMAGE READING ERROR!!!", boss);
	while (boss->win.mapa[i])
	{
		j = 0;
		while (boss->win.mapa[i][j])
			boss->img = upgrade_main_image2(boss, (i + 1), ++j);
		i++;
	}
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}
/* 
 * @brief Retrieve the address of the floor image.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the floor image.
 *
static void	*floor_image(t_win *win)
{
	void	*img_floor;

	img_floor = mlx_xpm_file_to_image(win->mlx,
			"images/utils/floor4.xpm", &win->image_length,
			&win->image_heigth);
	return (img_floor);
}
 */

/**
 * @brief This function retrieves the floor image using the floor_image()
 * function and assigns it to the current auxiliary image in the boss structure.
 * It then calls the upgrade_main_image() function to place the floor image on
 * the main image. Finally, it destroys (like freeing the memory) the floor
 * image and returns the modified main image.
 *
 * @param boss Pointer to the main structure.
 * @param i The current row index.
 * @param j The current column index.
 * @return t_data The modified main image data structure.
*/
t_data	put_floor2(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = floor_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("Floor Image Not Created", boss);
	boss->img = upgrade_main_image2(boss, (i + 1), (j + 1));
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}
