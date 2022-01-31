/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:30:05 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/31 20:03:35 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

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

int		ft_check_digit(char *str);
int 	ft_check_args(char **av);
int		ft_check_sorted(t_elemt *elemt);
int	ft_check_sorted3_reverse(t_elemt *elemt);
int	ft_check_sorted_reverse(t_elemt *elemt);

t_elemt	*ft_lst_last(t_elemt *lst);
void	ft_sa(t_liste *list);
void	ft_rra(t_liste *list);
void	ft_ra(t_liste *list);
void	ft_pb(t_liste *list);
void	ft_sb(t_liste *list);
void	ft_rrb(t_liste *list);
void	ft_rb(t_liste *list);
void	ft_pa(t_liste *list);



int		ft_median(t_elemt *elemt, int list, int ac);
t_liste	*ft_petit_tri_a(t_liste *list);
t_liste	*ft_petit_tri_b(t_liste *list);

int	ft_len_list(t_elemt *elemt);
t_elemt	*ft_sort_a(t_liste *list, int len);
t_elemt	*ft_sort_b(t_liste *list, int len);

void	ft_sort_b_with_median(t_liste *list, int *push, int len);
void ft_sort_a_with_median(t_liste *list, int *push, int len);
t_liste	*ft_sort_3_a(t_liste *list);
t_liste	*ft_sort_3_b(t_liste *list);


# endif
