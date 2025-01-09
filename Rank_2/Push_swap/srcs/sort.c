/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:36:32 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/15 17:36:35 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Performs a single sorting operation based on the provided identifier.
 *
 * @param stack_a A pointer to the head of the first stack (t_stack structure).
 * @param stack_b A pointer to the head of the second stack (t_stack structure).
 * @param id_1 The identifier specifying the sorting operation to be performed.
 */
void	sorting(t_stack **stack_a, t_stack **stack_b, char *id_1)
{
	if (ft_strncmp(id_1, "pa", 2) == 0)
		ft_pass_to(stack_b, stack_a, 'a');
	else if (ft_strncmp(id_1, "pb", 2) == 0)
		ft_pass_to(stack_a, stack_b, 'b');
	else if (ft_strncmp(id_1, "ss", 2) == 0)
		ft_swap_swap(stack_a, stack_b);
	else if (ft_strncmp(id_1, "sa", 2) == 0)
		ft_swap(stack_a, 'a');
	else if (ft_strncmp(id_1, "sb", 2) == 0)
		ft_swap(stack_a, 'b');
	else if (ft_strncmp(id_1, "ra", 2) == 0)
		ft_rotate(stack_a, 'a');
	else if (ft_strncmp(id_1, "rb", 2) == 0)
		ft_rotate(stack_b, 'b');
	else if (ft_strncmp(id_1, "rra", 3) == 0)
		ft_reverse_rotate(stack_a, 'a');
	else if (ft_strncmp(id_1, "rrb", 3) == 0)
		ft_reverse_rotate(stack_b, 'b');
	else if (ft_strncmp(id_1, "rrr", 3) == 0)
		ft_reverse_rotate_rotate(stack_a, stack_b);
	else if (ft_strncmp(id_1, "rr", 2) == 0)
		ft_rotate_rotate(stack_a, stack_b);
}

/**
 * @brief Sorts a stack by choosing the best operation.
 *
 * This function sorts a stack by selecting the best operation based on the
 * current state of the stacks.
 *
 * @param stack_a A pointer to the head of the first stack (t_stack structure).
 * @param stack_b A pointer to the head of the second stack (t_stack structure).
 */
void	sort_p(t_stack **stack_a, t_stack **stack_b)
{
	int		pb[4];
	char	*id;

	if (*stack_a == NULL)
		return ;
	pb[0] = INT_MAX;
	best_stack_pa_mov(*stack_b, *stack_a, pb);
	id = p_decisions(*stack_b, *stack_a, pb[1], pb[2]);
	sorting(stack_a, stack_b, id);
}

/**
 * @brief Implements a simplified sorting method for small stacks.
 *
 * This function implements a simplified sorting method by determining the
 * sorting method based on the size of stack_a and performing the corresponding
 * sorting operations.
 *
 * @param stack_a A pointer to the head of the first stack (t_stack structure).
 * @param stack_b A pointer to the head of the second stack (t_stack structure).
 * @param sa_ord A flag indicating whether stack_a is ordered or not (0 or 1).
 * @param method The sorting method to be used.
 */
void	sort_cut(t_stack **stack_a, t_stack **stack_b, int *sa_ord)
{
	int	nr;

	nr = 0;
	if (check_order_ok(*stack_a) == 0 && *stack_b != NULL && *sa_ord == 0)
		*sa_ord = 1;
	else if (ft_lstsize_rem(*stack_a) <= 3 && *sa_ord == 0)
	{
		sort_s_3(stack_a, 'a');
		*sa_ord = 1;
	}
	else if (*sa_ord == 0)
	{
		nr = find_above_quart_media_reverse(*stack_a, 0, 0);
		if (nr > 0)
			ft_reverse_rotate(stack_a, 'a');
		else if (nr < 0)
			ft_rotate(stack_a, 'a');
		else
			sort_cut2(stack_a, stack_b);
	}
}

/**
 * @brief   Sorts the given stack (stack_a). The function utilizes various
 *  helper functions for sorting, such as `simulation()`, `sort_cut()`,
 *  `sort_p()`, etc. `Simulation()` is used to determine the best sorting
 *  method, `sort_cut()` is employed to transfer values from stack_a to stack_b
 *  using the optimal method, and `sort_p()` is responsible for moving values
 *  back from stack_b to stack_a with the aim of minimizing the total number of
 *  movements.
 *
 * @param   stack_a     Pointer to the stack to be sorted.
 * @param   stack_b     Pointer to an auxiliary stack (not used in this
 * function).
 */
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	sa_ord;
	int	done;

	done = 0;
	sa_ord = 0;
	if (ft_lstsize_rem(*stack_a) == 2)
	{
		ft_swap(stack_a, 'a');
		return ;
	}
	while (*stack_b != NULL || (done == 0 && check_order_ok(*stack_a) != 0))
	{
		sort_cut(stack_a, stack_b, &sa_ord);
		if (sa_ord != 0 && *stack_b != NULL)
		{
			sort_p(stack_a, stack_b);
			done = 1;
		}
	}
}
