/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:32:52 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/16 11:29:07 by thifranc         ###   ########.fr       */
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

void	swapp(t_list **a, int *count)
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
	(*count)++;
//	dprintf(1, "swapp\n");
}

void	rev_rotate(t_list **list, int *count)
{
	(*list) = (*list)->prev;
	(*count)++;
//	dprintf(1, "rev_rot\n");
}

void	rotate(t_list **list, int *count)
{
	(*list) = (*list)->next;
	(*count)++;
//	dprintf(1, "rot\n");
}

void	push(t_list **a, t_list **b, int *count)
{
	t_list	*head;

//debug
	if (!(*a))
		dprintf(1, "segfault cause push called with nothing to push  from\n");
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
//	dprintf(1, "push\n");
	(*count)++;
}
