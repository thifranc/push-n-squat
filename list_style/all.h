/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:50:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/11 16:29:11 by thifranc         ###   ########.fr       */
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

void				dellist(t_list **a);
void				min_in_first(t_list **b);
void				rb(t_list **b);
void				circle_list(t_list *list);
void				print_list(t_list *list, int ct);
void				add_node(t_list **list, int nbr);
void				pa(t_list **a, t_list **b, char *out);

#endif
