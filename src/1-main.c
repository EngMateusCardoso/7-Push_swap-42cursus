/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:44:48 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/30 02:44:46 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resume_numbers_stack(t_stack *stack)
{
	t_stack	*sort_stack;
	t_stack	*temp_sort_stack;
	t_stack	*temp_stack;
	int		i;
	int		temp;

	sort_stack = to_sort_stack(stack);
	temp_stack = stack;
	while (temp_stack)
	{
		i = 0;
		temp = temp_stack->content;
		temp_sort_stack = sort_stack;
		while (temp_sort_stack)
		{
			if (temp == temp_sort_stack->content)
				temp_stack->content = i;
			temp_sort_stack = temp_sort_stack->next;
			i++;
		}
		temp_stack = temp_stack->next;
	}
	free_stack(&sort_stack);
}

void	init_stack(t_data *data, int size, char **argv)
{
	t_stack	*temp;
	int		nbr;

	while (size > 0)
	{
		if (!convert_int(argv[size], &nbr))
			exit_error(data);
		temp = lstnew(nbr);
		if (!temp)
			exit_error(data);
		lstadd_front(&(data->stack_a), temp);
		size--;
	}
}

void	init_data(t_data *data, int size, char **argv)
{
	size--;
	data->size = size;
	data->stack_a = NULL;
	data->stack_b = NULL;
	if (size <= 100)
	{
		data->n_chunks = 5;
		if (!(size % 5))
			data->chunk_size = size / 5;
		else
			data->chunk_size = size / 5 + 1;
	}
	else
	{
		data->n_chunks = 11;
		if (!(size % 11))
			data->chunk_size = size / 11;
		else
			data->chunk_size = size / 11 + 1;
	}
	init_stack(data, size, argv);
}

void	push_swap(t_data *data)
{
	if (data->size == 1)
		exit(EXIT_SUCCESS);
	if (data->size == 2)
		sort_two(data);
	else if (data->size == 3)
		sort_three(data);
	else if (data->size == 4)
		sort_four(data, 0);
	else if (data->size == 5)
		sort_five(data);
	else
		big_sort(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	init_data(&data, argc, argv);
	if (have_duplicates(data.stack_a))
		exit_error(&data);
	resume_numbers_stack(data.stack_a);
	if (!is_sorted(data.stack_a))
		push_swap(&data);
	free_stack(&data.stack_a);
	return (0);
}
