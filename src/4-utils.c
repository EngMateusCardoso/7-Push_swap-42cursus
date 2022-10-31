/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:52:44 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/30 14:44:35 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*to_sort_stack(t_stack *stack)
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

void	*convert_int(const char *nptr, int *target)
{
	unsigned long int	result;
	short int			sign;

	if (ft_strlen(nptr) > 11)
		return (NULL);
	sign = 1;
	result = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	if (*nptr == '\0')
		return (NULL);
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - 48);
	if (*nptr || result > 2147483648 || (sign == 1 && result == 2147483648))
		return (NULL);
	else
		*target = result * sign;
	return (target);
}

void	exit_error(t_data *data)
{
	if (data->stack_a)
		free_stack(&(data->stack_a));
	if (data->stack_b)
		free_stack(&(data->stack_b));
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}
