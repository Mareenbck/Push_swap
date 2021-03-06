/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:13:35 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/05 13:53:27 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elemt	*ft_lst_last(t_elemt *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_ra(t_liste *list)
{
	t_elemt	*last;
	t_elemt	*top;

	if (list->a != NULL && list->a->next)
	{
		last = list->a;
		list->a = list->a->next;
		top = list->a;
		last->next = NULL;
		list->a = ft_lst_last(list->a);
		list->a->next = last;
		list->a = top;
	}
	write(1, "ra\n", 3);
}

void	ft_rra(t_liste *list)
{
	t_elemt	*top;
	t_elemt	*tmp;

	if (list->a != NULL)
	{
		top = list->a;
		while (list->a->next->next)
			list->a = list->a->next;
		tmp = list->a->next;
		list->a->next = NULL;
		tmp->next = top;
		list->a = tmp;
	}
	write(1, "rra\n", 4);
}

void	ft_sa(t_liste *list)
{
	t_elemt	*tmp;

	if (list->a != NULL)
	{
		tmp = list->a->next;
		list->a->next = list->a->next->next;
		tmp->next = list->a;
		list->a = tmp;
	}
	write(1, "sa\n", 3);
}

void	ft_pb(t_liste *list)
{
	t_elemt	*tmp;

	tmp = list->a;
	if (list->a)
	{
		tmp = list->a->next;
		list->a->next = list->b;
		list->b = list->a;
		list->a = tmp;
	}
	write(1, "pb\n", 3);
}
