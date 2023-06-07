/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attacks_directions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:29:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/07 04:13:56 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	attack_direction_cut(t_win *win, t_extras *extra, int aux_x, int aux_y)
{
	if (aux_x * (-1) > 0 && aux_y * (-1) > 0)
	{
		if (aux_x < aux_y)
			extra->enemy_attack_direction = 2;
		else
			extra->enemy_attack_direction = 1;
	}
	else if (aux_x * (-1) > 0 && aux_y > 0)
	{
		if (aux_x *(-1) < aux_y)
			extra->enemy_attack_direction = 2;
		else
			extra->enemy_attack_direction = 0;
	}
	else
	{
		if (aux_x < aux_y *(-1))
			extra->enemy_attack_direction = 3;
		else
			extra->enemy_attack_direction = 1;
	}
}

void	attack_direction(t_win *win, t_extras *extra)
{
	// up -> 0 : down -> 1 : left -> 2 : right -> 3
	int	i;
	int	aux_x;
	int	aux_y;

	i = -1;
	aux_x = (win->player_x - extra->enemy_x);
	aux_y = (win->player_y - extra->enemy_y);
	if (aux_x >= 0 && aux_y >= 0)
	{
		if (aux_x < aux_y)
			extra->enemy_attack_direction = 3;
		else
			extra->enemy_attack_direction = 0;
	}
	else
		attack_direction_cut(win, extra, aux_x, aux_y);
}

