/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixeis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:55:44 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 21:28:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==============================================================\
|	  HERE WILL DEAL WITH THE FUNCTIONS THAT FOCES IN PIXEIS	|
\==============================================================*/

/**
 * @brief This function sets a color value at the {x, y} coordinates of the image
 * specified by the `data` parameter. It calculates the memory address of the
 * pixel using the image data's address, line length, and bits per pixel. Then,
 * it assigns the color value to that pixel. The `color` parameter represents
 * the color to be set.
 *
 * @param data Pointer to the image data structure.
 * @param x X-coordinate of the pixel.
 * @param y Y-coordinate of the pixel.
 * @param color Color value to be set.
 */
void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief This function retrieves the color of a pixel in the auxiliary image
 * based on the current image coordinates. It calculates the memory address
 * of the pixel using the line length, bits per pixel, and the current image
 * coordinates. The color value is then extracted from the memory address and
 * returned as an unsigned integer.
 * 
 * @param aux Pointer to the auxiliary values structure.
 * @return int The color value of the pixel.
*/
int	get_pixel(t_aux_vales *aux)
{
	char	*dst;

	dst = aux->address + (aux->current_image_y * aux->line_length
			+ aux->current_image_x * (aux->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

/**
 * @brief This function retrieves the color of a pixel in the auxiliary image by
 * obtaining the memory address of the pixel using the mlx_get_data_addr()
 * function. It then calls the get_pixel() function to extract the color
 * value from the memory address.
 * 
 * @param aux Pointer to the auxiliary values structure.
*/
void	get_color_of_aux_image(t_aux_vales *aux)
{
	aux->address = mlx_get_data_addr(aux->current_image,
			&aux->bits_per_pixel, &aux->line_length, &aux->endian);
	aux->color = get_pixel(aux);
}
