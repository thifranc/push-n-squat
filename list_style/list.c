/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:49:51 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/11 15:30:39 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*new_node(int nbr)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	new->prev = NULL;
	new->str = NULL;
	return (new);
}

void	add_node(t_list **list, int nbr)
{
	if (!(*list))
		(*list) = new_node(nbr);
	else if (!(*list)->next)
	{
		(*list)->next = new_node(nbr);
		((*list)->next)->prev = (*list);
	}
	else
		add_node(&(*list)->next, nbr);
}

void	print_list(t_list *list, int ct)
{
	t_list	*tmp;
	int		first;
	int		i;

	i = 0;
	if (!list)
		return ;
	while (i < ct)
	{
		tmp = list;
		first = tmp->nbr;
		tmp = tmp->next;
		ft_putnbr(first);
		write(1, "\n", 1);
		while (tmp->nbr != first)
		{
			ft_putnbr(tmp->nbr);
			write(1, "\n", 1);
			tmp = tmp->next;
		}
		i++;
	}
}

void	circle_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (!list)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = list;
	list->prev = tmp;
}

void	min_in_first(t_list **b)
{
	int		first;
	int		min;

	first = (*b)->nbr;
	min = (*b)->nbr;
	*b = (*b)->next;
	while ((*b)->nbr != first)
	{
		if ((*b)->nbr > min)
			min = (*b)->nbr;
		(*b) = (*b)->next;
	}
	while ((*b)->nbr != min)
		rb(&(*b));
}
