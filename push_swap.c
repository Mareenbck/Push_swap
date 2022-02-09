/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:26:11 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/09 15:56:57 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_tab(char **av, int tab)
{
	if (tab)
		ft_free_tab(av);
	ft_error("Error\n");
}

t_liste	*ft_list_init(void)
{
	t_liste	*list;

	list = malloc(sizeof(t_liste));
	if (!list)
	{
		ft_lstdel(list->a);
		ft_error("Error\n");
	}
	list->a = NULL;
	list->b = NULL;
	return (list);
}

void	ft_add_back(t_liste *list, int val)
{
	t_elemt	*new;
	t_elemt	*last;

	new = malloc(sizeof(t_elemt));
	if (!new)
		return ;
	if (list == NULL)
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
	int	len;

	len = ft_len_list(list->a);
	if (ft_check_sorted(list->a))
	{
		ft_lstdel(list->a);
		free(list);
		ft_error("");
	}
	if (len == 2 && (list->a->val > list->a->next->val))
		ft_sa(list);
	else if (len == 3)
		ft_sort_3_a(list);
	else
		ft_sort_a(list, len);
	ft_lstdel(list->a);
	ft_lstdel(list->b);
}

t_liste	*ft_init_push_swap(char **av, int i, int tab)
{
	t_liste	*list;

	ft_check_args(av, i, tab);
	list = ft_list_init();
	while (av[i])
	{
		ft_add_back(list, ft_atoi(av[i]));
		i++;
	}
	return (list);
}
