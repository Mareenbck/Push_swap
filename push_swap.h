/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:30:05 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/09 15:59:19 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct ss_list
{
	struct s_elemt	*a;
	struct s_elemt	*b;
}	t_liste;

typedef struct s_elemt
{
	int				val;
	struct s_elemt	*next;
}	t_elemt;

/*******_call_a_*******/
t_elemt	*ft_sort_a(t_liste *list, int len);
void	ft_push_a(t_liste *list, int *push);
void	ft_reverse_a(t_liste *list, int *rotate);

/*******_call_b_*******/
t_elemt	*ft_sort_b(t_liste *list, int len);
void	ft_push_b(t_liste *list, int *push);
void	ft_reverse_b(t_liste *list, int *rotate);

/*******_sort_a_*******/
t_liste	*ft_sort_3_a(t_liste *list);
t_liste	*ft_petit_tri_a(t_liste *list);
void	ft_sort_a_with_median(t_liste *list, int *push, int *rotate, int len);

/*******_sort_b_*******/
t_liste	*ft_sort_3_b(t_liste *list);
t_liste	*ft_petit_tri_b(t_liste *list);
void	ft_sort_b_with_median(t_liste *list, int *push, int *rotate, int len);

/*******_utils_*******/
void	ft_error(char *msg);
void	**ft_free_tab(char **tab);
int		ft_median(t_elemt *elemt, int list, int len);
int		ft_len_list(t_elemt *elemt);
void	ft_lstdel(t_elemt *elemt);

/*******_check_*******/
int		ft_check_digit(char *str);
int		ft_check_overflow(char *av);
int		ft_check_args(char **av, int i, int tab);
int		ft_check_sorted(t_elemt *elemt);
int		ft_check_sorted_reverse(t_elemt *elemt);

/*******_move_b_*******/
void	ft_rb(t_liste *list);
void	ft_rrb(t_liste *list);
void	ft_sb(t_liste *list);
void	ft_pa(t_liste *list);

/*******_move_a_*******/
t_elemt	*ft_lst_last(t_elemt *lst);
void	ft_sa(t_liste *list);
void	ft_rra(t_liste *list);
void	ft_ra(t_liste *list);
void	ft_pb(t_liste *list);

/*******_push_swap_*******/
t_liste	*ft_list_init(void);
void	ft_add_back(t_liste *list, int val);
t_liste	*ft_init_push_swap(char **av, int i, int tab);
void	push_swap(t_liste *list);
void	ft_error_tab(char **av, int tab);

#endif
