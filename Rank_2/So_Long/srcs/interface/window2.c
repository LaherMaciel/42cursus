/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:36:13 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/25 18:13:26 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fresh_start(t_main_struct *boss)
{
	window_destroy(boss);
	boss->img = img_vals_init(boss->img);
	boss->win = win_vals_init(boss->win);
}

/**
 * @brief 
 * 
 * @param boss 
 * @param filename 
 */
void	new_window(t_main_struct *boss)
{
	int	i;
	int	n;

	i = -1;
	n = boss->win.new_map;
	fresh_start(boss);
	while (boss->extras.map_names[++i])
		ft_printf("\n%s\n", boss->extras.map_names[i]);
	boss->win.current_map = n;
	ft_printf("current_map -> %i\nMap name -> %s\n", boss->win.current_map,
		boss->extras.map_names[boss->win.current_map]);
	ft_printf("argc -> %i\n", boss->aux.argc_size);
	boss->win.mapa = creat_map(boss,
			boss->extras.map_names[boss->win.current_map]);
	boss->win = validate_map(boss, boss->win,
			boss->extras.map_names[boss->win.current_map]);
	boss->win = window_init(boss, boss->win);
	boss->img = start_image(boss);
	ft_printf("MAPA 2 READY\n");
	mlx_hook(boss->win.mlx_win, 2, 1L << 0, keycode_decisions, boss);
	boss->img = upgrade_player(boss, 0);
	mlx_hook(boss->win.mlx_win, 17, 1L, end_game, &boss);
	mlx_loop(boss->win.mlx);
}
