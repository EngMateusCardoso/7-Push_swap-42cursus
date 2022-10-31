/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:53:26 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/30 04:35:22 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		less_commands;
	int		best_chunck;

	best_chunck = 1;
	less_commands = 2147483647;
	data.n_chunks = 1;
	data.is_a_test = 1;
	while (data.n_chunks != 25)
	{
		push_swap(&data, argc, argv);
		if (data.count_commands < less_commands)
		{
			less_commands = data.count_commands;
			best_chunck = data.n_chunks;
		}
		data.n_chunks++;
	}
	data.n_chunks = best_chunck;
	data.is_a_test = 0;
	push_swap(&data, argc, argv);
	return (0);
}
