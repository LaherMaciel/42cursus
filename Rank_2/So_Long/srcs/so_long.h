/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:36 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:34:01 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

// COLOR CODES
# define CLEAR "\033c"

typedef struct s_data{
	void	*main_image;
	char	*addr;
	int		line_length;
	int		endian;
	int		bits_per_pixel;
}				t_data;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	char	**mapa;
	char	*map_name;
	int		current_map;
	int		new_map;
	int		mapa_length;
	int		mapa_heigth;
	int		length_size;
	int		heigth_size;
	int		image_length;
	int		image_heigth;
	int		colors;
	int		player_x;
	int		player_y;
	int		player_walk;
	int		player_look;
	int		collectibles;
	int		collected;
	int		total_collected;
	int		collect;
	int		exit;
	int		i;
	int		j;
}		t_win;

typedef struct S_aux_vales
{
	unsigned int	color;
	char			*address;
	int				line_length;
	int				endian;
	int				bits_per_pixel;
	void			*current_image;
	int				current_image_x;
	int				current_image_y;
	int				x;
	int				y;
	int				argc_size;
	int				numb_of_mov;
	int				total_mov;
}		t_aux_vales;

typedef struct s_extras
{
	char	**map_names;
	int		current_map;
}		t_extras;

typedef struct s_main_struct
{
	t_data			img;
	t_win			win;
	t_aux_vales		aux;
	t_extras		extras;
}				t_main_struct;

//ANIMATIONS
void		*player_image(t_win *win);
void		*wall_image(t_win *win);
void		*exit_image(t_win *win);
void		*floor_image(t_win *win);
void		*collectibles_image(t_win *win);
void		*collectibles_image_animation(t_win *win);
t_data		upgrade_collectibles(t_main_struct *boss);
t_data		upgrade_player(t_main_struct *boss, int i);
t_data		put_floor(t_main_struct *boss, int i, int j);
t_data		put_wall(t_main_struct *boss, int i, int j);
t_data		put_exit(t_main_struct *boss, int i, int j);
t_data		floor_on_main_image_full(t_main_struct *boss);

//EVENTS
int			keycode_decisions(int keycode, t_main_struct *boss);
int			my_close(t_main_struct *boss);
void		mov_left(t_main_struct *boss, t_win *win);
void		mov_right(t_main_struct *boss, t_win *win);
void		mov_up(t_main_struct *boss, t_win *win);
void		mov_down(t_main_struct *boss, t_win *win);
int			mouse_handler(int mousekey, int x, int y, t_win *win);
void		my_prints(t_main_struct *boss);

//MAP
t_win		creat_mapa(t_main_struct *boss);
char		**creat_map_mod(t_main_struct *boss);
char		**creat_map(t_main_struct *boss, char *file_name);
char		**read_file(void);
t_win		map_base_check(t_main_struct *boss, t_win win);
int			map_check2(t_main_struct *boss, t_win win, char *filename);
t_win		validate_map(t_main_struct *boss, t_win win, char *filename);
t_win		read_map(t_main_struct *boss, char *argv[]);
char		**flood_fill(char **test_map, int y, int x, int exit);
void		map_last_base_check(t_main_struct*boss, t_win win);
void		print_map(t_main_struct *boss);

//WINDOWS
t_win		window_init(t_main_struct *boss, t_win win);
void		destroy_aux_struct(t_aux_vales *aux);
int			end_game(t_main_struct *boss, int error);
void		window_destroy(t_main_struct *boss);
void		error_call(char *str, t_main_struct *boss);
void		new_window(t_main_struct *boss);
void		put_collectibles_on_window(t_main_struct *boss);
void		put_total_collected_on_window(t_main_struct *boss);
void		put_movs_on_window(t_main_struct *boss);

//MAIN IMAGE
t_data		start_image(t_main_struct *boss);
t_data		create_main_image(t_main_struct *boss);
t_data		choose_aux_image(t_main_struct *boss);
t_data		upgrade_main_image(t_main_struct *boss, int i, int j);

//SECONDARY IMAGE
int			correct_x(t_main_struct *boss, int stop_x);
int			include_x(t_main_struct *boss, int i);
int			ignore_x(t_main_struct *boss, int i);
int			correct_y(t_main_struct *boss, int stop_y);
int			include_y(t_main_struct *boss, int i);
int			ignore_y(t_main_struct *boss, int i);

//ANIMATIONS
void		*walk_up(t_win *win);
void		*walk_down(t_win *win);
void		*walk_left(t_win *win);
void		*walk_right(t_win *win);
void		*look_up(t_win *win);
void		*look_down(t_win *win);
void		*look_left(t_win *win);
void		*look_right(t_win *win);
t_data		collect(t_main_struct *boss);
t_data		put_walls_aux(t_main_struct *boss, int i, int j);

// PIXEIS
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			get_pixel(t_aux_vales *aux);
int			aux_get_pixel(t_aux_vales *aux, int x, int y);
void		get_color_of_aux_image(t_aux_vales *aux);

//OTHERS
t_data		img_vals_init(t_data img);
t_win		win_vals_init(t_win win);
t_extras	extras_vals_init(t_extras extras);

#endif // !SO_LONG_H
