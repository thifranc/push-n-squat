/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:50:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/17 11:45:50 by thifranc         ###   ########.fr       */
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

typedef struct		s_pivot
{
	struct s_pivot	*next;
	struct s_pivot	*prev;
	int				nbr;
}					t_pivot;

typedef struct		s_data
{
	int				gap;
	int				pivot;
	int				misplaced;
	int				*goal;
	int				size;
}					t_data;

void				wesh(t_list *list);
int					thibault(int ac, char **av);
int					insert_sort(t_list **a, t_list **b, t_data data);

t_list				*get_pivot(t_data data, t_list *list, int count);
int					get_pivot2(int gap, int misplaced, int size);
int					quick_sort(t_list **a, t_list **b, t_data data, int count);

int					*make_goal(t_list *list);
int					get_min(t_list *list, int min, int size);
t_data				count_gap(t_list *list, int *goal, int size);

t_list				*get_cible(t_list **a, t_list *elem, t_data data);
t_list				*cible_updated(t_list *cible, t_list *sup);

void				double_check(t_list *a);
t_list				*list_arg(int ac, char **av);
long long			ft_atoll(char *str);

void				dellist(t_list **a);
t_list				*copy_list(t_list *a);
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

int					nearest2(t_list **list, t_list *one, t_list *two);
int					forw_or_rew(t_list *one, t_list *two);
void				put_in_head(t_list **list, t_list *goal, int *count);

t_list				*get_value(t_list **list, int value);
int					get_rank(int *tab, int value, int size);
#endif
