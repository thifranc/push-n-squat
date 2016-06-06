/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/06 22:05:17 by thifranc         ###   ########.fr       */
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
	pivot = goal[ac / 2 - 1];
	printf("pivot = %d, rank = %d\n", pivot, ac / 2);
	print_tab(goal, ac - 1);
	data = count_gap(a, goal, ac - 1);
	printf("max step = %d && misplaced=%d\n", data.gap, data.misplaced);
	dellist(&a);
	return (0);
}
