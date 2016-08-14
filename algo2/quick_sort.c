/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 20:20:58 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/14 20:38:45 by thifranc         ###   ########.fr       */
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
