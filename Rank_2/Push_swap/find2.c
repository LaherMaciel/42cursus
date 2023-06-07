/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:34:41 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/18 11:42:09 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return the val in the position 'pos'
int	find_val(t_stack *head, int pos)
{
	t_stack	*current;
	int		cont;

	if (head == NULL)
		return (0);
	if (pos < 0)
		pos = pos * (-1);
	else if (pos > 0)
		pos = ft_lstsize(head) - pos;
	cont = 0;
	current = head;
	while (cont < pos)
	{
		current = current->next;
		cont++;
	}
	return (current->content);
}

int	find_media(t_stack *stack)
{
	t_stack	*current;
	int		val;
	int		cont;

	if (stack == NULL)
		return (0);
	current = stack;
	val = 0;
	cont = 0;
	while (current)
	{
		val += current->content;
		current = current->next;
		cont++;
	}
	return ((val / cont) + (val / (cont * 2)));
}

// Corre até encontrar o 1 numero a cima da media, conta
// primeiro do topo até a mmetade, e depois do final até a metade.
int	find_above_media(t_stack *stack, int cont1, int cont2)
{
	t_stack	*current;
	int		media;

	media = find_media(stack);
	current = stack;
	while (cont1 > (-ft_lstsize(stack) / 2))
	{
		if (find_val(stack, cont1) <= media)
			break ;
		current = current->next;
		cont1--;
	}
	while (cont2 < (ft_lstsize(stack) / 2))
	{
		if (find_val(stack, cont2) <= media)
			break ;
		current = current->next;
		cont2++;
	}
	if ((cont1 * (-1)) <= cont2)
		return (cont1);
	else if ((cont1 * (-1)) > cont2)
		return (cont2);
	return (0);
}
