/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:47:23 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/31 21:28:18 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_sort_3_b(t_liste *list)
{
    printf(">> SORT 3 B\n");
	 t_elemt *last;
     t_elemt *middle;
	 last = list->b->next->next;
	 middle = list->b->next;
	 printf("Bottom : %d\n", last->val);
	 printf("middle : %d\n", middle->val);
	 printf("top : %d\n", list->b->val);
	 if (list->b->val < middle->val
	 		&& middle->val > last->val
	 		&& last->val > list->b->val)
	 	ft_rb(list);
	 else
	 {
		if (list->b->val > middle->val 
				&& middle->val < last->val
				&& last->val > list->b->val)
			ft_rrb(list);
		else 
			ft_sb(list);
	 }
	 middle = list->b->next;
	 last = ft_lst_last(list->b);
	 if (list->b->val > middle->val 
	 		&& middle->val < last->val
			&& last->val > list->b->val)
	 	ft_rrb(list);
	 else if (list->b->val < middle->val
	 		&& middle->val > last->val
	 		&& last->val > list->b->val)
	 	ft_rb(list);
	return (list);
}

t_liste *ft_petit_tri_b(t_liste *list)
{
	int len;
	printf("On rentre dans petit_tri B\n");
	len = ft_len_list(list->b);
	if (len >= 2 && (list->b->val < list->b->next->val))
		ft_sb(list);
	if (len >= 3 && (list->b->next->val < list->b->next->next->val))
	{
		ft_rb(list);
		ft_sb(list);
		ft_rrb(list);
	}
	if (len >= 2 && list->b->val < list->b->next->val)
		ft_sb(list);
	return (list);
}

void	ft_sort_b_with_median(t_liste *list, int *push, int len)
{
	int median;
//	int size;
	int i;
	t_elemt	*elemt;

	i = 0;
	printf(">> TRI MEDIANE B\n");
	
	median = ft_median(list->b, 1, len);
	printf("len B: %d\n", len);
	printf("median B: %d\n", median);
	elemt = list->b;
	while (i < len)
	{
	//  size = ft_len_list(list->b);
	//	printf("size B : %d\n", size);
		printf("Elemt B : %d\n", elemt->val);
	//	if (size == 3)
	//		ft_sort_3_b(list);
		if (elemt->val > median)
		{


			ft_pa(list);
			(*push)++;
		}
		else
			ft_rb(list);
		i++;
		elemt = list->b;

		printf("elemt B: %d\n", elemt->val);		
	}
}

t_elemt	*ft_sort_b(t_liste *list, int len)
{
	int push;
    // int pb;

    // pb = 0;
	push = 0;
	printf("len B dans sort : %d\n", len);
    int size;
    size = ft_len_list(list->b);
    printf("size liste B %d\n", size);
	// if (ft_check_sorted_reverse(list->b) || len == 0)
	// 	return (list->b);
	if (len <= 3)
	{
	 	if (size == 3)
			ft_sort_3_b(list);
		else
			ft_petit_tri_b(list);
		return (list->b);
	}

	ft_sort_b_with_median(list, &push, len);
	printf("sortie du tri B avec mediane\n");
	list->a = ft_sort_a(list, push);
	list->b = ft_sort_b(list, (len - push));
	// if (len == 3)
	//  	ft_sort_3_b(list);
	// else if (len <= 2 && (list->b->val < list->b->next->val))
	// 	ft_sb(list);
	// else
	// 	ft_sort_b_with_median(list, &push, len);
	if (ft_check_sorted_reverse(list->b) == 0)
	{
		while (push)
		{
			ft_pb(list);
			push--;
		}
	}
	t_elemt *elemt = list->b;
	printf("-----SORT B-----\n");
	while (elemt != NULL)
	{
		printf("a : %d\n", elemt->val);
		elemt = elemt->next;
	}
	return (list->b);		
}
