/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:47:23 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/30 13:25:13 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_sort_3_a(t_liste *list)
{
	printf(">> SORT 3 A\n");
	t_elemt *last;
	t_elemt *middle;

	last = ft_lst_last(list->a);
	middle = list->a->next;
	printf("last : %d\n", last->val);
	printf("middle : %d\n", middle->val);
	printf("top : %d\n", list->a->val);
	if(list->a->val > middle->val
			&& middle->val < last->val
			&& last->val < list->a->val)
		ft_ra(list);
	else 
	{	
		if (list->a->val < middle->val 
				&& middle->val > last->val
				&& last->val < list->a->val)
			ft_rra(list);
		else 
			ft_sa(list);
	}

	
	middle = list->a->next;
	last = ft_lst_last(list->a);
	printf("last : %d\n", last->val);
	printf("middle : %d\n", middle->val);
	printf("top : %d\n", list->a->val);
	if (list->a->val < middle->val 
			&& middle->val > last->val
			&& last->val < list->a->val)
		ft_rra(list);
	else if (list->a->val > middle->val
			&& middle->val < last->val
			&& last->val < list->a->val)
		ft_ra(list);
	return (list);
}

t_liste *ft_petit_tri_a(t_liste *list)
{
	int len;

	printf("On rentre dans petit_tri A\n");
	len = ft_len_list(list->a);
	if (len >= 2 && list->a->val > list->a->next->val)
		ft_sa(list);
	if (len >= 3 && (list->a->next->val > list->a->next->next->val))
		ft_sort_3_a(list);
	if (len >= 2 && list->a->val > list->a->next->val)
		ft_sa(list);
	return (list);
}

void ft_sort_a_with_median(t_liste *list, int *push, int len)
{
	int median;
	//int size;
	int i;
	t_elemt	*elemt;


	i = 0;
	printf(">> TRI MEDIAN A\n");
	median = ft_median(list->a, list, len);
	printf("len A: %d\n", len);
	printf("median A: %d", median);
	elemt = list->a;
	while (i < len)
	{			
		//size = ft_len_list(list->a);
		//if (size == 3 && !ft_check_sorted(list->a))
		//	ft_sort_3_a(list);
		if (elemt->val < median)
		{
			ft_pb(list);
			(*push)++;
		}
		else
			ft_ra(list);	
		i++;
		elemt = list->a;
		printf("i : %d \n", i);
		printf("elemt A: %d\n", elemt->val);	
		printf("median : %d\n", median);
		printf("push = %d\n", *push);
	//	printf("size = %d\n", size);
		printf("-------------\n");

	}		
}

t_elemt	*ft_sort_a(t_liste *list, int len)
{
	int push;
	// int pa;

	// pa = 0;
	push = 0;
	
	printf("len dans sort A : %d\n", len);
	printf("SORT A: %d\n", ft_check_sorted(list->a));
	if ((ft_check_sorted(list->a) && list->a))
		return (list->a);
	if (len <= 3)
	{
		if (len == 3)
			ft_sort_3_a(list);
		else 
			ft_petit_tri_a(list);
		return (list->a);
	}
	
	ft_sort_a_with_median(list, &push, len);
	
	// {
	// 	ft_petit_tri_a(list);
	// 	return(list->a);
	// }
	// ft_sort_a_with_median(list, &push, len);
	// printf("sortie du tri A avec mediane\n");
	// list->a = ft_sort_a(list, (len - push));
	// list->b = ft_sort_b(list, push);
	
	printf("sortie du tri A avec mediane\n");
	list->a = ft_sort_a(list, (len - push));
	list->b = ft_sort_b(list, push);
	//if (ft_check_sorted_reverse(list->b))
//  {
	while (list->b && push)
	{
		ft_pa(list);
		push--;
		printf("push : %d\n", push);	
	}
//	}
	return (list->a);	
}
