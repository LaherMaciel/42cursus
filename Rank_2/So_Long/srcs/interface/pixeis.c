/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixeis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:55:44 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 00:15:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==============================================================\
|	  HERE WILL DEAL WITH THE FUNCTIONS THAT FOCES IN PIXEIS	|
\==============================================================*/

/**
 * @brief Set a color value at a specific pixel location in the image.
 *
 * This function sets a color value at the {x, y} coordinates of the image
 * specified by the `data` parameter. It calculates the memory address of the
 * pixel using the image data's address, line length, and bits per pixel. Then,
 * it assigns the color value to that pixel. The `color` parameter represents
 * the color to be set. No return value.
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
 * @brief Retrieve the color value at a specific pixel location in the current image.
 *
 * This function finds the memory address of the pixel at the {x, y} coordinates of the
 * current image, as specified by the `aux` parameter. It calculates the address using
 * the current image's address, line length, and bits per pixel. Then, it retrieves the
 * color value stored at that pixel and returns it. The function returns an unsigned integer
 * representing the color value.
 *
 * @param aux Pointer to the auxiliary values structure.
 * @param x X-coordinate of the pixel in the auxiliary image.
 * @param y Y-coordinate of the pixel in the auxiliary image.
 * @return unsigned int Color value at the specified pixel location.
 */
int	get_pixel(t_aux_vales *aux)
{
	char	*dst;

	dst = aux->address + (aux->current_image_y * aux->line_length + aux->current_image_x * (aux->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
