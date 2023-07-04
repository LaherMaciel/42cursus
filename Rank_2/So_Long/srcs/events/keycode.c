/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:39:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 21:41:16 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Handles the keypress events and performs corresponding actions.
 *
 * @param keycode The keycode of the pressed key.
 * @param win The window structure.
 * @return 0
 */
int	keycode_decisions(int keycode, t_main_struct *boss)
{
	ft_printf(CLEAR);
	if (keycode == 100 || keycode == 65363)
		mov_right(boss, &boss->win);
	if (keycode == 97 || keycode == 65361)
		mov_left(boss, &boss->win);
	if (keycode == 119 || keycode == 65362)
		mov_up(boss, &boss->win);
	if (keycode == 115 || keycode == 65364)
		mov_down(boss, &boss->win);
	if (keycode == 65307 || boss->win.new_map == boss->aux.argc_size)
		end_game(boss, 0);
	if (boss->win.new_map != boss->win.current_map)
		new_window(boss);
	my_prints(boss);
	if (boss->win.collectibles == boss->win.collected)
		boss->win.exit = 2;
	return (0);
}
