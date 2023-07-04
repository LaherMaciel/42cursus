/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vals_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:15:06 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 19:35:49 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Initialize map names array
 * 
 * @param mapNames Pointer to the map names array
*/
void	initialize_map_names(char ***mapNames)
{
	*mapNames = (char **)malloc(10 * sizeof(char *));
	(*mapNames)[0] = strdup("Map 1");
	(*mapNames)[1] = strdup("Map 2");
	(*mapNames)[2] = strdup("Map 3");
	(*mapNames)[3] = strdup("Map 4");
	(*mapNames)[4] = strdup("Map 5");
	(*mapNames)[5] = strdup("Map 6");
	(*mapNames)[6] = strdup("Map 7");
	(*mapNames)[7] = strdup("Map 8");
	(*mapNames)[8] = strdup("Map 9");
	(*mapNames)[9] = NULL;
}

/**
 * @brief Initialize 'extras' struct values
 * 
 * @param extras The 'extras' struct to be initialized
 * @return The initialized 'extras' struct
*/
t_extras	extras_vals_init(t_extras extras)
{
	initialize_map_names(&extras.map_names);
	return (extras);
}

/**
 * @brief Initialize 'img' struct values
 * 
 * @param img The 'img' struct to be initialized
 * @return The initialized 'img' struct
*/
t_data	img_vals_init(t_data img)
{
	img.main_image = NULL;
	return (img);
}

/**
 * @brief Initialize 'win' struct values
 * 
 * @param win The 'win' struct to be initialized
 * @return The initialized 'win' struct
 */
t_win	win_vals_init(t_win win)
{
	win.collect = 0;
	win.collected = 0;
	win.collectibles = 0;
	win.player_walk = 0;
	win.image_heigth = 64;
	win.image_length = 64;
	win.mlx = NULL;
	win.mlx_win = NULL;
	return (win);
}
