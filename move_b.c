/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:13:35 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/30 11:34:07 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void		ft_rb(t_liste *list)
{
	t_elemt	*last;
	t_elemt *top;

	if (list->b != NULL)
	{
		last = list->b;
		list->b = list->b->next;
		top = list->b;
		last->next = NULL;
		last->prev = top;
		list->b = ft_lst_last(list->b);
		list->b->next = last;
		list->b = top;
	}
	write(1, "rb\n", 3);
  // printf("\033[0;31m . RB . \033[0;m\n");
}

void		ft_rrb(t_liste *list)
{
	t_elemt	*top;
	t_elemt *tmp;

	if (list->b != NULL)
	{
		top = list->b;
		while (list->b->next->next)
			list->b = list->b->next;
		tmp = list->b->next;
		list->b->next = NULL;
		tmp->next = top;
		tmp->prev = NULL;
		list->b = tmp;
	}
	write(1, "rrb\n", 4);
  // printf("\033[0;31m . RRB . \033[0;m\n");
}

void	ft_sb(t_liste *list)
{
	t_elemt *tmp;

	if (list->b != NULL)
	{
		tmp = list->b->next;
		list->b->next = list->b->next->next;
		tmp->next = list->b;
		tmp->prev = NULL;
		list->b = tmp;
	}
	write(1, "sb\n", 3);
  // printf("\033[0;33m . SB . \033[0;m\n");
}

void		ft_pa(t_liste *list)
{
	t_elemt *tmp;
	if (list->b)
	{
		tmp = list->b->next;
		list->b->next = list->a;
		list->a = list->b;
		list->b = tmp;
	}
	write(1, "pa\n", 3);
  // printf("\033[0;32m . PA . \033[0;m\n");
}
