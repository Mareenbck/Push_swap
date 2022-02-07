/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:07:03 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/07 10:22:19 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			|| (str[i] == '-' && !ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && !ft_isdigit(str[i + 1])))
			ft_error("Error\n");
		i++;
	}
	return (1);
}

int	ft_check_overflow(char *av)
{
	long long	nb;

	nb = ft_atoll(av);
	if (nb >= INT_MIN && nb <= INT_MAX)
		return (1);
	ft_error("Error\n");
	return (0);
}

int	ft_check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoll(av[i]) == ft_atoll(av[j]))
				ft_error("Error \n");
			j++;
		}
		ft_check_digit(av[i]);
		ft_check_overflow(av[i]);
		i++;
	}
	return (1);
}

int	ft_check_sorted(t_elemt *elemt)
{
	while (elemt->next != NULL)
	{
		if (elemt->next && elemt->val < elemt->next->val)
			elemt = elemt->next;
		else
			return (0);
	}
	return (1);
}

int	ft_check_sorted_reverse(t_elemt *elemt)
{
	while (elemt->next != NULL)
	{
		if (elemt->next && elemt->val > elemt->next->val)
			elemt = elemt->next;
		else
			return (0);
	}
	return (1);
}
