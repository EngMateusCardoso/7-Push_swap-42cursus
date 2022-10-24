/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:47:33 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/24 02:42:12 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (data->stack_a->content == 1)
		stack_operation(data, "sa");
}

void	sort_three(t_data *data)
{
	if (data->stack_a->content < data->stack_a->next->next->content
		&& data->stack_a->next->next->content < data->stack_a->next->content)
	{
		stack_operation(data, "rra");
		stack_operation(data, "sa");
	}
	if (data->stack_a->next->content < data->stack_a->content
		&& data->stack_a->content < data->stack_a->next->next->content)
		stack_operation(data, "sa");
	if (data->stack_a->next->next->content < data->stack_a->content
		&& data->stack_a->content < data->stack_a->next->content)
		stack_operation(data, "rra");
	if (data->stack_a->next->content < data->stack_a->next->next->content
		&& data->stack_a->next->next->content < data->stack_a->content)
		stack_operation(data, "ra");
	if (data->stack_a->next->next->content < data->stack_a->next->content
		&& data->stack_a->next->next->content < data->stack_a->content)
	{
		stack_operation(data, "ra");
		stack_operation(data, "sa");
	}
}

int	is_shorted(t_stack *stack)
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
		stack_operation(data, "ra");
	else if (data->stack_a->next->next->content == less_content_stack_a)
	{
		stack_operation(data, "ra");
		stack_operation(data, "ra");
	}
	else if (data->stack_a->next->next->next->content == less_content_stack_a)
		stack_operation(data, "rra");
	if (!is_shorted(data->stack_a))
	{
		stack_operation(data, "pb");
		sort_three(data);
		stack_operation(data, "pa");
	}
}

void	sort_five(t_data *data)
{
	if (data->stack_a->next->content == 0)
		stack_operation(data, "ra");
	else if (data->stack_a->next->next->content == 0)
	{
		stack_operation(data, "ra");
		stack_operation(data, "ra");
	}
	else if (data->stack_a->next->next->next->content == 0)
	{
		stack_operation(data, "rra");
		stack_operation(data, "rra");
	}
	else if (data->stack_a->next->next->next->next->content == 0)
		stack_operation(data, "rra");
	if (!is_shorted(data->stack_a))
	{
		stack_operation(data, "pb");
		sort_four(data, 1);
		stack_operation(data, "pa");
	}
}
