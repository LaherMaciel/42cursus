/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:39:14 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/01/19 16:40:52 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strstr(char **strstr)
{
	int	i;

	i = -1;
	if (strstr)
	{
		while (strstr[++i])
			free(strstr[i]);
		free(strstr);
	}
}
