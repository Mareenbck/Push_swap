/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:01:03 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/05 13:19:34 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_liste *list, int *push)
{
	while (*push)
	{
		ft_pb(list);
		(*push)--;
	}
}

void	ft_reverse_b(t_liste *list, int *rotate)
{
	int	size;

	size = ft_len_list(list->b);
	if (*rotate > (size / 2) && size > 3)
	{
		while (*rotate < size)
		{
			ft_rb(list);
			(*rotate)++;
		}
	}
	else if (size > 3)
	{
		while (*rotate)
		{
			ft_rrb(list);
			(*rotate)--;
		}
	}
}

t_elemt	*ft_sort_b(t_liste *list, int len)
{
	int	push;
	int	rotate;
	int	size;

	push = 0;
	rotate = 0;
	size = ft_len_list(list->b);
	if (ft_check_sorted_reverse(list->b))
		return (list->b);
	if (len <= 3)
	{
		if (size == 3)
			ft_sort_3_b(list);
		else
			ft_petit_tri_b(list);
		return (list->b);
	}
	ft_sort_b_with_median(list, &push, &rotate, len);
	ft_reverse_b(list, &rotate);
	list->a = ft_sort_a(list, push);
	list->b = ft_sort_b(list, (len - push));
	if (ft_check_sorted_reverse(list->b) == 0)
		ft_push_b(list, &push);
	return (list->b);
}
