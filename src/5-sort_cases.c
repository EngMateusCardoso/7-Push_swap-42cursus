/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-sort_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:47:33 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/26 03:00:46 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (data->stack_a->content == 1)
		stack_operations(data, "sa", 1);
}

void	sort_three(t_data *data)
{
	if (data->stack_a->content < data->stack_a->next->next->content
		&& data->stack_a->next->next->content < data->stack_a->next->content)
	{
		stack_operations(data, "rra", 1);
		stack_operations(data, "sa", 1);
	}
	if (data->stack_a->next->content < data->stack_a->content
		&& data->stack_a->content < data->stack_a->next->next->content)
		stack_operations(data, "sa", 1);
	if (data->stack_a->next->next->content < data->stack_a->content
		&& data->stack_a->content < data->stack_a->next->content)
		stack_operations(data, "rra", 1);
	if (data->stack_a->next->content < data->stack_a->next->next->content
		&& data->stack_a->next->next->content < data->stack_a->content)
		stack_operations(data, "ra", 1);
	if (data->stack_a->next->next->content < data->stack_a->next->content
		&& data->stack_a->next->next->content < data->stack_a->content)
	{
		stack_operations(data, "ra", 1);
		stack_operations(data, "sa", 1);
	}
}

int	is_sorted(t_stack *stack)
{
	int		i;
	t_stack	*check_stack;

	check_stack = stack;
	i = 0;
	while (check_stack)
	{
		if (check_stack->content != i)
			return (0);
		i++;
		check_stack = check_stack->next;
	}
	return (1);
}

void	sort_four(t_data *data, int less_content_stack_a)
{
	if (data->stack_a->next->content == less_content_stack_a)
		stack_operations(data, "ra", 1);
	else if (data->stack_a->next->next->content == less_content_stack_a)
		stack_operations(data, "ra", 2);
	else if (data->stack_a->next->next->next->content == less_content_stack_a)
		stack_operations(data, "rra", 1);
	if (!is_sorted(data->stack_a))
	{
		stack_operations(data, "pb", 1);
		sort_three(data);
		stack_operations(data, "pa", 1);
	}
}

void	sort_five(t_data *data)
{
	if (data->stack_a->next->content == 0)
		stack_operations(data, "ra", 1);
	else if (data->stack_a->next->next->content == 0)
		stack_operations(data, "ra", 2);
	else if (data->stack_a->next->next->next->content == 0)
		stack_operations(data, "rra", 2);
	else if (data->stack_a->next->next->next->next->content == 0)
		stack_operations(data, "rra", 1);
	if (!is_sorted(data->stack_a))
	{
		stack_operations(data, "pb", 1);
		sort_four(data, 1);
		stack_operations(data, "pa", 1);
	}
}
