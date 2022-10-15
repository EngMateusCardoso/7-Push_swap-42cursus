/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:27:38 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/15 21:06:09 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int n)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = n;
	node->next = NULL;
	return (node);
}

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	else if (!lst->next)
		return (lst);
	return (lstlast(lst->next));
}

t_stack	*lstlastbutone(t_stack *lst)
{
	if (!lst)
		return (NULL);
	else if (!lst->next->next)
		return (lst);
	return (lstlastbutone(lst->next));
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		lstlast(*lst)->next = new;
}
