/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:26:11 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/31 20:03:11 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	ft_median(t_elemt *elemt, int list, int len)
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
  if (i % 2 == 0 && list == 1)
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
    ft_error("Error\n");
  list->a = NULL;
	list->b = NULL;
	return (list);
}

void ft_add_back(t_liste *list, int val)
{
    t_elemt *new;
    t_elemt *last;

	new = malloc(sizeof(t_elemt));
    if (list == NULL || new == NULL)
      ft_error("Error\n");
    new->val = val;
    new->next = NULL;
    if (list->a != NULL)
    {
        last = ft_lst_last(list->a);
        last->next = new;
    }
    else
        list->a = new;
}

void	push_swap(t_liste *list)
{
	int len;

	len = ft_len_list(list->a);
	if (ft_check_sorted(list->a))
		printf("Cest trie");
	if  (len == 2 && (list->a->val > list->a->next->val))
		ft_sa(list);
	else if (len == 3)
		ft_sort_3_a(list);
	else
		ft_sort_a(list, len);

	//PRINT FINAL

	// t_elemt *elemt = list->a;
	// printf("-----FINAL-----\n");
	// while (elemt != NULL)
	// {
	// 	printf("a : %d\n", elemt->val);
	// 	elemt = elemt->next;
	// }

}

int main(int ac, char **av)
{
	int i;
	t_liste	*list;

	i = 1;
	if (ac < 2)
    ft_error("Error\n");
  ft_check_args(av);
	list = ft_list_init();
	while (av[i])
	{
		ft_add_back(list, ft_atoi(av[i]));
		i++;
	}
	// t_elemt	*elemt;
	// elemt = list->a;
	// printf("-----BEGIN-----\n");
	// while (elemt != NULL)
	// {
	// 	printf("%d \n", elemt->val);
	// 	elemt = elemt->next;
	// }
	push_swap(list);
}

