/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:30:05 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/20 11:16:11 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libc.h>

/*typedef struct		s_liste
{
	int				content;
	struct s_liste	*next;
}					t_liste;

typedef struct		s_pile
{
	t_liste			*b;
	t_liste			*a;
}					t_pile;
*/
typedef struct ss_list
{
    struct s_elemt *a;
    struct s_elemt *b;
}	t_liste;

typedef struct s_elemt
{
	int	val;
	struct s_elemt	*next;
	struct s_elemt	*prev;
}	t_elemt;


void	ft_error(char *msg);
int	ft_check_digit(char *str);
int ft_check_args(char **av);
t_elemt	*ft_lst_last(t_elemt *lst);
void	ft_sa(t_liste *list);
void		ft_rra(t_liste *list);
void		ft_ra(t_liste *list);
int main(int ac, char **av);

# endif
