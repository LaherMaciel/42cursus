/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proxy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:55:49 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/27 13:56:51 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* char	*proxy_cut2(void)
{
	char	*commands;
	ssize_t	ret;

	commands = (char *)ft_calloc(1000000, sizeof(char));
	if (commands == NULL)
		return (NULL);
	ret = read(0, commands, 1000000);
	if (ret == -1)
	{
		free(commands);
		return (NULL);
	}
	if (ret == 0)
	{
		free(commands);
		return ("  ");
	}
	return (commands);
}
 */
char	**proxy_cut(char commands[])
{
	char	**vals;

	vals = the_split(commands);
	if (!vals)
		return (NULL);
	return (vals);
}

// if the user introduz the numbers and the commands or just numbers | main
void	proxy(t_stack **stack_a, t_stack **stack_b, int i)
{
	char	*commands;
	char	**vals;

	vals = NULL;
	commands = get_next_line(0);
	if (commands == NULL)
		return ;
	while (commands != NULL && ft_strncmp(commands, "  ", 2))
	{
		vals = proxy_cut(commands);
		if (!vals)
			return ;
		while (vals[++i] != NULL)
		{
			if (commands_check(vals[i]) == 1)
				return (0);
			if (user_sort(stack_a, stack_b, vals[i]) == 0)
			{
				while (vals[i])
					free(vals[i++]);
				return ;
			}
			free(vals[i]);
		}
		while (vals[i])
			free(vals[i++]);
		free(vals);
		free(commands);
		commands = get_next_line(0);
	}
	end_code(stack_a, stack_b, commands);
}
