/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-big_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 06:57:21 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/25 20:38:26 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_for_pb(t_data *data, int n_moves, char *type_rotate)
{
	while (n_moves)
	{
		stack_operation(data, type_rotate);
		n_moves--;
	}
	stack_operation(data, "pb");
}

int	ra_needed(t_stack *stack, int min, int max)
{
	int		count;
	t_stack	*check;

	if (!stack)
		return (-1);
	count = 0;
	check = stack;
	while (check)
	{
		if (check->content >= min && check->content < max)
			break ;
		count++;
		check = check->next;
	}
	return (count);
}

int	rra_needed(t_stack *stack, int min, int max)
{
	int		count;
	int		last;
	t_stack	*check;

	count = 0;
	last = lstsize(stack) + 1;
	check = stack;
	while (check)
	{
		if (check->content >= min && check->content < max)
			last = count;
		count++;
		check = check->next;
	}
	return (lstsize(stack) - last);
}

void	big_sort(t_data *data)
{
	int	count_chunk;
	int	i;
	int	ra_mvs;
	int	rra_mvs;

	count_chunk = 0;
	while (count_chunk < data->n_chunks)
	{
		i = 0;
		while (i < data->chunk_size)
		{
			ra_mvs = ra_needed(data->stack_a, data->chunk_size * count_chunk,
					data->chunk_size * (count_chunk + 1));
			rra_mvs = rra_needed(data->stack_a, data->chunk_size * count_chunk,
					data->chunk_size * (count_chunk + 1));
			if ((ra_mvs <= rra_mvs || ra_mvs == 0) && ra_mvs != -1)
				move_for_pb(data, ra_mvs, "ra");
			else if (rra_mvs > 0)
				move_for_pb(data, rra_mvs, "rra");
			i++;
		}
		count_chunk++;
	}
	refill(data);
}
