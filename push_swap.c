/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:26:11 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/05 14:08:57 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_error("");
	if (len == 2 && (list->a->val > list->a->next->val))
		ft_sa(list);
	else if (len == 3)
		ft_sort_3_a(list);
	else
		ft_sort_a(list, len);
	ft_lstdel(list->a);
	ft_lstdel(list->b);
}

t_liste	*ft_init_push_swap(char **av, int i)
{
	t_liste	*list;

	ft_check_args(av);
	list = ft_list_init();
	while (av[i])
	{
		ft_add_back(list, ft_atoi(av[i]));
		i++;
	}
	return (list);
}

int	main(int ac, char **av)
{
	t_liste	*list;
	char	**tab;

	if (ac < 2)
		ft_error("");
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		list = ft_init_push_swap(tab, 0);
		ft_free_tab(tab);
	}
	else
		list = ft_init_push_swap(av, 1);
	push_swap(list);
	free(list);
	return (0);
}
