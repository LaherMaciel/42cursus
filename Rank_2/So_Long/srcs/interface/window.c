/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/15 21:17:43 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*=============================================
include the 'mlx.h' on your '.h' project file
mlx_init() -> used to inicialize the library. It returns a (void *)
mlx_new_window(pointer_returned_by_mlx_init(),
	width, heigth, "the_name_of_the_window") -> used to initialize a window.
	return the (void *) to the new window created.
mlx_new_image() ->
mlx_loop() -> initiate the window rendering.
==============================================*/

/**
 * @brief Initilize the window where the game will be located.
 *      the size is set by the number of coloms and rows of the map and the size
 *      of the secondary images.
 *
 *	Its called by the function window_start(t_main_struct boss) in this file.
 *
 * @param win
 * @return t_win
 */
t_win	window_init(t_win win)
{
	win.length_size = ft_strlen(win.mapa[0]);
	win.heigth_size = 0;
	while (win.mapa[win.heigth_size])
		win.heigth_size++;
	win.length_size = win.length_size * win.image_length;
	win.heigth_size = win.heigth_size * win.image_heigth;
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, win.length_size, win.heigth_size, "so_long");
	ft_printf("WINDOOW CREATED\n");
	return (win);
}

/**
 * @brief destroy the window created and free the map, and end the code.
 *
 * @param win
 * @return int
 */
int	window_destroy(t_win *win)
{
	int	i;

	i = -1;
	mlx_destroy_window(win->mlx, win->mlx_win);
	mlx_destroy_display(win->mlx);
	while (win->mapa[++i])
		free(win->mapa[i]);
	free(win->mapa);
	free(win->mlx);
	exit(0);
}

/**
 * @brief Function to decide the size of the window.
 *	Its called by the function window_start(t_main_struct boss) in this file.
 *
 * @param win
 * @return t_aux_vales aux
 */
t_aux_vales	win_start_aux(t_win win)
{
	t_aux_vales	aux;

	aux.current_image = floor_image(&win);
	aux.address = mlx_get_data_addr(aux.current_image, &aux.bits_per_pixel, &aux.line_length,
		&aux.endian);
	return (aux);
}

/**
 * @brief creat the map, initialize the window, put
 * the first image on the window.
 *	Its called by the main fucntion;
 *
 *	Call's the function win_start_aux(boss.win), window_init(boss. win) in this
 *  file;
 *	Call's the function player_image(&boss.win) on the file
 *	Call's the function create_main_image(&boss, player_image(&boss.win)) in the
 * file main_image.c
 *
 * minilibx functions: mlx_new_image(), mlx_get_data_addr();
 *
 * @param win
 */
void	window_start(t_main_struct boss)
{
	int	i;

	boss.win.mapa = creat_map_mod();
	//boss.win.mapa = creat_map();
	if (boss.win.mapa == NULL)
		return ;
	if (map_base_check(boss.win) == 0)
	{
		ft_printf("ERROR\n");
		return ;
	}
	ft_printf("%s\n\n", boss.win.mapa[0]);
	boss.win = window_init(boss. win);
	//boss.aux = win_start_aux(boss.win);
	boss.img.main_image = mlx_new_image(boss.win.mlx, boss.win.image_length, boss.win.image_heigth);
	boss.img.addr = mlx_get_data_addr(boss.img.main_image, &boss.img.bits_per_pixel, &boss.img.line_length,
								&boss.img.endian);
	create_main_image(&boss, player_image(&boss.win));
	mlx_hook(boss.win.mlx_win, 2, 1L<<0, keycode_decisions, &boss);
	mlx_hook(boss.win.mlx_win, 17, 1L, window_destroy, &boss);
	boss.win.mapa = boss.win.mapa;
	mlx_loop(boss.win.mlx);
	ft_printf("img: %p\n", boss.img);
	i = -1;
	while (boss.win.mapa[++i])
		free(boss.win.mapa[i]);
	free(boss.win.mapa);
}

