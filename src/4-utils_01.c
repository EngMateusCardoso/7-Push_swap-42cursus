/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-push_swap_utils_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:52:44 by matcardo          #+#    #+#             */
/*   Updated: 2022/10/23 06:52:48 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*convert_int(const char *nptr,int *target)
{
	unsigned long int	result;
	short int			sign;

	if (ft_strlen(nptr) > 11)
		return (NULL);
	sign = 1;
	result = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - 48);
	if (*nptr || result > 2147483648 || (sign == 1 && result == 2147483648))
		return (NULL);
	else
		*target = result * sign;
	return (target);
}
