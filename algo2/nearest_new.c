/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:47:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/07/15 10:51:39 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*nearest_b(t_list **a, int *goal, int pivot)
{//attention ne pas appeler si pivot = 0 => boucle infinie
	t_list	*tmp;
	int		dir;
	int		size;

	tmp = *a;
	size = list_size(*a);
	while (size && tmp->nbr >= goal[pivot])
	{
		tmp = tmp->next;
		size--;
	}
	if (!size)
		return (NULL);
	else
	{
		dir = forw_or_rew(*a, get_value(&(*a), goal[pivot]));
		tmp = *a;
		while (tmp->nbr >= goal[pivot])
		{
			if (dir < 0)
				tmp = tmp->prev;
			else
				tmp = tmp->next;
		}
	}
	return (tmp);
}

//nearest b et cible == nearest2(nearest_b, cible)

int		nearest2(t_list **list, t_list *one, t_list *two)
{
	int		one_min;
	int		two_min;

	if (!one)
		return (1);
	if (!two)
		return (-1);
	one_min = ft_abs(forw_or_rew(*list, one));
	two_min = ft_abs(forw_or_rew(*list, two));
	return (one_min <= two_min ? -1 : 1);
}

int		forw_or_rew(t_list *move, t_list *fixe)
{
	int		forw;
	int		rew;
	t_list	*tmp;

	forw = 0;
	rew = 0;
	tmp = move;
	while (tmp != fixe)
	{
		forw++;
		tmp = tmp->next;
	}
	tmp = move;
	while (tmp != fixe)
	{
		rew++;
		tmp = tmp->prev;
	}
	return (forw <= rew ? forw : -rew);
}
