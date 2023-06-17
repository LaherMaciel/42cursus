/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vals_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:15:06 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 03:19:01 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_aux_vales	aux_imgs_init(t_aux_vales aux)
{
	aux.img_wall = NULL;
	aux.img_player = NULL;
	aux.img_collectibles = NULL;
	aux.img_exit = NULL;
	aux.img_floor = NULL;
	aux.current_image = NULL;
	aux.address = NULL;
	return (aux);
}
