/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:36 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 01:05:31 by lwencesl         ###   ########.fr       */
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

typedef struct s_data{
	void	*main_image;
	char	*addr;
	int		line_length;
	int		endian;
	int		bits_per_pixel;
	int		ok;
}				t_data;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	char	**mapa;
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
	void			*img_collectibles;
	void			*img_exit;
	void			*img_floor;
	void			*img_player;
	void			*img_wall;
	void			*current_image;
	int				current_image_x;
	int				current_image_y;
	int				x;
	int				y;
	int				ignx0;
	int				ignx1;
	int				igny0;
	int				igny1;

}		t_aux_vales;

typedef struct s_extras
{
	int		boss_x;
	int		boss_y;
	int		boss_walk;
	int		boss_look;
	int		boss_zone;
	int		boss_slash;
	int		boss_health;
	int		boss_changes;
	int		summon1_x;
	int		summon2_x;
	int		summon3_x;
	int		summon1_y;
	int		summon2_y;
	int		summon3_y;
	int		summon1_helth;
	int		summon2_helth;
	int		summon3_helth;
	int		enemy_x;
	int		enemy_y;
	int		enemy_attack;
	float	enemy_attack_delay;
	float	enemy_attack_delay2;
	int		enemy_attack_damage;
	int		enemy_attack_damage2;
	int		enemy_attack_direction;
	int		enemy_attack_number_of_blocks_moved;
	int		enemy_attack_number_of_blocks_moved2;
	int		teleport;
	int		last_attack;
	int		player_health;
}		t_extras;

typedef struct s_main_struct
{
	t_data			img;
	t_win			win;
	t_aux_vales 	aux;
	t_extras		extras;
}				t_main_struct;

//ANIMATIONS
void	*collectibles_image_animation(t_win *win);
t_data	upgrade_collectibles(t_main_struct *boss);
t_data	upgrade_player(t_main_struct *boss, int i);
t_data	upgrade_main_image(t_main_struct *boss, int i, int j);

//EVENTS
int		keycode_decisions(int keycode, t_main_struct *boss);
int		my_close(t_main_struct *boss);
void	mov_left(t_main_struct *boss, t_win *win);
void	mov_right(t_main_struct *boss, t_win *win);
void	mov_up(t_main_struct *boss, t_win *win);
void	mov_down(t_main_struct *boss, t_win *win);
int		mouse_handler(int mousekey, int x, int y, t_win *win);

//MAP
t_win	creat_mapa(t_main_struct *boss);
t_win	creat_map_mod(t_main_struct *boss, t_win win);
t_win	creat_map(t_main_struct *boss, t_win win);
char	**read_file(void);
t_win	map_base_check(t_main_struct *boss, t_win win);
t_win	validate_map(t_main_struct *boss, t_win win);

//WINDOWS
t_win			window_init(t_win win);
int				window_destroy(t_main_struct *boss);
void			error_call(char *str, t_main_struct *boss);

//MAIN IMAGE
t_data			start_image(t_main_struct *boss);
t_data			create_main_image(t_main_struct *boss);
int				ignore_x(t_main_struct *boss, int i);
int				ignore_y(t_main_struct *boss, int i);
int				include_y(t_main_struct *boss, int i);
int				include_x(t_main_struct *boss, int i);
//void			*choose_aux_image(t_main_struct *boss);
t_data			choose_aux_image(t_main_struct *boss);


//SECONDARY IMAGE
void			*wall_image(t_win *win);
void			*player_image(t_win *win);
void			*floor_image(t_win *win);
void			*collectibles_image(t_win *win);
void			*exit_image(t_win *win);
void			get_color_of_aux_image(t_aux_vales *aux);
t_data			put_wall(t_main_struct *boss, int i, int j);
t_data			put_floor(t_main_struct *boss, int i, int j);
t_data			put_exit(t_main_struct *boss, int i, int j);

//ANIMATIONS
void			*walk_up(t_win *win);
void			*walk_down(t_win *win);
void			*walk_left(t_win *win);
void			*walk_right(t_win *win);
void			*look_up(t_win *win);
void			*look_down(t_win *win);
void			*look_left(t_win *win);
void			*look_right(t_win *win);
t_data			collect(t_main_struct *boss);
t_data			put_walls_aux(t_main_struct *boss, int i, int j);

// PIXEIS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_pixel(t_aux_vales *aux);
int		aux_get_pixel(t_aux_vales *aux, int x, int y);

//OTHERS
t_aux_vales	aux_imgs_init(t_aux_vales aux);
t_win	win_vals_init(t_win win);

#endif // !SO_LONG_H
