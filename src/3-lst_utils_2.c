/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-lst_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:39:26 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/29 08:05:51 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *stack)
{
	if (!stack)
		return (0);
	return (lstsize(stack->next) + 1);
}

int	find_content(t_stack *stack, int position)
{
	t_stack	*node;

	node = stack;
	while (position-- > 0)
		node = node->next;
	return (node->content);
}

int	find_position(t_stack *stack, int to_find)
{
	int		count;
	int		position;
	t_stack	*temp;

	position = -1;
	count = 0;
	temp = stack;
	while (temp)
	{
		if (temp->content == to_find)
			position = count;
		temp = temp->next;
		count++;
	}
	return (position);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	have_duplicates(t_stack *stack)
{
	t_stack	*search_stack;
	t_stack	*check_stack;

	search_stack = stack;
	while (search_stack)
	{
		check_stack = search_stack->next;
		while (check_stack)
		{
			if (search_stack->content == check_stack->content)
				return (1);
			check_stack = check_stack->next;
		}
		search_stack = search_stack->next;
	}
	return (0);
}
