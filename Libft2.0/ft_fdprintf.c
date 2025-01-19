/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:39:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/01/03 17:26:05 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * I'm declaring this functions here unstad of doing on that `ft_printf.h` to
 * prevent me of seeing them when calling the `ft_printf()` on another project
*/

int	ft_fdputstr(int fd, char *s);
int	ft_fdputchr(int fd, char s);
int	ft_fdputnbr(int fd, double nbr, char *base, double size);
int	fdputhexa(int fd, double nbr, char *base, double size);
int	fdputpoint(int fd, unsigned long long nbr,
		char *base, unsigned long long size);

/**
 * @brief Auxiliary function for formatting and printing data based on a format
 * specifier.
 *
 * This function is responsible for handling various format specifiers and
 * printing corresponding data types. It uses a variable argument list (va_list)
 * to access the arguments passed to the variadic function `ft_printf`.
 *
 * @param format The format specifier character determining the type of data to
 * be printed.
 * @param args   A variable argument list containing the actual data to be
 * printed.
 *
 * @return The total number of characters printed, or 0 if the format specifier
 * is invalid.
 */
int	ft_fdprintaux(int fd, const char format, va_list args)
{
	if (!format)
		return (-1);
	if (format == 'c')
		return (ft_fdputchr(fd, va_arg(args, int)));
	if (format == 's')
		return (ft_fdputstr(fd, va_arg(args, char *)));
	if (format == 'i' || format == 'd')
		return (ft_fdputnbr(fd, va_arg(args, int), "0123456789", 10));
	if (format == 'u')
		return (ft_fdputnbr(fd, va_arg(args, unsigned int), "0123456789", 10));
	if (format == 'X')
		return (ft_fdputnbr(fd, va_arg(args,
					unsigned int), "0123456789ABCDEF", 16));
	if (format == 'x')
		return (ft_fdputnbr(fd,
				va_arg(args, unsigned int), "0123456789abcdef", 16));
	if (format == 'p')
		return (fdputpoint(fd, va_arg(args, unsigned long long), \
			"0123456789abcdef", 1));
	return (0);
}

/**
 * @brief Custom printf implementation that supports basic format specifiers.
 *
 * This function mimics the behavior of the standard printf function by
 * processing a format string and printing formatted output to the standard
 * output. It supports format specifiers denoted by '%' and can handle
 * characters ('c'), strings ('s'), integers ('i' or 'd'), unsigned integers
 * ('u'), hexadecimal numbers in uppercase ('X') and lowercase ('x') formats,
 * and pointers ('p').
 *
 * @param format A null-terminated format string containing text and format
 * specifiers.
 * @param ...    Variable arguments corresponding to the format specifiers in
 * the format string.
 *
 * @return The total number of characters printed, excluding the null
 * terminator.
 */
int	ft_fdprintf(int fd, const char *format, ...)
{
	size_t	i;
	size_t	cont;
	va_list	args;

	if (!format)
		return (0);
	i = 0;
	cont = -1;
	va_start(args, format);
	while (format[++cont])
	{
		if (format[cont] == '%')
		{
			if (format[cont + 1] != '%')
				i += ft_fdprintaux(fd, format[cont + 1], args);
			else
				i += write(fd, &format[cont], 1);
			cont++;
		}
		else
			i += write(fd, &format[cont], 1);
	}
	va_end(args);
	return (i);
}
