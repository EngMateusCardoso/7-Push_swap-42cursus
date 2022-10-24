/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:50:29 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/24 06:51:39 by matcardo         ###   ########.fr       */
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
	int		size;
}	t_data;

void	print_stack(t_data *data);
void	print_stack_2(t_stack *stack);
//lst_utils_01.c
t_stack	*lstnew(int n);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstlastbutone(t_stack *lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **lst, t_stack *new);
//lst_utils_02.c
t_stack *selection_sort_stack(t_stack *stack);
int		have_duplicates(t_stack *stack);
void	exit_error(t_data *data);
void	free_stack(t_stack **stack);
//utils.c
void	*convert_int(const char *nptr, int *target);
//sort cases.c
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data, int	less_content_stack_a);
void	sort_five(t_data *data);
int		is_shorted(t_stack *stack);

//Operations.c
void	stack_operation(t_data *data, char *op);

#endif
