/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:26:11 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/26 10:17:57 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	ft_median(t_elemt *elemt, int len)
{
	int i;
	int *tab;
	int median;

	i = 0;
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	while (i < len)
	{
		tab[i] = elemt->val;
		i++;
		elemt = elemt->next;
	}
	tab = ft_sort_int_tab(tab, len);

	if (i % 2 == 0)
		median = tab[i / 2 - 1];
	else
		median = tab[i / 2];
	free(tab);
	return (median);
}


int	ft_len_list(t_elemt *elemt)
{
 	int	len;

	len = 0;
 	while (elemt != NULL)
 	{
 		len++;
 		elemt = elemt->next;
 	}
 	return (len);
}

t_liste *ft_list_init(void)
{
	t_liste *list = malloc(sizeof(t_liste));
	if (list == NULL)
		ft_error("init list failed");
	list->a = NULL;
	list->b = NULL;
	return (list);
}

// t_liste *ft_list_init(void *av)
// {
//    t_liste *list = malloc(sizeof(t_liste));
//    t_elemt *elemt = malloc(sizeof(t_elemt));

//     if (list == NULL || elemt == NULL)
//         ft_error("init list failed");

//     elemt->val = ft_atoi(av);
//     elemt->next = NULL;
//     elemt->prev = NULL;
//     list->a = elemt;

//     return (list);
// }


void ft_add_back(t_liste *list, int val)
{
    t_elemt *new; 
    t_elemt *last; 
		
	new = malloc(sizeof(t_elemt));
    if (list == NULL || new == NULL)
    	ft_error("pile failed");
    new->val = val;
    new->next = NULL;
    if (list->a != NULL)
    {
        last = ft_lst_last(list->a);
        last->next = new;
		//new->prev = last;
    }
    else
        list->a = new;
}

void	push_swap(t_liste *list)
{
	int len;

	len = ft_len_list(list->a);
	if (ft_check_sorted(list->a))
		ft_error("Sorted !");
	if (len == 3)
		ft_sort_3_a(list);
	else if (len == 2 && (list->a->val > list->a->next->val))
		ft_sa(list);
	else
		ft_sort_a(list, len);

	//PRINT FINAL
	t_elemt *elemt = list->a;

	printf("-----FINAL-----\n");
	while (elemt != NULL)
	{
		printf("a : %d\n", elemt->val);
		elemt = elemt->next;
	}

}

// void	push_swap(t_var *arg)
// {
// 	if (!check_doubles(arg) || !check_numbers(arg))
// 	{
// 		ft_free_tab(arg->tab);
// 		//free var;
// 		return ;
// 	}
// 	arg->len = ft_fill_stack(arg);
// 	if (!check_sorted_a(arg))
// 		ft_error("Error : list of arguments already sorted\n", 1);
// 	if (arg->len == 2)
// 		ft_sort_2_a(arg);
// 	else if (arg->len == 3)
// 		ft_sort_3_a(arg);
// 	else
// 		ft_sort_a(arg, arg->len);
	
// }

int main(int ac, char **av)
{
	int i;
	// int	median;
	t_liste	*list;
	t_elemt	*elemt;
	
	i = 1;
	if (ac < 2)
		ft_error("There is no args");
	ft_check_args(av);
	list = ft_list_init(); 
	while (av[i])	
	{
		ft_add_back(list, ft_atoi(av[i]));
		i++;
	}
	elemt = list->a;
	printf("-----BEGIN-----\n");
	while (elemt != NULL)
	{
		printf("%d \n", elemt->val);
		elemt = elemt->next;
	}
	printf("-----ACTION----\n");
	push_swap(list);
}

