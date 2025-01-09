/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:08:52 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/05 19:40:26 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// ss -> sa and sb at the same time.
void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	ft_swap(stack_a);
	ft_swap(stack_b);
}

// rr -> ra and rb at the same time
void	ft_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr\n");
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

// rrr -> rra and rrb at the same time.
void	ft_reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr\n");
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
