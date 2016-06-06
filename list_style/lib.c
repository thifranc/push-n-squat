/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:13:31 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/06 22:14:09 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*get_value(t_list **list, int value)
{
	t_list	*tmp;
	int		size;

	tmp = *list;
	size = list_size(tmp);
	while (tmp->nbr != value && size)
	{
		tmp = tmp->next;
		size--;
	}
	//debug
	if (!size)
		exiting("probleme ds get_value avec la value envoyee\n");
	//end debug
	return (tmp);
}

int		nearest2(t_list **list, t_list *one, t_list *two)
{
	int		one_min;
	int		two_min;

	one_min = ft_abs(nearest(&(*list), one));
	two_min = ft_abs(nearest(&(*list), two));
	return (one_min <= two_min ? -1 : 1);
}

int		nearest(t_list **list, t_list *goal)
{
	t_list	*tmp;
	int		forward;
	int		rewind;

	forward = 0;
	rewind = 0;
	tmp = *list;
	while (tmp != goal)
	{
		tmp = tmp->next;
		forward++;
	}
	tmp = *list;
	while (tmp != goal)
	{
		tmp = tmp->prev;
		rewind++;
	}
	return (forward <= rewind ? forward : -rewind);
}

void	place_in_head(t_list **list, t_list *goal)
{
	if (nearest(&(*list), goal) >= 0)
	{
		dprintf(1, "forward\n");
		while ((*list) != goal)
			rotate(&(*list));
	}
	else
	{
		dprintf(1, "rewind\n");
		while ((*list) != goal)
			rev_rotate(&(*list));
	}
}
