/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:50:29 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/30 04:11:13 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

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
	int		chunk_size;
	int		n_chunks;
	int		is_a_test;
	int		count_commands;
}	t_data;

//1-push_swap.c
void	push_swap(t_data *data, int argc, char **argv);
//lst_utils_1.c
t_stack	*lstnew(int n);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstlastbutone(t_stack *lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **lst, t_stack *new);
//lst_utils_02.c
int		lstsize(t_stack	*stack);
int		find_content(t_stack *stack, int position);
int		find_position(t_stack *stack, int to_find);
void	free_stack(t_stack **stack);
int		have_duplicates(t_stack *stack);
//utils.c
void	copy_stack(t_stack *src, t_stack **dst);
t_stack	*to_sort_stack(t_stack *stack);
void	*convert_int(const char *nptr, int *target);
void	exit_error(t_data *data);
//sort_cases.c
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data, int less_content_stack_a);
void	sort_five(t_data *data);
int		is_sorted(t_stack *stack);
//big_sort_1.c
void	big_sort(t_data *data);
//big_sort_2.c
int		find_top_content_stack_b(t_data *data, int content);
int		find_option(int ra_mvs, int rra_mvs, int mvs_ra[2], int mvs_rra[2]);
void	exec_adapt_stack_b_simple(t_data *data, int option, int stack_a_mvs[2],
			int mvs_stack_b[2][2]);
void	exec_adapt_stack_b_optimized(t_data *data, int option,
			int stack_a_mvs[2], int mvs_stack_b[2][2]);
//refill.c
void	refill(t_data *data);
//Operations.c
void	stack_operations(t_data *data, char *op, int n_moves);

#endif
