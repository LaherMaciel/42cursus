/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_sizeof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:06:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/24 15:09:50 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_my_sizeof(const void *ptr)
{
	const char	*char_ptr;
	size_t		size;

	char_ptr = (const char *)ptr;
	size = 0;
	while (char_ptr[size])
		size++;
	return (size);
}
