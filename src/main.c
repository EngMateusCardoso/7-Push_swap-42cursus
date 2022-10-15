/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:44:48 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/15 22:47:30 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resume_numbers_stack(t_stack *stack)
{
	t_stack	*sort_stack;
	t_stack	*temp_stack;
	int		i;

	sort_stack = sort_numbers(stack);
	temp_stack = stack;
	print_stack_2(stack);
	print_stack_2(sort_stack);
	i = 0;
	while(sort_stack)
	{
		while(temp_stack)
		{
			if (temp_stack->content == sort_stack->content)
				temp_stack->content = i;
			temp_stack = temp_stack->next;
		}
		temp_stack = stack;
		sort_stack = sort_stack->next;
		i++;
	}
	print_stack_2(stack);
	//free_stack(sort_stack);
}

void	init_data(t_data *data, int size, char **argv)
{
	t_stack	*temp;
	int 	nbr;

	size--;
	data->size_a = size;
	data->size_b = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 2)
		exit(EXIT_SUCCESS);
	init_data(&data, argc, argv);
	// print_stack(&data); // vai sair
	// printf("-%d-\n", argc);
	resume_numbers_stack(data.stack_a);
	// print_stack(&data); // vai sair
	return (0);
}
