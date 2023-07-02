/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:14:44 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/01 22:51:31 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_call(char *str, t_main_struct *boss)
{
	ft_printf("\033[1;31mERROR:\033[0m %s\033[1;31m!!\033[0m\n\n", str);
	print_map(boss);
	end_game(boss, 1);
}
