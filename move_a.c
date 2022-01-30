/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:13:35 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/30 11:27:39 by marinebas        ###   ########.fr       */
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

void		ft_ra(t_liste *list)
{
	t_elemt	*last;
	t_elemt *top;
	t_elemt *elemt = list->a;
	printf("\n-----RA-----");
	printf("\na : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	t_elemt *elemtb = list->b;
	printf("\nb : ");
	while (elemtb != NULL)
	{
		printf("%d ", elemtb->val);
		elemtb = elemtb->next;
	}
	if (list->a != NULL && list->a->next)
	{
		last = list->a;
		list->a = list->a->next;
		top = list->a;
		last->next = NULL;
		last->prev = top;
		list->a = ft_lst_last(list->a);
		list->a->next = last;
		list->a = top;
	}
	elemt = list->a;
	printf("\n-----RA-----");
	printf("\na : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	elemtb = list->b;
	printf("\nb : ");
	while (elemtb != NULL)
	{
		printf("%d ", elemtb->val);
		elemtb = elemtb->next;
	}
	//write(1, "\nra", 3);
	printf("\n-------------\n");
}

void		ft_rra(t_liste *list)
{
	t_elemt *elemt = list->a;	 
	
	printf("\n-----RRA-----");
	printf("\na : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	t_elemt *elemtb = list->b;
	printf("\nb : ");
	while (elemtb != NULL)
	{
		printf("%d ", elemtb->val);
		elemtb = elemtb->next;
	}
//***************CODE ICI*******************	
	t_elemt	*top;
	t_elemt *tmp;

	if (list->a != NULL)
	{
		top = list->a;
		while (list->a->next->next)
			list->a = list->a->next;
		tmp = list->a->next;
		list->a->next = NULL;
		tmp->next = top;
		tmp->prev = NULL;
		list->a = tmp;
	}
//	write(1, "rra\n", 4);
//******************************************
	elemt = list->a;
	printf("\n----RRA-----");
	printf("\na : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	elemt = list->b;
	printf("\nb : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	printf("\n-------------\n");
}

void	ft_sa(t_liste *list)
{
	 t_elemt *elemt = list->a;	 
	
	printf("\n-----SA-----");
	printf("\na : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	t_elemt *elemtb = list->b;
	printf("\nb : ");
	while (elemtb != NULL)
	{
		printf("%d ", elemtb->val);
		elemtb = elemtb->next;
	}
//***************CODE ICI*******************	
	t_elemt *tmp;

	if (list->a != NULL)
	{
		tmp = list->a->next;
		list->a->next = list->a->next->next;
		tmp->next = list->a;
		tmp->prev = NULL;
		list->a = tmp;
	}
//	write(1, "sa\n", 3);
//******************************************
	elemt = list->a;
	printf("\n-----SA-----");
	printf("\na : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	elemt = list->b;
	printf("\nb : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	printf("\n-------------\n");
}

void	ft_pb(t_liste *list)
{
	 t_elemt *elemt = list->a;	 
	
	printf("\n-----PB-----");
	printf("\na : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	t_elemt *elemtb = list->b;
	printf("\nb : ");
	while (elemtb != NULL)
	{
		printf("%d ", elemtb->val);
		elemtb = elemtb->next;
	}
//***************CODE ICI*******************
	t_elemt *tmp = list->a;
	if (list->a)
	{
		tmp = list->a->next;
		list->a->next = list->b;
		list->b = list->a;
		list->a = tmp;
	}
//******************************************
	elemt = list->a;
	printf("\n-----PB-----");
	printf("\na : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	elemt = list->b;
	printf("\nb : ");
	while (elemt != NULL)
	{
		printf("%d ", elemt->val);
		elemt = elemt->next;
	}
	//printf("-------------");
	//write(1, "pb\n", 3);
	printf("\n-------------\n");
}
