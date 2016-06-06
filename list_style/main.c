/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/06 19:23:29 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int			main(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	int				*goal;

	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	goal = make_goal(a);
	printf("nearest is %d\n", nearest2(&a, get_value(&a, 8), get_value(&a, 8)));
	dellist(&a);
	return (0);
}
