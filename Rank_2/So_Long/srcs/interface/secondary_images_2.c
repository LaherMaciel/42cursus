/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_images_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/15 21:32:19 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Get the color of aux image.
 *
 * @param boss boss as a pointer.
 * @param aux aux as a pointer.
 * @param x the x of this image.
 * @param y the y of this image.
 * @return int
 */
void	get_color_of_aux_image(t_aux_vales *aux)
{
	aux->address = mlx_get_data_addr(aux->current_image,
			&aux->bits_per_pixel, &aux->line_length, &aux->endian);
	aux->color = get_pixel(aux, aux->current_image_x, aux->current_image_y);
}
