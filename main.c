/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:54:18 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/09 15:56:48 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_liste	*list;
	char	**tab;

	if (ac < 2)
		ft_error("");
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			ft_error("");
		tab = ft_split(av[1], ' ');
		list = ft_init_push_swap(tab, 0, 1);
		ft_free_tab(tab);
	}
	else
		list = ft_init_push_swap(av, 1, 0);
	push_swap(list);
	free(list);
	return (0);
}
