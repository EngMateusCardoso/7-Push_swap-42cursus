/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7-big_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:20:00 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/30 00:20:04 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_top_content_stack_b(t_data *data, int content)
{
	int		next_less_pos;
	int		bigger_pos;
	t_stack	*temp;

	next_less_pos = -1;
	bigger_pos = -1;
	temp = data->stack_b;
	while (temp)
	{
		if (temp->content < content && temp->content > next_less_pos)
			next_less_pos = temp->content;
		temp = temp->next;
	}
	if (next_less_pos == -1)
	{
		temp = data->stack_b;
		while (temp)
		{
			if (temp->content > bigger_pos)
				bigger_pos = temp->content;
			temp = temp->next;
		}
		return (bigger_pos);
	}
	return (next_less_pos);
}

int	find_option(int ra_mvs, int rra_mvs, int mvs_ra[2], int mvs_rra[2])
{
	int	opt_1;
	int	opt_2;
	int	opt_3;
	int	opt_4;

	opt_1 = ra_mvs + mvs_ra[1];
	opt_2 = rra_mvs + mvs_rra[0];
	if (ra_mvs >= mvs_ra[0])
		opt_3 = ra_mvs;
	else
		opt_3 = mvs_ra[0];
	if (rra_mvs >= mvs_rra[1])
		opt_4 = rra_mvs;
	else
		opt_4 = mvs_rra[1];
	if (opt_1 <= opt_2 && opt_1 <= opt_3 && opt_1 <= opt_4)
		return (1);
	else if (opt_2 <= opt_1 && opt_2 <= opt_3 && opt_2 <= opt_4)
		return (2);
	else if (opt_3 <= opt_1 && opt_3 <= opt_2 && opt_3 <= opt_4)
		return (3);
	else
		return (4);
}

void	exec_adapt_stack_b_simple(t_data *data, int option, int stack_a_mvs[2],
			int mvs_stack_b[2][2])
{
	if (option == 1)
	{
		stack_operations(data, "rrb", mvs_stack_b[0][1]);
		stack_operations(data, "ra", stack_a_mvs[0]);
	}
	else if (option == 2)
	{
		stack_operations(data, "rb", mvs_stack_b[1][0]);
		stack_operations(data, "rra", stack_a_mvs[1]);
	}
}

void	exec_adapt_stack_b_optimized(t_data *data, int option,
			int stack_a_mvs[2], int mvs_stack_b[2][2])
{
	if (option == 3 && stack_a_mvs[0] >= mvs_stack_b[0][0])
	{
		stack_operations(data, "rr", mvs_stack_b[0][0]);
		stack_operations(data, "ra", stack_a_mvs[0] - mvs_stack_b[0][0]);
	}
	else if (option == 3 && stack_a_mvs[0] < mvs_stack_b[0][0])
	{
		stack_operations(data, "rr", stack_a_mvs[0]);
		stack_operations(data, "rb", mvs_stack_b[0][0] - stack_a_mvs[0]);
	}
	else if (option == 4 && stack_a_mvs[1] >= mvs_stack_b[1][1])
	{
		stack_operations(data, "rrr", mvs_stack_b[1][1]);
		stack_operations(data, "rra", stack_a_mvs[1] - mvs_stack_b[1][1]);
	}
	else if (option == 4 && stack_a_mvs[1] < mvs_stack_b[1][1])
	{
		stack_operations(data, "rrr", stack_a_mvs[1]);
		stack_operations(data, "rrb", mvs_stack_b[1][1] - stack_a_mvs[1]);
	}
}
