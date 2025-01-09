/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:36:32 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/05 19:44:32 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sorting(t_stack **stack_a, t_stack **stack_b, char *id_1)
{
	if (ft_strncmp(id_1, "pa", 2) == 0)
		ft_pass_to(stack_b, stack_a);
	else if (ft_strncmp(id_1, "pb", 2) == 0)
		ft_pass_to(stack_a, stack_b);
	else if (ft_strncmp(id_1, "ss", 2) == 0)
		ft_swap_swap(stack_a, stack_b);
	else if (ft_strncmp(id_1, "sa", 2) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(id_1, "sb", 2) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(id_1, "ra", 2) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(id_1, "rb", 2) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(id_1, "rra", 3) == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strncmp(id_1, "rrb", 3) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strncmp(id_1, "rrr", 3) == 0)
		ft_reverse_rotate_rotate(stack_a, stack_b);
	else if (ft_strncmp(id_1, "rr", 2) == 0)
		ft_rotate_rotate(stack_a, stack_b);
}
