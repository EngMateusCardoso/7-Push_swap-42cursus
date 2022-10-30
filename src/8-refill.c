/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8-refill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:16:49 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/30 00:54:18 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb_needed_refill(t_stack *stack, int number)
{
	int		count;
	t_stack	*check;

	if (!stack)
		return (-1);
	count = 0;
	check = stack;
	while (check)
	{
		if (check->content == number)
			break ;
		count++;
		check = check->next;
	}
	return (count);
}

int	rrb_needed_refill(t_stack *stack, int number)
{
	int		count;
	int		last;
	t_stack	*check;

	count = 0;
	last = lstsize(stack) + 1;
	check = stack;
	while (check)
	{
		if (check->content == number)
			last = count;
		count++;
		check = check->next;
	}
	return (lstsize(stack) - last);
}

void	refill(t_data *data)
{
	int	max_num;
	int	rb_mvs;
	int	rrb_mvs;

	max_num = data->size;
	max_num--;
	while (max_num > 0)
	{
		rb_mvs = rb_needed_refill(data->stack_b, max_num);
		rrb_mvs = rrb_needed_refill(data->stack_b, max_num);
		if (rb_mvs <= rrb_mvs)
			stack_operations(data, "rb", rb_mvs);
		else
			stack_operations(data, "rrb", rrb_mvs);
		stack_operations(data, "pa", 1);
		max_num--;
	}
	stack_operations(data, "pa", 1);
}
