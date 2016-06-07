/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 15:42:12 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int			main(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	t_data			data;
	t_data			new;
	t_list			*tmp;

	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	data.goal = make_goal(a);
	data.size = ac - 1;
	data.pivot = ac / 2 - 1;//pivot doit decoule d'une estimation cf un ternaire
	printf("pivot = %d, rank = %d\n", data.goal[data.pivot], data.pivot);
	print_tab(data.goal, ac - 1);
	print_list(a);
	new = count_gap(a, data.goal, data.size);
	data.gap = new.gap;
	data.misplaced = new.misplaced;
	printf("max step = %d && misplaced=%d\n", data.gap, data.misplaced);
	tmp = get_cible(&a, NULL, data);
	if (!tmp)
		printf("A is sorted\n");
	else
		printf("the cible for A is %d\n", tmp->nbr);
	dellist(&a);
	return (0);
}
