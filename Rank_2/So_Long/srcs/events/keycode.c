/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:39:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/25 19:38:48 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Closes the window and terminates the program.
 *
 * @param win The window structure to be closed.
 * @return 0
 */

int	keycode_int(int keycode)
{
	return (keycode);
}

void	my_prints(int keycode, t_main_struct *boss)
{
	int		i;

	i = -1;
	ft_printf("\nKEYCODE	%i\nargc -> %i\n", keycode, boss->aux.argc_size);
	ft_printf("boss->win.new_map -> %i\n", boss->win.new_map);
	ft_printf("boss->win.current_map -> %i\n\n", boss->win.current_map);
	ft_printf("boss->win.collectibles -> %i\n", boss->win.collectibles);
	ft_printf("boss->win.collected -> %i\n", boss->win.collected);
	ft_printf("exit -> %i\n", boss->win.exit);
	//ft_printf(CLEAR"keycode -> %i\n", keycode);
	while (boss->win.mapa[++i])
		ft_printf("%s\n", boss->win.mapa[i]);
}

/**
 * @brief Handles the keypress events and performs corresponding actions.
 *
 * @param keycode The keycode of the pressed key.
 * @param win The window structure.
 * @return 0
 */
int	keycode_decisions(int keycode, t_main_struct *boss)
{
	if (keycode == 100 || keycode == 65363)
		mov_right(boss, &boss->win);
	if (keycode == 97 || keycode == 65361)
		mov_left(boss, &boss->win);
	if (keycode == 119 || keycode == 65362)
		mov_up(boss, &boss->win);
	if (keycode == 115 || keycode == 65364)
		mov_down(boss, &boss->win);
	if (keycode == 65307 || boss->win.new_map == boss->aux.argc_size)
		end_game(boss);
	if (boss->win.new_map != boss->win.current_map)
		new_window(boss);
	my_prints(keycode, boss);
	if (boss->win.collectibles == boss->win.collected)
		boss->win.exit = 2;
	//boss->img = upgrade_collectibles(boss);
	mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win,
		boss->img.main_image, 0, 0);
	return (0);
}
