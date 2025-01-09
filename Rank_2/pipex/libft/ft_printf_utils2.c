/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:14:43 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/01/03 16:14:43 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Prints a string to the standard output.
 *
 * This function takes a pointer to a null-terminated string as input and prints
 * its characters to the standard output. If the input string is NULL, it prints
 * the string "(null)".
 *
 * @param s A pointer to the null-terminated string to be printed.
 * @return The total number of characters printed, excluding the null
 * terminator. In the case of a NULL string, it returns the number of characters
 * in the "(null)" string.
 */
int	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return (write (1, "(null)", 6));
	i = -1;
	while (s[++i] != '\0')
		write (1, &s[i], 1);
	return (i);
}

int	ft_printargs(char **s)
{
	size_t	i;
	size_t	cont;

	if (!s)
		return (write (1, "(null)", 6));
	cont = -1;
	i = 0;
	while (s[++cont])
	{
		i += ft_putstr(s[cont]);
		i += write (1, " ", 1);
	}
	return (i);
}

int	ft_printargsn(char **s)
{
	size_t	i;
	size_t	cont;

	if (!s)
		return (write (1, "(null)", 6));
	cont = -1;
	i = 0;
	while (s[++cont])
	{
		i += ft_putstr(s[cont]);
		i += write (1, "\n", 1);
	}
	return (i);
}

int	ft_printargsc(char **s)
{
	size_t	i;
	size_t	cont;

	if (!s)
		return (write (1, "(null)", 6));
	cont = -1;
	i = 0;
	while (s[++cont])
	{
		i += write (1, "\"", 1);
		i += ft_putstr(s[cont]);
		i += write (1, "\"", 1);
		i += write (1, " ", 1);
	}
	return (i);
}

int	ft_printargscn(char **s)
{
	size_t	i;
	size_t	cont;

	if (!s)
		return (write (1, "(NULL)", 6));
	cont = -1;
	i = 0;
	while (s[++cont])
	{
		i += write (1, "\"", 1);
		i += ft_putstr(s[cont]);
		i += write (1, "\"", 1);
		i += write (1, "\n", 1);
	}
	return (i);
}
