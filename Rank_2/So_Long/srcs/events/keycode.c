/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:39:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/07 01:31:25 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	my_close(t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit(0);
	return (0);
}
int	keycode_int(int keycode)
{
	return (keycode);
}

int	keycode_decisions(int keycode, t_win *win)
{
	int		i;

	i = -1;
	while (win->mapa[++i])
		ft_printf("%s\n", win->mapa[i]);
	if (keycode == 100)
		mov_right(win);
	if (keycode == 97)
		mov_left(win);
	if (keycode == 119)
		mov_up(win);
	if (keycode == 115)
		mov_down(win);
	if (keycode == 65307)
		my_close(win);
	ft_printf("keycode -> %i\n", keycode);
	mlx_loop(win->mlx);
	return (0);
}
