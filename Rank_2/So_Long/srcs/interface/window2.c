/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:36:13 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/03 21:33:53 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_movs_on_window(t_main_struct *boss)
{
	char	*message;
	char	*tmp;
	char	*vals;

	vals = ft_itoa(boss->aux.numb_of_mov);
	message = ft_strjoin("Movements: ", vals);
	free(vals);
	tmp = message;
	message = ft_strjoin(tmp, "; ");
	free(tmp);
	mlx_string_put(boss->win.mlx, boss->win.mlx_win,
		10, 20,
		0x00FFFFFF, message);
	free(message);
	ft_printf("\nMovements: %i;\n", boss->aux.numb_of_mov);
	ft_printf("Total Movements: %i;\n", boss->aux.total_mov);
}

void	put_collectibles_on_window(t_main_struct *boss)
{
	char	*message;
	char	*tmp;
	char	*vals;

	vals = ft_itoa(boss->win.collected);
	message = ft_strjoin("Collectibles: ", vals);
	free(vals);
	tmp = message;
	message = ft_strjoin(tmp, " / ");
	free(tmp);
	tmp = message;
	vals = ft_itoa(boss->win.collectibles);
	message = ft_strjoin(tmp, vals);
	free(vals);
	free(tmp);
	tmp = message;
	message = ft_strjoin(tmp, "; ");
	free(tmp);
	mlx_string_put(boss->win.mlx, boss->win.mlx_win,
		10, 40, 0x00FFFFFF, message);
	free(message);
	ft_printf("Collectibles: %i / %i;\n", boss->win.collected,
		boss->win.collectibles);
}

void	put_total_collected_on_window(t_main_struct *boss)
{
	char	*message;
	char	*tmp;
	char	*vals;

	vals = ft_itoa(boss->win.total_collected);
	message = ft_strjoin("Total Collected: ", vals);
	free(vals);
	tmp = message;
	message = ft_strjoin(tmp, "; ");
	free(tmp);
	mlx_string_put(boss->win.mlx, boss->win.mlx_win, 10,
		60, 0x00FFFFFF, message);
	free(message);
	ft_printf("Total collected: %i;\n", boss->win.total_collected);
}

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
	int	n;

	n = boss->win.new_map;
	fresh_start(boss);
	boss->win.current_map = n;
	boss->win.mapa = creat_map(boss,
			boss->extras.map_names[boss->win.current_map]);
	boss->win = validate_map(boss, boss->win,
			boss->extras.map_names[boss->win.current_map]);
	boss->win = window_init(boss, boss->win);
	boss->img = start_image(boss);
	ft_printf(CLEAR"MAPA %i READY\n", (boss->win.current_map + 1));
	my_prints(boss);
	mlx_hook(boss->win.mlx_win, 2, 1L << 0, keycode_decisions, boss);
	boss->img = upgrade_player(boss, 0);
	mlx_hook(boss->win.mlx_win, 17, 1L, end_game, &boss);
	mlx_loop(boss->win.mlx);
}
