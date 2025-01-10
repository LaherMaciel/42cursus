/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:11:03 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/01/10 22:23:55 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief function used to end the program if something happens
 * @param error -1 to print a error message used to write errors -2 to simple
 *  messages to STDERR_FILENO 1 to write a normal message to STDOUT 0 to run the
 *  functions without printing any message, basically end the code without any
 *  errors.
 * @param message message to print
 * @param piper struct with all the programs basic or main info
 */
void	exit_pipex(int error, char *message)
{
	int	out;

	out = 1;
	if (error == -1)
		ft_fdprintf(STDERR_FILENO, RED"%s"DEFAULT_COLOR": %s\n",
			message, strerror(errno));
	if (error == -2)
		ft_fdprintf(STDERR_FILENO, "%s\n", message);
	if (error == -3)
		ft_fdprintf(STDERR_FILENO, "pipex: %s: %s\n",
			strerror(errno), message);
	if (error == -4)
		ft_fdprintf(STDERR_FILENO,
			"pipex: command not found: %s\n", message);
	if (error == 1)
		ft_printf("%s\n", message);
	if (error == 0 || error == 1)
		out = 0;
	exit(out);
}

void	printfile(int fd, char *filename)
{
	char	*a;
	int		in;

	a = "hello";
	in = 0;
	ft_printf("\nPrinting the file (%s):\n", filename);
	while (a != NULL)
	{
		if (a && in == 1)
			free(a);
		a = get_next_line(fd);
		if (a)
			ft_printf("%s", a);
		if (in == 0)
			in = 1;
	}
	ft_printf("\n\n");
}
