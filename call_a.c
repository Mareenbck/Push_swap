/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:44:09 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/05 12:59:37 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_a(t_liste *list, int *rotate)
{
	int	size;

	size = ft_len_list(list->a);
	if (*rotate > (size / 2) && size > 3)
	{
		while (*rotate < size)
		{
			ft_ra(list);
			(*rotate)++;
		}
	}
	else if (size > 3)
	{
		while (*rotate)
		{
			ft_rra(list);
			(*rotate)--;
		}
	}
}

void	ft_push_a(t_liste *list, int *push)
{
	while (list->b && *push)
	{
		ft_pa(list);
		(*push)--;
	}
}

t_elemt	*ft_sort_a(t_liste *list, int len)
{
	int	push;
	int	rotate;
	int	size;

	push = 0;
	rotate = 0;
	size = ft_len_list(list->a);
	if ((ft_check_sorted(list->a) && list->a))
		return (list->a);
	if (len <= 3)
	{
		if (size == 3)
			ft_sort_3_a(list);
		else
			ft_petit_tri_a(list);
		return (list->a);
	}
	ft_sort_a_with_median(list, &push, &rotate, len);
	ft_reverse_a(list, &rotate);
	list->a = ft_sort_a(list, (len - push));
	list->b = ft_sort_b(list, push);
	ft_push_a(list, &push);
	return (list->a);
}
