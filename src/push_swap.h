/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:50:29 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/27 19:37:58 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
//delete ta aqui para debugar com printf
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
}	t_data;

void	print_stack(t_data *data);
//utils
void	*convert_int(const char *nptr, int *target);
void	exit_error(t_data *data);
//lst_utils
t_stack	*lstnew(int n);
void	lstadd_front(t_stack **lst, t_stack *new);

#endif
