/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:04:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 14:50:50 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_data	count_gap(t_list *a, int *goal, int size)
{
	t_data	data;
	t_list	*tmp;
	int		i;
	int		ct;

	i = 0;
	data.gap = 0;
	data.misplaced = 0;
	tmp = a;
	while (i < size)
	{
		ct = nearest(&tmp, get_value(&tmp, goal[i]));
		if (ct)
			data.misplaced++;
		data.gap += ft_abs(ct);
		tmp = tmp->next;
		i++;
	}
	return (data);
}

int		get_min(t_list *list, int min, int size)
{
	int		out;

	out = 2147483647;
	while (size)
	{
		if (list->nbr > min && list->nbr < out)
			out = list->nbr;
		size--;
		list = list->next;
	}
	return (out);
}

int		*make_goal(t_list *list)
{
	int		size;
	int		*out;
	int		i;

	size = list_size(list);
	if (!(out = (int*)malloc(sizeof(int) * (size))))
		return (NULL);
	i = 0;
	out[0] = list->nbr;
	while (i < size)
	{
		if (list->nbr < out[0])
			out[0] = list->nbr;
		list = list->next;
		i++;
	}
	i = 0;
	while (++i < size)
		out[i] = get_min(list, out[i - 1], size);
	return (out);
}
