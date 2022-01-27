/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:47:23 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/26 11:00:56 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_sort_3_a(t_liste *list)
{
	t_elemt *bottom;
	t_elemt *middle;

	printf(">> SORT 3 A\n");
	bottom = ft_lst_last(list->a);
	middle = list->a->next;
	printf("Bottom : %d\n", bottom->val);
	printf("middle : %d\n", middle->val);
	printf("top : %d\n", list->a->val);
	if(list->a->val > middle->val
			&& middle->val < bottom->val
			&& bottom->val < list->a->val)
		ft_ra(list);
	else if (list->a->val < middle->val 
			&& middle->val > bottom->val
			&& bottom->val < list->a->val)
		ft_rra(list);
	else 
		ft_sa(list);
	//si pas sort > recursive de push swap
	 if (!ft_check_sorted(list->a))
	 	ft_sort_3_a(list);
	return (list);
}

t_liste	*ft_sort_3_b(t_liste *list)
{
	// t_elemt *bottom;
	// t_elemt *middle;
	int i = 0;
	printf(">> SORT 3 B\n");
	if (ft_check_sorted_reverse(list->b))
	 	return (list);
	if (list->b->val > list->b->next->val)
	{
		if (list->b->val > list->b->next->next->val)
			i = 1;
		ft_rrb(list);
		if (i)
			ft_sb(list);
	}
	else
	{
		if (list->b->val > list->b->next->next->val)
			ft_sb(list);
		else
		{
			if (list->b->next->val < list->b->next->next->val)
				i = 1;
			ft_rb(list);
			if (i)
				ft_sb(list);
		}
	}
	// bottom = list->b->next->next;
	// middle = list->b->next;
	// printf("Bottom : %d\n", bottom->val);
	// printf("middle : %d\n", middle->val);
	// printf("top : %d\n", list->b->val);
	// if(list->b->val < middle->val
	// 		&& middle->val > bottom->val
	// 		&& bottom->val > list->b->val)
	// 	ft_rb(list);
	// else if (list->b->val > middle->val 
	// 		&& middle->val < bottom->val
	// 		&& bottom->val > list->b->val)
	// 	ft_rrb(list);
	// else 
	// 	ft_sb(list);
	// //si pas sort > recursive de push swap
	// printf("CEST TRIE WESH %d\n", ft_check_sorted3_reverse(list->b));
	//  if (!ft_check_sorted3_reverse(list->b))
	//  	ft_sort_3_b(list);
	return (list);
}

// void ft_petit_tri_a(t_liste *list)
// {
// 	int len;

// 	printf("On rentre dans petit_tri A\n");
// 	len = ft_len_list(list->a);
// 	if (len >= 2 && (list->a->val > list->a->next->val))
// 		ft_sa(list);
// 	else if (len >= 3 && (list->a->next->val > list->a->next->next->val))
// 	{
// 		ft_sort_3_a(list);
// 	}
// 	if (len >= 2 && (list->a->val > list->a->next->val))
// 		ft_sa(list);
// 	// if (!ft_check_sorted(list->a))
// 	// 	ft_sort_3(list);
// 	//return (list);
// }


// void ft_petit_tri_b(t_liste *list)
// {
// 	int len;
// 	printf("On rentre dans petit_tri B\n");
// 	len = ft_len_list(list->b);
// 	if (len >= 2 && (list->b->val > list->b->next->val))
// 		ft_sb(list);
// 	if (len == 3 && (list->b->next->val > list->b->next->next->val))
// 	{
// 		ft_sort_3_b(list);
// 		// ft_rb(list);
// 		// ft_sb(list);
// 		// ft_rrb(list);
// 	}
// 	if (len >= 2 && (list->b->val > list->b->next->val))
// 		ft_sb(list);
// 	// if (!ft_check_sorted(list->a))
// 	// 	ft_sort_3(list);
// 	//return (list);
// }

void ft_sort_a_with_median(t_liste *list, int *push, int len)
{
	int median;
	int size;
	int i;
	t_elemt	*elemt;


	i = 0;
	printf(">> TRI MEDIAN A\n");
	median = ft_median(list->a, len);
	printf("len A: %d\n", len);
	printf("median A: %d", median);
	elemt = list->a;
	while (i < len)
	{			
		size = ft_len_list(list->a);
		if (size == 3 && !ft_check_sorted(list->a))
			ft_sort_3_a(list);
		else if (elemt->val < median)
			ft_pb(list, push);
		else
			ft_ra(list);	
		i++;
		elemt = list->a;
		printf("i : %d \n", i);
		printf("elemt A: %d\n", elemt->val);	
		printf("median : %d\n", median);
		printf("push = %d\n", *push);
		printf("size = %d\n", size);
		printf("-------------\n");

	}		
}

t_elemt	*ft_sort_a(t_liste *list, int len)
{
	int push;

	
	push = 0;
	
	printf("len dans sort A : %d\n", len);
	printf("SORT A: %d\n", ft_check_sorted(list->a));
	if (ft_check_sorted(list->a))
		return (list->a);
	
	// if (len <= 3)
	// {
	// 	ft_petit_tri_a(list);
	// 	return(list->a);
	// }
	// ft_sort_a_with_median(list, &push, len);
	// printf("sortie du tri A avec mediane\n");
	// list->a = ft_sort_a(list, (len - push));
	// list->b = ft_sort_b(list, push);
	
	if (len == 3)
		ft_sort_3_a(list);
	else if (len == 2 && (list->a->val > list->a->next->val))
		ft_sa(list);
	else
		ft_sort_a_with_median(list, &push, len);
	printf("sortie du tri A avec mediane\n");
	list->a = ft_sort_a(list, (len - push));
	list->b = ft_sort_b(list, push);
	if (ft_check_sorted_reverse(list->b))
	{
		while (list->b && push > 0)
		{
			ft_pa(list, &push);
			if (push == 1)
				push--;
			push = push - 2;		
			printf("push : %d\n", push);	
		}
	}
	return (list->a);	
}	


void	ft_sort_b_with_median(t_liste *list, int *push, int len)
{
	int median;
	int size;
	int i;
	t_elemt	*elemt;

	i = 0;
	printf(">> TRI MEDIANE B\n");
	
	median = ft_median(list->b, len);
	printf("len B: %d\n", len);
	printf("median B: %d\n", median);
	elemt = list->b;
	while (i < len)
	{
		size = ft_len_list(list->b);
		printf("size B : %d\n", size);
		printf("Elemt B : %d\n", elemt->val);
		if (size == 3)
			ft_sort_3_b(list);
		if (elemt->val >= median)
			ft_pa(list, push);
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

	push = 0;
	printf("len B dans sort : %d\n", len);
	if (ft_check_sorted_reverse(list->b)  || len == 0)
		return (list->b);
	// if (len <= 3)
	// {
	// 	ft_petit_tri_b(list);
	// 	return (list->b);
	// }
	// ft_sort_b_with_median(list, &push, len);
	// printf("sortie du tri B avec mediane\n");
	// list->a = ft_sort_a(list, push);
	// list->b = ft_sort_b(list, (len - push));


	if (len == 3)
	 	ft_sort_3_b(list);
	else if (len <= 2 && (list->b->val < list->b->next->val))
		ft_sb(list);
	else
		ft_sort_b_with_median(list, &push, len);
	printf("sortie du tri B avec mediane\n");
	list->a = ft_sort_a(list, push);
	list->b = ft_sort_b(list, (len - push));
	if (ft_check_sorted_reverse(list->b))
	{
		while (push > 0)
		{
			ft_pb(list, &push);
			if (push == 1)
				push--;
			push = push - 2;
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
