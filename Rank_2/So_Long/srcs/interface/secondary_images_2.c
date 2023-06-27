/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_images_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/27 20:26:57 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Get the color of the auxiliary image at a given position.
 *
 * This function retrieves the color of the auxiliary image at the specified
 *  position (x, y).
 * The auxiliary image is represented by the `current_image` field of the
 *  `aux` structure.
 * It uses the `mlx_get_data_addr` function to get the address of the image
 *  data and store it
 * in the `address` field of the `aux` structure. It also retrieves the bits
 *  per pixel,
 * line length, and endianness information and stores them in the
 *  corresponding fields.
 * The function then calls the `get_pixel` function to get the color of the
 *  pixel at the given
 * position, which is stored in the `color` field of the `aux` structure.
 *
 * @param aux A pointer to the auxiliary values structure.
 */
void	get_color_of_aux_image(t_aux_vales *aux)
{
	aux->address = mlx_get_data_addr(aux->current_image,
			&aux->bits_per_pixel, &aux->line_length, &aux->endian);
	aux->color = get_pixel(aux);
}

/**
 * @brief
 *
 * if color == 555555 make it 7F555555
 *
 * @param boss
 * @param i
 * @param j
 * @return t_data
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

t_data	put_floor(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = floor_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("Floor Image Not Created", boss);
	boss->img = upgrade_main_image(boss, (i + 1), (j + 1));
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}

t_data	put_exit(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = exit_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("Exit Image Not Created", boss);
	boss->img = upgrade_main_image(boss, (i + 1), (j + 1));
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}
