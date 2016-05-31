/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:18:53 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/31 12:26:35 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	mem_tab(int **src, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (!(src[i] = (int*)malloc(sizeof(int))))
			exiting("Could not malloc");
		*src[i] = 2147483647;
		i++;
	}
}

t_data	count_gap(int **a, int **b, int size)
{
	int		i;
	int		ct;
	t_data	data;

	i = 0;
	data.misplaced = 0;
	data.step = 0;
	while (i < size)
	{	
		ct = 0;
		while (*b[i] != *a[ct])
			ct++;
		if (i - ct != 0)
			data.misplaced++;
		printf("abs return:%d\n", ft_abs(i - ct));
		data.step += ft_abs(i - ct);
		i++;
	}
	return (data);
}

int		**make_goal(int **src, int size)
{
	int		**out;
	int		i;
	int		cur;
	int		back;

	i = 0;
	if (!(out = (int**)malloc(sizeof(int*) * (size + 1))))
		return (NULL);
	mem_tab(out, size + 1);
	back = -2147483647;
	while (i < size)
	{
		cur = 0;
		while (cur < size)
		{
			if (back < *src[cur] && *src[cur] < *out[i])
				*out[i] = *src[cur];
			cur++;
		}
		back = *out[i];
		i++;
	}
	*out[size] = STOP;
	return (out);
}
