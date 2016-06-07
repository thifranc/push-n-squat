/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 11:31:42 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int			main(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	t_data			data;
	int				*goal;
	int				pivot;

	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	goal = make_goal(a);
	pivot = ac / 2 - 1;//pivot doit decoule d'une estimation cf un ternaire
	printf("pivot = %d, rank = %d\n", goal[pivot], pivot);
	print_tab(goal, ac - 1);
	data = count_gap(a, goal, ac - 1);
	printf("max step = %d && misplaced=%d\n", data.gap, data.misplaced);
	printf("min is %d and max is %d\n", list_min(&a)->nbr, list_max(&a)->nbr);
	dellist(&a);
	return (0);
}
