/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:30:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:25:46 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Put walls on the game window.
 *
 * This function is called as an auxiliary function to put walls on the game
 * window. It iterates over the specified coordinates (i, j) and draws walls on
 * the window using the appropriate image. The image is adjusted based on the
 * current position and size of the window.
 *
 * @param boss The main game structure.
 * @param i The row index of the wall.
 * @param j The column index of the wall.
 * @return t_data The updated game data.
*/
t_data	put_walls_aux2(t_main_struct *boss, int i, int j)
{
	int	stop_x;
	int	stop_y;

	stop_y = i * 64;
	stop_x = j * 64;
	boss->aux.y = stop_y - (boss->win.image_heigth + 1);
	boss->aux.x = stop_x - (boss->win.image_length + 1);
	mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win,
		boss->aux.current_image, boss->aux.x, boss->aux.y);
	return (boss->img);
}

/**
 * @brief This function retrieves the wall image using the wall_image()
 * function and assigns it to the current auxiliary image in the boss
 * structure. It then calls the put_walls_aux() function to
 * place the wall image on the main image. Finally, it destroys (like freeing the
 * memory) the wall image and returns the modified main image.
 *
 * @param boss Pointer to the main structure.
 * @param i The current row index.
 * @param j The current column index.
 * @return t_data The modified main image data structure.
*/
t_data	put_wall2(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = wall_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("Wall Image Not Created", boss);
	boss->img = put_walls_aux2(boss, (i + 1), (j + 1));
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}
