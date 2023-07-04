/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:14:44 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 16:19:04 by lwencesl         ###   ########.fr       */
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
	ft_printf("\033[1;31mERROR:\033[0m %s\033[1;31m!!\033[0m\n\n", str);
	print_map(boss);
	end_game(boss, 1);
}
