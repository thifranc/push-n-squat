/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:10:08 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/11 13:34:22 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		is_full(t_list *b, int pivot)
{
	return (list_size(b) == pivot ? 1 : 0);//attention peut etre pivot - 1
}

int		belongs_to(t_list *elem, int *goal, int pivot)
{
	return (elem->nbr >= goal[pivot] ? 1 : -1);
}

t_list	*cible_updated(t_list *cible, t_list *sup)
{
	return (forw_or_rew(cible, sup) < 0 ? cible->prev : cible);
}

t_list	*get_cible(t_list **a, t_list *elem, t_data data)
{
	int		size;
	int		lol;
	t_list	*tmp;

	tmp = NULL;
	size = data.size - 1;
	if (!elem)//get_cible for A
	{
		dprintf(1, "elem is in A\n");
		tmp = get_value(&(*a), data.goal[size]);
		while (tmp->nbr != data.goal[size - 1])
		{
			tmp = tmp->prev;
			if (tmp->nbr != data.goal[size - 1] &&
				tmp->nbr >= data.goal[data.pivot])
				return (get_value(&(*a), data.goal[size - 1]));
			if (tmp->nbr == data.goal[size - 1])
				size--;
			if (size == data.pivot)
				return (NULL);//A is sorted
		}
	}
	else
	{
		dprintf(1, "elem is in B\n");
		lol = get_rank(data.goal, elem->nbr, data.size);
		dprintf(1, "is in B\n");
		printf("%d=end of B and %d=cible of B\n", data.goal[data.pivot - 1], data.goal[lol - 1]);
		while (!tmp)
		{
		lol ? (tmp = get_value(&(*a), data.goal[lol - 1])) : (tmp = get_value(&(*a), data.goal[data.pivot - 1]));
		lol--;
		}
		dprintf(1, "B cible =>%d\n", tmp->nbr);
		//pb ac get_value car B est NULL so far
		//-1 car cible pr B est premier directement inferieur a notre val actuelle
		//pour get_rank = 0, return goal[size];
		return (tmp);
	}
	return (NULL);
}
