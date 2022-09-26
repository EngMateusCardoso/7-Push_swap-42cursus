/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:44:48 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/26 03:57:56 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data, int size, char **argv)
{
	data->size_a = size;
	data->size_b = 0;
	data->stack_a = (t_stack *)malloc(sizeof(t_stack));
	data->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!data->stack_a || !data->stack_b)
		exit(1);
	size--;
	while (size > 0)
	{
		ft_putstr_fd(argv[size], 1);
		size--;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 2)
		exit(EXIT_SUCCESS);
	init_data(&data, argc, argv);
	fct();
	return (0);
}
