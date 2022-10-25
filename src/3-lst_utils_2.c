/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-lst_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:39:26 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/25 20:36:57 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack	*stack)
{
	if (!stack)
		return (0);
	return (lstsize(stack->next) + 1);
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

void	copy_stack(t_stack *src, t_stack **dst)
{
	t_stack	*temp_stack;
	t_stack	*new;
	t_stack	*target;	

	target = lstnew(src->content);
	temp_stack = src->next;
	while (temp_stack)
	{
		new = lstnew(temp_stack->content);
		lstadd_back(&target, new);
		temp_stack = temp_stack->next;
	}
	*dst = target;
}

t_stack	*selection_sort_stack(t_stack *stack)
{
	t_stack	*temp_stack_1;
	t_stack	*temp_stack_2;
	t_stack	*sort_stack;
	t_stack	*min_node;
	int		temp;

	copy_stack(stack, &sort_stack);
	temp_stack_1 = sort_stack;
	while (temp_stack_1)
	{
		min_node = temp_stack_1;
		temp_stack_2 = temp_stack_1->next;
		while (temp_stack_2)
		{
			if (temp_stack_2->content < min_node->content)
				min_node = temp_stack_2;
			temp_stack_2 = temp_stack_2->next;
		}
		temp = temp_stack_1->content;
		temp_stack_1->content = min_node->content;
		min_node->content = temp;
		temp_stack_1 = temp_stack_1->next;
	}
	return (sort_stack);
}
