/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/08 10:51:54 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

//opti : just avt ra ou rra, check if put middle B in head needs also a rb or rrb

int		get_pivot(int gap, int misplaced, int size)
{
	printf("gap = %d VS all = %d\n", gap, misplaced * (size / 2) / 2);
	return (gap > (misplaced * (size / 2)) / 2 ? size / 2 : 0); 
}

int			main(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	t_data			data;
	t_data			new;
	int				way;
	t_list			*tmp;

	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	data.goal = make_goal(a);
	data.size = ac - 1;
	new = count_gap(a, data.goal, data.size);
	data.gap = new.gap;
	data.misplaced = new.misplaced;
	data.pivot = get_pivot(data.gap, data.misplaced, data.size);
	print_tab(data.goal, data.size);
	printf("max step = %d && misplaced=%d\n", data.gap, data.misplaced);
	printf("pivot = %d and rank is %d\n", data.goal[data.pivot], data.pivot);
	tmp = get_cible(&a, NULL, data);
	if (!tmp)
		exiting("A is sorted\n");
	printf("Oh no ! %d is not sorted !\n", tmp->nbr);
	way = forw_or_rew(get_value(&a, 4), get_value(&a, 7));
	printf("%d = way \n", way);
	if (way >= 0)
		printf("you ll go forw\n");
	else
		printf("you ll go rew\n");
	way = forw_or_rew(a, get_value(&a, 4));
	if (way >= 0)
		printf("you ll go forw\n");
	else
		printf("you ll go rew\n");
	dellist(&a);
	return (0);
}
