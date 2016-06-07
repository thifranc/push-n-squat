/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 21:15:03 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int			main(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	t_data			data;
	t_data			new;
	int				way;
	//t_list			*tmp;

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
	way = forw_or_rew(get_value(&a, 7), get_value(&a, 8));
	printf("%d = way \n", way);
	if (way > 0)
		printf("you ll go forw\n");
	else
		printf("you ll go rew\n");
	dellist(&a);
	return (0);
}
