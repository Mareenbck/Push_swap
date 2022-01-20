/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:26:11 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/20 12:55:22 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/*int	*push_swap(int *list_a, int j)
{
	int middle;

	middle = j / 2;
	if (list_a[0] > list_a[middle] 
			&& list_a[middle] < list_a[j]
			&& list_a[j] < list_a[0])
		ft_r(list_a, j);
	else if (list_a[0] < list_a[middle] 
			&& list_a[middle] > list_a[j]
			&& list_a[j] < list_a[0])
		ft_rr(list_a);
	else 
		ft_s(list_a);
	return (list_a);
}*/

t_liste *ft_list_init(void *av)
{
   t_liste *list = malloc(sizeof(t_liste));
   t_elemt *elemt = malloc(sizeof(t_elemt));

    if (list == NULL || elemt == NULL)
        ft_error("init list failed");

    elemt->val = ft_atoi(av);
    elemt->next = NULL;
    elemt->prev = NULL;
    list->a = elemt;

    return (list);
}

void ft_lst_add_front(t_liste *list, char *val)
{
    t_elemt *new = malloc(sizeof(t_elemt));
    if (list == NULL || new == NULL)
        ft_error("add front failed");
  
    new->val = ft_atoi(val);

    /* Insertion de l'élément au début de la liste */
    new->next = list->a;
    list->a = new;
}

void ft_add_back(t_liste *list, char *val)
    t_elemt *new; 
    t_elemt *last; 
		
	new = malloc(sizeof(t_elemt));
    if (list == NULL || new == NULL)
    	ft_error("pile failed");
    new->val = ft_atoi(val);
    new->next = NULL;
    if (list->a != NULL)
    {
        last = ft_lst_last(list->a);
        last->next = new;
		new->prev = last;
    }
    else
        list->a = new;
}

int main(int ac, char **av)
{
	int i;
	t_liste	*list_a;
	t_elemt	*elemt;
	
	i = 1;
	if (ac < 2)
		ft_error("There is no args");
	ft_check_args(av);
	list_a = ft_list_init(av[1]); 
//	list_b = ft_list_init("0"); 
	while (av[++i])	
		ft_add_back(list_a, av[i]);
//	push_swap(&list_a, j);
	elemt = list_a->a;
	while (elemt != NULL)
	{
		printf("%d \n", elemt->val);
		elemt = elemt->next;
	}
	ft_sa(list_a);
	elemt = list_a->a;
	printf("--------------\n");
	while (elemt != NULL)
	{
		printf("%d \n", elemt->val);
		elemt = elemt->next;
	}
}

