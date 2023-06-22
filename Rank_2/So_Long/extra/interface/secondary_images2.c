/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_images2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:38:56 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/22 23:39:50 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_data	put_wall_42(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = wall_image_42(&boss->win);
	boss->img = put_walls_aux(boss, (i + 1), (j + 1));
	return (boss->img);
}

t_data	put_floor_42(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = floor_image_42(&boss->win);
	boss->img = upgrade_main_image(boss, (i + 1), (j + 1));
	return (boss->img);
}

t_data	put_exit_42(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = exit_image_42(&boss->win);
	boss->img = upgrade_main_image(boss, (i + 1), (j + 1));
	return (boss->img);
}

