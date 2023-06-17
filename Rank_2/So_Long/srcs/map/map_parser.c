/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:59:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 04:02:15 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*=============================================


==============================================*/

t_win	creat_mapa(t_main_struct *boss)
{
	t_win	win;

	win.mapa = creat_map_mod();
	//win.mapa = creat_map();
	if (win.mapa == NULL)
		error_call("Mapa Not Created", boss);
	map_base_check(boss, &win);
	win.mapa_length = ft_strlen(win.mapa[0]);
	return (win);
}
