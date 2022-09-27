/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:27:39 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/27 19:37:50 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_data *data)
{
	t_stack *node;

	node = data->stack_a;
	ft_putstr_fd("Stack A\n",1);
	while(node)
	{
		ft_putnbr_fd(node->content, 1);
		ft_putchar_fd('\n',1);
		node = node->next;
	}
	node = data->stack_b;
	ft_putstr_fd("Stack B\n",1);
	while(node)
	{
		ft_putnbr_fd(node->content, 1);
		ft_putchar_fd('\n',1);
		node = node->next;
	}
}
