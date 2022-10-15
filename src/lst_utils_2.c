/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:39:05 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/15 22:46:20 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack(t_stack *src, t_stack **dts)
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
	*dts = target;
}

t_stack *sort_numbers(t_stack *stack)
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
