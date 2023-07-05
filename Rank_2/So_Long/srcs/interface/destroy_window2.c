/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:14:44 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/05 00:00:22 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Handles an error, prints an error message, and terminates the
 * program.
 * This function prints an error message with the provided string using
 * ft_printf(). It then calls the print_map() function to display the
 * current game map. Finally, it calls the end_game() function with an
 * error code of 1 to terminate the program.
 *
 * @param str The error message string.
 * @param boss The main structure containing game resources.
 * @return void
 */
void	error_call(char *str, t_main_struct *boss)
{
	ft_printf(RED"ERROR: "DEFAULT_COLOR"%s"RED"!!\n"DEFAULT_COLOR, str);
	if (boss->win.mapa)
	{
		ft_printf("\n");
		print_map(boss);
		ft_printf("\n");
	}
	end_game(boss, 1);
}
