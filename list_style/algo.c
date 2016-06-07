/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:10:08 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 21:25:59 by thifranc         ###   ########.fr       */
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
	t_list	*tmp;

	size = data.size - 1;
	printf("%d=======segfault && goal end = %d\n", data.size, data.goal[size - 1]);
	if (!elem)//get_cible for A
	{
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
	return (get_value(&(*a), data.goal// == valeur juste dessous elem ds goal
				[ft_get_rank(data.goal, elem->nbr, data.size) - 1]));
}
