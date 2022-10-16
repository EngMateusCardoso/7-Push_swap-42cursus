/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:50:29 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/16 05:56:41 by matcardo         ###   ########.fr       */
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
void	print_stack_2(t_stack *stack);
//Operations
void	stack_operation(t_data *data, const char *op);
//utils
void	*convert_int(const char *nptr, int *target);
void	exit_error(t_data *data);
void	free_stack(t_stack **stack);
//lst_utils
t_stack	*lstnew(int n);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstlastbutone(t_stack *lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack *sort_numbers(t_stack *stack);

#endif
