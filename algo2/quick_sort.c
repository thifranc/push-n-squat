/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 20:20:58 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/15 09:18:50 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*get_pivot(t_data data, t_list *list, int count)
{
	int		max;
	int		i;
	int		size;
	t_list	*pivot;

	i = 0;
	size = list_size(list);
	pivot = NULL;
	max = ft_power(2, count);
	while (i < max)
	{
		add_node(&pivot, data.goal[i * size / max]);
		i++;
	}
	return (pivot);
}

void	load(t_list **a, t_list *stop, t_list **b, int pivot_ahead)
{
	if (!stop)
		return ;
	while ((*a)->nbr != stop->nbr)
	{
		dprintf(1, "A= %d && stop= %d\n", (*a)->nbr, stop->nbr);
		if (pivot_ahead && (*a)->nbr > stop->nbr)
			push(&(*a), &(*b));
		else if (!pivot_ahead && (*a)->nbr < stop->nbr)
			push(&(*a), &(*b));
		*a = (*a)->next;
	}
}

t_list	*hay_in_list(t_list **list, int value, int inf)
{
	t_list	*tmp;
	int		size;

	tmp = *list;
	size = list_size(tmp);
	while (size)
	{
		if (inf && tmp->nbr < value)
			return (tmp);
		if (!inf && tmp->nbr > value)
			return (tmp);
		tmp = tmp->next;
		size--;
	}
	return (NULL);
}

void	unload(t_list **a, t_list *stop, t_list **b, int pivot_ahead)
{
	t_list	*to_unload;

	if (!stop)
		return ;
	put_in_head(&(*a), get_value(&(*a), stop->nbr));
	if (pivot_ahead)
	{
		while ((to_unload = hay_in_list(&(*b), stop->nbr, 1)) != NULL)
		{
			put_in_head(&(*b), get_value(&(*b), to_unload->nbr));
			push(&(*b), &(*a));
		}
	}
	else
	{
		while ((to_unload = hay_in_list(&(*b), stop->nbr, 0)) != NULL)
		{
			put_in_head(&(*b), get_value(&(*b), to_unload->nbr));
			push(&(*b), &(*a));
		}
	}
}

void	quick_sort(t_list **a, t_list **b, t_data data, int count)
{
	t_list	*pivot;
	t_list	*stop;
	t_list	*tmp;

	tmp = get_pivot(data, *a, count);
	while (tmp && tmp->next) //a faire encore une fois pour le last time
	{
		print_list(*a);
		pivot = tmp->next;
		stop = pivot->next;
		put_in_head(&(*a), get_value(&(*a), tmp->nbr));
		load(&(*a), pivot, &(*b), 1);
		load(&(*a), stop, &(*b), 0);
		unload(&(*a), pivot, &(*b), 1);
		unload(&(*a), stop, &(*b), 0);
		tmp = tmp->next->next;
	}
}
