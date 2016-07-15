/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:13:31 by thifranc          #+#    #+#             */
/*   Updated: 2016/07/15 09:58:21 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*list_min(t_list **list)
{
	t_list	*tmp;
	t_list	*out;
	int		size;

	tmp = (*list)->next;
	out = *list;
	size = list_size(tmp) - 1;
	while (size)
	{
		if (out->nbr > tmp->nbr)
			out = tmp;
		tmp = tmp->next;
		size--;
	}
	return (out);
}

t_list	*list_max(t_list **list)
{
	t_list	*tmp;
	t_list	*out;
	int		size;

	tmp = (*list)->next;
	out = *list;
	size = list_size(tmp) - 1;
	while (size)
	{
		if (out->nbr < tmp->nbr)
			out = tmp;
		tmp = tmp->next;
		size--;
	}
	return (out);
}

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
	{
		dprintf(1, "keskispass\n");
		return (NULL);
	}
		//exiting("probleme ds get_value avec la value envoyee\n");
	//end debug
	return (tmp);
}

void	put_in_head(t_list **list, t_list *goal)
{
	if (!(*list))
		return ;
	if (forw_or_rew(*list, goal) >= 0)
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
