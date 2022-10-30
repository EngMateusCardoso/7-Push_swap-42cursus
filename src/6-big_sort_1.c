/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-big_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 06:57:21 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/30 00:23:28 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adapt_stack_b(t_data *data, int first, int last, int stack_a_mvs[2])
{
	int	mvs_stack_b[2][2];
	int	option;

	mvs_stack_b[0][0] = find_position(data->stack_b, find_top_content_stack_b(
				data, first));
	mvs_stack_b[0][1] = lstsize(data->stack_b) - mvs_stack_b[0][0];
	mvs_stack_b[1][0] = find_position(data->stack_b, find_top_content_stack_b(
				data, last));
	mvs_stack_b[1][1] = lstsize(data->stack_b) - mvs_stack_b[1][0];
	option = find_option(stack_a_mvs[0], stack_a_mvs[1],
			mvs_stack_b[0], mvs_stack_b[1]);
	if (option == 1 || option == 2)
		exec_adapt_stack_b_simple(data, option, stack_a_mvs, mvs_stack_b);
	else if (option == 3 || option == 4)
		exec_adapt_stack_b_optimized(data, option, stack_a_mvs, mvs_stack_b);
}

void	move_for_stack_b(t_data *data, int ra_moves, int rra_moves)
{
	int	pass_ra;
	int	pass_rra;
	int	stack_a_mvs[2];

	if (data->stack_b && data->stack_b->next && data->stack_a)
	{
		pass_ra = find_content(data->stack_a, ra_moves);
		pass_rra = find_content(data->stack_a,
				lstsize(data->stack_a) - rra_moves);
		stack_a_mvs[0] = ra_moves;
		stack_a_mvs[1] = rra_moves;
		adapt_stack_b(data, pass_ra, pass_rra, stack_a_mvs);
	}
	else
	{
		if (ra_moves <= rra_moves)
			stack_operations(data, "ra", ra_moves);
		else
			stack_operations(data, "rra", rra_moves);
	}
	stack_operations(data, "pb", 1);
}

int	ra_needed(t_stack *stack, int min, int max)
{
	int		count;
	int		first;
	t_stack	*check;

	if (!stack)
		return (-1);
	first = -1;
	count = 0;
	check = stack;
	while (check)
	{
		if (check->content >= min && check->content < max)
		{
			first = count;
			break ;
		}
		count++;
		check = check->next;
	}
	return (first);
}

int	rra_needed(t_stack *stack, int min, int max)
{
	int		count;
	int		last;
	t_stack	*check;

	if (!stack)
		return (-1);
	last = lstsize(stack) + 1;
	count = 0;
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
			if (ra_mvs != -1 && rra_mvs != -1)
				move_for_stack_b(data, ra_mvs, rra_mvs);
			i++;
		}
		count_chunk++;
	}
	refill(data);
}
