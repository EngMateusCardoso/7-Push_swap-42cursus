/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:44:48 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/04 16:08:11 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data, int size, char **argv)
{
	t_stack	*temp;
	int 	nbr;

	data->size_a = size;
	data->size_b = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
	size--;
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
	print_stack(&data);
	ft_putstr_fd("-----sa-----\n", 1);
	stack_operation(&data, "sa");
	print_stack(&data);
	ft_putstr_fd("-----pb-----\n", 1);
	stack_operation(&data, "pb");
	print_stack(&data);
	ft_putstr_fd("-----pb-----\n", 1);
	stack_operation(&data, "pb");
	print_stack(&data);
	ft_putstr_fd("-----sb-----\n", 1);
	stack_operation(&data, "sb");
	print_stack(&data);
	ft_putstr_fd("-----ss-----\n", 1);
	stack_operation(&data, "ss");
	print_stack(&data);
	ft_putstr_fd("-----pb-----\n", 1);
	stack_operation(&data, "pb");
	print_stack(&data);
	ft_putstr_fd("-----ra-----\n", 1);
	stack_operation(&data, "ra");
	print_stack(&data);
	ft_putstr_fd("-----rb-----\n", 1);
	stack_operation(&data, "rb");
	print_stack(&data);
	ft_putstr_fd("-----rr-----\n", 1);
	stack_operation(&data, "rr");
	print_stack(&data);
	ft_putstr_fd("-----rra-----\n", 1);
	stack_operation(&data, "rra");
	print_stack(&data);
	ft_putstr_fd("-----rrb-----\n", 1);
	stack_operation(&data, "rrb");
	print_stack(&data);
	ft_putstr_fd("-----rrr-----\n", 1);
	stack_operation(&data, "rrr");
	print_stack(&data);
	return (0);
}
