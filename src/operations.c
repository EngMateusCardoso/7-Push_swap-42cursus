/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:11:51 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/24 04:36:18 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data *data, const char *op)
{
	t_stack *temp;

	if (op[1] == 'a' || op[1] == 's')
	{
		temp = data->stack_a->next->next;
		data->stack_a->next->next = data->stack_a;
		data->stack_a = data->stack_a->next;
		data->stack_a->next->next = temp;
	}
	if (op[1] == 'b' || op[1] == 's')
	{
		temp = data->stack_b->next->next;
		data->stack_b->next->next = data->stack_b;
		data->stack_b = data->stack_b->next;
		data->stack_b->next->next = temp;
	}
}

void	push(t_data *data, const char *op)
{
	t_stack *temp;

	if (op[1] == 'a')
	{
		temp = data->stack_a;
		data->stack_a = data->stack_b;
		data->stack_b = data->stack_b->next;
		data->stack_a->next = temp;
	}
	else if (op[1] == 'b')
	{
		temp = data->stack_b;
		data->stack_b = data->stack_a;
		data->stack_a = data->stack_a->next;
		data->stack_b->next = temp;
	}
}

void	rotate(t_data *data, const char *op)
{
	t_stack *temp;

	if (op[1] == 'a' || op[1] == 'r')
	{
		temp = data->stack_a->next;
		data->stack_a->next = NULL;
		lstadd_back(&temp, data->stack_a);
		data->stack_a = temp;
		
	}
	if (op[1] == 'b' || op[1] == 'r')
	{
		temp = data->stack_b->next;
		data->stack_b->next = NULL;
		lstadd_back(&temp, data->stack_b);
		data->stack_b = temp;
	}
}

void	reverse_rotate(t_data *data, const char *op)
{
	t_stack *temp;

	if (op[2] == 'a' || op[2] == 'r')
	{
		temp = lstlast(data->stack_a);
		lstlastbutone(data->stack_a)->next = NULL;
		temp->next = data->stack_a;
		data->stack_a = temp;
		
	}
	if (op[2] == 'b' || op[2] == 'r')
	{
		temp = lstlast(data->stack_b);
		lstlastbutone(data->stack_b)->next = NULL;
		temp->next = data->stack_b;
		data->stack_b = temp;
	}
}

void	stack_operation(t_data *data, char *op)
{
	if (op[0] == 's')
		swap(data, op);
	else if (op[0] == 'p')
		push(data, op);
	else if (op[0] == 'r' && ft_strlen(op) == 2)
		rotate(data, op);
	else if (op[0] == 'r' && op[1] == 'r' && ft_strlen(op) == 3)
		reverse_rotate(data, op);
	ft_putstr_fd(op, 1);
	ft_putchar_fd('\n',1);
}
