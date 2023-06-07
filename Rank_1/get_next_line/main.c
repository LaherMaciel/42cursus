/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:16:56 by lwencesl          #+#    #+#             */
/*   Updated: 2023/01/21 19:49:12 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	int		fds;
	char	*a;
	int		cont;

	cont = 1;
	fds = open("test.txt", O_RDONLY);
	printf("\n");
	while ((a = get_next_line(fds)) != NULL)
	{
		printf("%i - %s", cont, a);
		free(a);
		cont++;
	}
	printf("\n\n");
	return (0);
}
