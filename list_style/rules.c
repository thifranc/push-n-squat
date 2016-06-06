/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:32:52 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/06 14:24:48 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	dellist(t_list **b)
{
	int		first;

	if (!(*b))
		return ;
	first = (*b)->nbr;
	(*b) = (*b)->next;
	while ((*b)->nbr != first)
	{
		*b = (*b)->next;
		free((*b)->prev);
	}
}

void	swapp(t_list **a)
{
	t_list	*swapper;

	swapper = (*a)->next;
	(*a)->next = swapper->next;
	(*a)->next->prev = (*a);
	(*a)->prev->next = swapper;
	swapper->prev = (*a)->prev;
	(*a)->prev = swapper;
	swapper->next = *a;
	(*a) = swapper;//head over the new head
}

void	rev_rotate(t_list **list)
{
	(*list) = (*list)->prev;
}

void	rotate(t_list **list)
{
	(*list) = (*list)->next;
}

void	push(t_list **a, t_list **b)
{
	t_list	*head;

	//debug
	if (!(*a))
		dprintf(1, "program will segfault cause push been called with nothing tu push from\n");
	//end of debug
	head = (*a)->next;
	if (*a == (*a)->next)
		head = NULL;
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	if (*b)
	{
		(*a)->next = *b;
		(*a)->prev = (*b)->prev;
		(*b)->prev->next = *a;
		(*b)->prev = *a;
		*b = (*b)->prev;
	}
	else
	{
		*b = *a;
		(*b)->next = *b;
		(*b)->prev = *b;
	}
	*a = head;
}
