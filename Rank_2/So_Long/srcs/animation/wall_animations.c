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
 * @brief Retrieve the address of the wall image.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the wall image.
 */
void	*wall_image(t_win *win)
{
	void	*img_wall;

	img_wall = mlx_xpm_file_to_image(win->mlx,
			"images/utils/floor2.xpm", &win->image_length,
			&win->image_heigth);
	return (img_wall);
}

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
t_data	put_walls_aux(t_main_struct *boss, int i, int j)
{
	int	stop_x;
	int	stop_y;

	stop_y = i * 64;
	boss->aux.y = stop_y - (boss->win.image_heigth + 1);
	boss->aux.current_image_y = 0;
	stop_y = correct_y(boss, stop_y);
	while (++boss->aux.y <= stop_y
		&& boss->aux.y <= boss->win.heigth_size)
	{
		boss->aux.current_image_x = 0;
		stop_x = j * 64;
		boss->aux.x = stop_x - (boss->win.image_length + 1);
		stop_x = correct_x(boss, stop_x);
		while (++boss->aux.x <= stop_x && boss->aux.x <= boss->win.length_size)
		{
			get_color_of_aux_image(&boss->aux);
			if (boss->aux.color && boss->aux.color != 4278190080)
				my_mlx_pixel_put(&boss->img,
					boss->aux.x, boss->aux.y, boss->aux.color);
			boss->aux.current_image_x++;
		}
		boss->aux.current_image_y++;
	}
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
t_data	put_wall(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = wall_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("Wall Image Not Created", boss);
	boss->img = put_walls_aux(boss, (i + 1), (j + 1));
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}
