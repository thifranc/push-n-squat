/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:50:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/15 21:51:28 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include "libft/libft.h"

typedef struct		s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			*str;
	int				nbr;
}					t_list;

typedef struct		s_data
{
	int				misplaced;
	int				gap;
	int				*goal;
	int				pivot;
	int				size;
}					t_data;

int					*make_goal(t_list *list);
int					get_min(t_list *list, int min, int size);
t_data				count_gap(t_list *list, int *goal, int size);

t_list				*get_cible(t_list **a, t_list *elem, t_data data);
t_list				*cible_updated(t_list *cible, t_list *sup);

void				double_check(t_list *a);
t_list				*list_arg(int ac, char **av);
long long			ft_atoll(char *str);

void				dellist(t_list **a);
void				circle_list(t_list *list);
int					list_size(t_list *list);
t_list				*list_min(t_list **list);
t_list				*list_max(t_list **list);
void				add_node(t_list **list, int nbr);

void				print_list(t_list *list);
void				print_tab(int *list, int size);

void				rotate(t_list **list, int *count);
void				push(t_list **a, t_list **b, int *count);
void				rev_rotate(t_list **list, int *count);
void				swapp(t_list **a, int *count);

int					nearest(t_list **list, t_list *goal);
int					nearest2(t_list **list, t_list *one, t_list *two);
int					forw_or_rew(t_list *one, t_list *two);
t_list				*nearest_b(t_list **list, int *goal, int pivot);

int					is_full(t_list *b, int pivot);
int					belongs_to(t_list *elem, int *goal, int pivot);

void				put_in_head(t_list **list, t_list *goal, int *count);
t_list				*get_value(t_list **list, int value);
int					get_rank(int *tab, int value, int size);
#endif
