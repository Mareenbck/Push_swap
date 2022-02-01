/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:47:23 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/01 10:27:19 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_sort_3_a(t_liste *list)
{
	// printf(">>> SORT 3 A <<<\n");
	t_elemt *third;
	t_elemt *second;
  t_elemt *first;

	first = list->a;
  third = list->a->next->next;
	second = list->a->next;
	if(first->val > second->val
			&& second->val < third->val
			&& third->val < first->val)
		ft_ra(list);
	else
	{
		if (first->val < second->val
				&& second->val > third->val
				&& third->val < first->val)
			ft_rra(list);
		else
			ft_sa(list);
	}
  first = list->a;
  second = list->a->next;
	third = list->a->next->next;
	if (first->val < second->val
			&& second->val > third->val
			&& third->val < first->val)
		ft_rra(list);
	else if (first->val > second->val
			&& second->val < third->val
			&& third->val < first->val)
		ft_ra(list);
  //***************AFFICHAGE*************************
  // t_elemt *elemt = list->a;
  // t_elemt *elemtb = list->b;
  // printf("-----Sort 3 A-----");
  // printf("\n-a-    -b-");
  // printf("\n _      _\n");
  // while (elemt != NULL || elemtb != NULL)
  // {
  //   if (elemtb == NULL)
  //   {
  //     printf(" %d      \n", elemt->val);
  //     elemt = elemt->next;
  //   }
  //   else if (elemt == NULL)
  //   {
  //     printf("        %d\n", elemtb->val);
  //     elemtb = elemtb->next;
  //   }
  //   else
  //   {
  //     printf(" %d     %d\n", elemt->val, elemtb->val);
  //     elemtb = elemtb->next;
  //     elemt = elemt->next;
  //   }
  // }
  //*****************************************************
  return (list);
}

t_liste *ft_petit_tri_a(t_liste *list)
{
	int size;

	// printf(">>> PETIT TRI A <<<\n");
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
  //***************AFFICHAGE*************************
  // t_elemt *elemt = list->a;
  // t_elemt *elemtb = list->b;
  // printf("-----Petit Tri A-----");
  // printf("\n-a-    -b-");
  // printf("\n _      _\n");
  // while (elemt != NULL || elemtb != NULL)
  // {
  //   if (elemtb == NULL)
  //   {
  //     printf(" %d      \n", elemt->val);
  //     elemt = elemt->next;
  //   }
  //   else if (elemt == NULL)
  //   {
  //     printf("        %d\n", elemtb->val);
  //     elemtb = elemtb->next;
  //   }
  //   else
  //   {
  //     printf(" %d     %d\n", elemt->val, elemtb->val);
  //     elemtb = elemtb->next;
  //     elemt = elemt->next;
  //   }
  // }
  //*****************************************************
  return (list);
}

int under_median(t_liste *list, int n, int median)
{
  int i;
  t_elemt *tmp;

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

void ft_sort_a_with_median(t_liste *list, int *push, int *rotate, int len)
{
	int median;
	int i;
	t_elemt	*elemt;
	t_elemt *elemtb;

	i = 0;
	// printf(">>> TRI MEDIAN A <<<\n");
	median = ft_median(list->a, 0, len);
	elemt = list->a;
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
  elemt = list->a;
  elemtb = list->b;
  // printf("\n-----Tri Mediane A-----");
  // printf("\n-a-    -b-");
  // printf("\n _      _\n");
  // while (elemt != NULL || elemtb != NULL)
  // {
  //   if (elemtb == NULL)
  //   {
  //     printf(" %d      \n", elemt->val);
  //     elemt = elemt->next;
  //   }
  //   else if (elemt == NULL)
  //   {
  //     printf("        %d\n", elemtb->val);
  //     elemtb = elemtb->next;
  //   }
  //   else
  //   {
  //     printf(" %d     %d\n", elemt->val, elemtb->val);
  //     elemtb = elemtb->next;
  //     elemt = elemt->next;
  //   }
  // }
  // printf("-------------\n");
  // printf("push = %d\n", *push);
}

t_elemt	*ft_sort_a(t_liste *list, int len)
{
	int push;
  int rotate;
  int size;

	push = 0;
  rotate = 0;
  size = ft_len_list(list->a);
	// printf(">>> SORT A <<<\n");
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
  list->a = ft_sort_a(list, (len - push));
	list->b = ft_sort_b(list, push);
	while (list->b && push)
	{
		ft_pa(list);
		push--;
	}
  return (list->a);
}
