/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:47:23 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/05 13:14:17 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_sort_3_b(t_liste *list)
{
	if (list->b->val < list->b->next->val
		&& list->b->next->val > list->b->next->next->val
		&& list->b->next->next->val > list->b->val)
		ft_rb(list);
	else
	{
		if (list->b->val > list->b->next->val
			&& list->b->next->val < list->b->next->next->val
			&& list->b->next->next->val > list->b->val)
			ft_rrb(list);
		else
			ft_sb(list);
	}
	if (list->b->val > list->b->next->val
		&& list->b->next->val < list->b->next->next->val
		&& list->b->next->next->val > list->b->val)
		ft_rrb(list);
	else if (list->b->val < list->b->next->val
		&& list->b->next->val > list->b->next->next->val
		&& list->b->next->next->val > list->b->val)
		ft_rb(list);
	return (list);
}

t_liste	*ft_petit_tri_b(t_liste *list)
{
	int	size;

	size = ft_len_list(list->b);
	if (list->b->val < list->b->next->val)
		ft_sb(list);
	if (size >= 3 && (list->b->next->val < list->b->next->next->val))
	{
		ft_rb(list);
		ft_sb(list);
		ft_rrb(list);
	}
	if (list->b->val < list->b->next->val)
		ft_sb(list);
	return (list);
}

int	above_median(t_liste *list, int n, int median)
{
	int		i;
	t_elemt	*tmp;

	i = 0;
	tmp = list->b;
	while (i < n)
	{
		if (tmp->val > median)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_b_with_median(t_liste *list, int *push, int *rotate, int len)
{
	int		median;
	int		i;
	t_elemt	*elemt;

	i = 0;
	median = ft_median(list->b, 1, len);
	elemt = list->b;
	while (i < len && above_median(list, len - i, median))
	{
		if (elemt->val > median)
		{
			ft_pa(list);
			(*push)++;
		}
		else
		{
			ft_rb(list);
			(*rotate)++;
		}
		i++;
		elemt = list->b;
	}
}
