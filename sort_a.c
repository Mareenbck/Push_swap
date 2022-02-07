/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:47:23 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/05 12:54:01 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_sort_3_a(t_liste *list)
{
	if (list->a->val > list->a->next->val
		&& list->a->next->val < list->a->next->next->val
		&& list->a->next->next->val < list->a->val)
		ft_ra(list);
	else
	{
		if (list->a->val < list->a->next->val
			&& list->a->next->val > list->a->next->next->val
			&& list->a->next->next->val < list->a->val)
			ft_rra(list);
		else
			ft_sa(list);
	}
	if (list->a->val < list->a->next->val
		&& list->a->next->val > list->a->next->next->val
		&& list->a->next->next->val < list->a->val)
		ft_rra(list);
	else if (list->a->val > list->a->next->val
		&& list->a->next->val < list->a->next->next->val
		&& list->a->next->next->val < list->a->val)
		ft_ra(list);
	return (list);
}

t_liste	*ft_petit_tri_a(t_liste *list)
{
	int	size;

	size = ft_len_list(list->a);
	if (list->a->val > list->a->next->val)
		ft_sa(list);
	if (size >= 3 && (list->a->next->val > list->a->next->next->val))
	{
		ft_ra(list);
		ft_sa(list);
		ft_rra(list);
	}
	if (list->a->val > list->a->next->val)
		ft_sa(list);
	return (list);
}

int	under_median(t_liste *list, int n, int median)
{
	int		i;
	t_elemt	*tmp;

	i = 0;
	tmp = list->a;
	while (i < n)
	{
		if (tmp->val < median)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_a_with_median(t_liste *list, int *push, int *rotate, int len)
{
	t_elemt	*elemt;
	int		i;
	int		median;

	elemt = list->a;
	i = 0;
	median = ft_median(list->a, 0, len);
	while (i < len && under_median(list, len - i, median))
	{
		if (elemt->val < median)
		{
			ft_pb(list);
			(*push)++;
		}
		else
		{
			ft_ra(list);
			(*rotate)++;
		}
		i++;
		elemt = list->a;
	}
}
