/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:32:14 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/09 10:52:09 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_median(t_elemt *elemt, int list, int len)
{
	int	i;
	int	*tab;
	int	median;

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
		median = tab[len / 2 - 1];
	else
		median = tab[len / 2];
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

void	ft_lstdel(t_elemt *elemt)
{
	t_elemt	*tmp;

	while (elemt)
	{
		tmp = elemt->next;
		free(elemt);
		elemt = tmp;
	}
	free(elemt);
}
