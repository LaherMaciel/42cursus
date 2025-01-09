/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:01:16 by lwencesl          #+#    #+#             */
/*   Updated: 2023/01/03 17:08:27 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchr(char s)
{
	return (write (1, &s, 1));
}

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

/**
 * @brief Recursively converts a double precision floating-point number to a
 * custom base representation and prints it.
 *
 * This function handles both positive and negative numbers. It recursively
 * divides the input double precision floating-point number (`nbr`) by the
 * specified base size (`size`) and prints the corresponding character from
 * the custom base (`base`). It also handles negative numbers by printing
 * a '-' sign if the input number is less than 0. The result is printed to
 * the standard output.
 *
 * @attention This function should be reviewd and improved. And maybe merged
 * with the `putpointer()` function. Like if the `size` is bigger then 16 then it
 * handles it as a pointer and do all the pointer formatation and if not works
 * as normally
 * 
 * @param nbr   The double precision floating-point number to be converted.
 * @param base  The character array representing the custom base.
 * @param size  The size of the custom base.
 *
 * @return The total number of characters printed.
 */
int	ft_putnbr(double nbr, char *base, double size)
{
	int	cont;

	cont = 0;
	if (nbr < 0)
	{
		cont += write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= size)
		cont += ft_putnbr(nbr / size, base, size);
	cont += write (1, &base[((unsigned long) nbr) % ((unsigned long) size)], 1);
	return (cont);
}

/**
 * @brief Recursively converts an unsigned long long number to hexadecimal
 * representation and prints it. Handles both "regular" hexadecimal values and
 * pointers. Mainly used to print pointers.
 *
 * This function converts the input unsigned long long number (`nbr`) to
 * hexadecimal representation using the specified custom base (`base`) and size.
 * If the size is not 16, it is adjusted to 16 to handle pointers, and a '0x'
 * prefix is printed for formatting. If the input number is zero, "(nil)" is
 * printed for pointer representation. The result is printed to the standard
 * output.
 *
 * @attention This function should be reviewd and improved.
 * 
 * @param nbr   The unsigned long long number to be converted to hexadecimal.
 * @param base  The character array representing the hexadecimal base.
 * @param size  The size of the hexadecimal base.
 *
 * @return The total number of characters printed.
 */
int	putpoint(unsigned long long nbr, char *base, unsigned long long size)
{
	int	cont;

	cont = 0;
	if (size != 16)
	{
		if (!nbr)
			return (write(1, "(nil)", 5));
		size = 16;
		write (1, "0x", 2);
		cont = 2;
	}
	if (nbr >= size)
		cont += putpoint(nbr / size, base, size);
	cont += write (1, &base[(nbr) % (size)], 1);
	return (cont);
}
