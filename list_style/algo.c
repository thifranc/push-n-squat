/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:10:08 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 13:40:50 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*get_cible(t_list **a, t_list *elem,
		int *goal, int size, int pivot)//data struct to pass
{
	if (!elem)//get_cible for A
	{
		tmp = get_value(&(*a), goal[size]);
		while (tmp->nbr != goal[size - 1])
		{
			tmp = tmp->prev;
			if (tmp->nbr != goal[size - 1] &&
				tmp->nbr >= goal[pivot])//pivot to include
				return (get_value(&(*a), goal[size]));
			if (tmp->nbr == goal[size - 1])
				size--;
			if (size == pivot)
				return (NULL);//A is sorted
		}
	}
	else//get for B
		return (get_value(goal[ft_get_rank(goal, elem->nbr, size) - 1]));
}
