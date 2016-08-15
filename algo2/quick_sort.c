/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 20:20:58 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/15 12:13:41 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*get_pivot(t_data data, t_list *list, int count)
{
	int		max;
	int		i;
	int		size;
	t_list	*pivot;

	i = 1;
	size = list_size(list);
	pivot = NULL;
	add_node(&pivot, list_min(&list)->nbr);
	max = ft_power(2, count);
	while (i < max)
	{
		add_node(&pivot, data.goal[i * size / max]);
		i++;
	}
	add_node(&pivot, list_max(&list)->nbr);
	return (pivot);
}

int		next_stop(t_list *a, int pivot, int end)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->nbr != pivot && tmp->nbr != end)
		tmp = tmp->next;
	if (tmp->nbr == pivot)
		return (end);
	else
		return (pivot);
}

void	quick_sort(t_list **a, t_list **b, t_data data, int count)
{
	t_list	*tmp;
	int		next;

	tmp = get_pivot(data, *a, count);
	put_in_head(&(*a), get_value(&(*a), tmp->nbr));
	while (tmp && tmp->next)//a faire encore une fois pour le last time
	{
		next = next_stop(*a, tmp->next->nbr, tmp->next->next->nbr);
		while ((*a)->nbr != next)
		{
			if ((*a)->nbr >= tmp->next->nbr)
				push(&(*a), &(*b));
			else
				*a = (*a)->next;
		}
		if ((*a)->nbr == tmp->next->nbr)
		{
			*a = (*a)->next;
			while (*b)
				push(&(*b), &(*a));
		}
		else if (*b)
		{
			put_in_head(&(*b), get_value(&(*b), tmp->next->nbr)->next);
			while (*b)
				push(&(*b), &(*a));
		}
		tmp = tmp->next->next;
	}
}
