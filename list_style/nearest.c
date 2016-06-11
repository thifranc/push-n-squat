/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:47:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/11 10:53:45 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*nearest_b(t_list **a, int *goal, int pivot)
{//attention ne pas appeler si pivot = 0 => boucle infinie
	int		forw;
	int		rew;
	int		back;
	t_list	*tmp;

	forw = 0;
	rew = 0;
	tmp = *a;
	dprintf(1, "dbar\n");
	if (!pivot)//du coup y a pas de B possib
		return (NULL);
	while (tmp->nbr >= goal[pivot])
	{
		forw++;
		tmp = tmp->next;
	}
	back = tmp->nbr;
	tmp = *a;
	while (tmp->nbr >= goal[pivot])
	{
		rew++;
		tmp = tmp->prev;
	}
	dprintf(1, "tg\n");
	return (rew < forw ? tmp : get_value(&(*a), back));
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

/*int		nearest(t_list **list, t_list *goal)//get rid of bearest in other calls
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
}*/
