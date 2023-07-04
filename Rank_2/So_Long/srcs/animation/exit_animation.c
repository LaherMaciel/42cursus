/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:25:57 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 21:26:46 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Retrieve the address of the exit image.
 *
 * The image file used is determined based on the value of the `exit`
 * variable. If `exit` is non-zero, it loads the "exit0.xpm" image file.
 * Otherwise, it also loads the "exit1.xpm" image file.
 *
 * @param win A pointer to the window structure.
 * @return void* The address of the exit image.
 */
void	*exit_image(t_win *win)
{
	void	*img_exit;

	if (win->exit != 1)
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"images/utils/exit1.xpm", &win->image_length,
				&win->image_heigth);
	else
		img_exit = mlx_xpm_file_to_image(win->mlx,
				"images/utils/exit1.xpm", &win->image_length,
				&win->image_heigth);
	return (img_exit);
}

/**
 * @brief This function retrieves the exit image using the exit_image() function
 * and assigns it to the current auxiliary image in the boss structure. It then
 * calls the upgrade_main_image() function to place the exit image on the main
 * image Finally, it destroys (like freeing the memory) the exit image and
 * returns the modified main image.
 * 
 * @param boss 
 * @param i 
 * @param j 
 * @return t_data 
 */
t_data	put_exit(t_main_struct *boss, int i, int j)
{
	boss->aux.current_image = exit_image(&boss->win);
	if (!boss->aux.current_image)
		error_call("Exit Image Not Created", boss);
	boss->img = upgrade_main_image(boss, (i + 1), (j + 1));
	mlx_destroy_image(boss->win.mlx, boss->aux.current_image);
	return (boss->img);
}
