/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:47:23 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/01 10:31:05 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_sort_3_b(t_liste *list)
{
  // printf(">>> SORT 3 B <<<\n");
  t_elemt *third;
  t_elemt *second;
  t_elemt *first;

  first = list->b;
  third = list->b->next->next;
  second = list->b->next;
  if (first->val < second->val
      && second->val > third->val
      && third->val > first->val)
	 	ft_rb(list);
	 else
	 {
		if (first->val > second->val
				&& second->val < third->val
				&& third->val > first->val)
			ft_rrb(list);
		else
			ft_sb(list);
	 }
   first = list->b;
   third = list->b->next->next;
   second = list->b->next;
   if (first->val > second->val
	 		&& second->val < third->val
			&& third->val > first->val)
	 	ft_rrb(list);
	 else if (first->val < second->val
	 		&& second->val > third->val
	 		&& third->val > first->val)
	 	ft_rb(list);
   return (list);
}

t_liste *ft_petit_tri_b(t_liste *list)
{
	int size;

  // printf(">>> PETIT TRI B <<<\n");
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

int above_median(t_liste *list, int n, int median)
{
  int i;
  t_elemt *tmp;

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
	int median;
	int i;
	t_elemt	*elemt;

	i = 0;
  // printf(">>> TRI MEDIAN B <<<\n");
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

t_elemt	*ft_sort_b(t_liste *list, int len)
{
	int push;
  int rotate;
  int size;

	push = 0;
  rotate = 0;
  size = ft_len_list(list->b);
  // printf(">>> SORT B <<<\n");
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
  if (len > 3)
  {
    while (rotate)
    {
      ft_rrb(list);
      rotate--;
    }
  }
  list->a = ft_sort_a(list, push);
  list->b = ft_sort_b(list, (len - push));
	if (ft_check_sorted_reverse(list->b) == 0)
	{
		while (push)
		{
			ft_pb(list);
			push--;
    }
	}
  return (list->b);
}
