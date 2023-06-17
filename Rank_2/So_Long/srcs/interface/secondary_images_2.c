/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_images_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/16 23:16:13 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Get the color of the auxiliary image at a given position.
 *
 * This function retrieves the color of the auxiliary image at the specified position (x, y).
 * The auxiliary image is represented by the `current_image` field of the `aux` structure.
 * It uses the `mlx_get_data_addr` function to get the address of the image data and store it
 * in the `address` field of the `aux` structure. It also retrieves the bits per pixel,
 * line length, and endianness information and stores them in the corresponding fields.
 * The function then calls the `get_pixel` function to get the color of the pixel at the given
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
