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

#include "libft.h"

int	readfile(int fds)
{
	char	*a;
	int		cont;

	cont = 1;
	//printf("\n");
	while ((a = get_next_line(fds)) != NULL)
	{
		ft_printf("%i - %s", cont, a);
		free(a);
		cont++;
	}
	ft_printf("\n");
	return (cont);
}

int	main(void)
{
	int	fds;
	int	count;

	fds = open("test.txt", O_RDWR);
	if (fds <= 0)
		return (-1);
	count = readfile(fds);
	if (count > 0)
	{
		ft_fdprintf(fds, "\n%i lines were read!\n", count);
		ft_fdprintf(1, "\n%i lines were read!\n", count);
	}
	close(fds);
	return (0);
}
