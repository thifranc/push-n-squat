/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/17 11:19:18 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

//opti : just avt ra ou rra, check if put middle B in head needs also a rb or rrb

int			insert_sort(t_list **a, t_list **b, t_data data)
{
	int		count;
	t_data	new;

	new = count_gap(*a, data.goal, data.size);
	data.gap = new.gap;
	data.misplaced = new.misplaced;
	data.pivot = data.size;
	count = 0;
	while (*a)
	{
		put_in_head(&(*b), get_cible(&(*b), *a, data), &count);
		push(&(*a), &(*b), &count);
	}
	if (list_max(&(*b)))
	{
		put_in_head(&(*b), list_max(&(*b)), &count);
		while (*b)
			push(&(*b), &(*a), &count);
	}
	print_list(*a);
	return (count);
}

int			thibault(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	t_data			data;
	int				count;

	count = 0;
	if (ac == 1)
		return (0);
	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	data.goal = make_goal(a);
	data.size = ac - 1;


	count = insert_sort(&a, &b, data);

	return (count);
}
