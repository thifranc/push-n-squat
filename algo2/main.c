/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/14 09:08:18 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		get_rank(int *tab, int value, int size)
{
	int		i;

	i = 0;
	while (value != tab[i] && i < size)
		i++;
	//debug
	if (i == size)
		dprintf(1, "PROBLEME MAJEUR IN GET_RANK\n");
	//end debug
	return (i == size ? -1 : i);
}

void		stack_sort(t_list **a, t_list **b, t_data data)
{
	t_list	*cible;

	while ((cible = get_cible(&(*a), NULL, data)) != NULL
			|| (data.pivot != 0 && !is_full(*b, data.pivot)))
	{
		//print_list(*a);
		//print_list(*b);
		if (belongs_to(*a, data.goal, data.pivot) < 0)
		{
//			dprintf(1, "elem is in B\n");
			put_in_head(&(*b), get_cible(&(*b), *a, data));
			push(&(*a), &(*b));
		}
		else
		{
//			dprintf(1, "elem is in A\n");
			if (cible && nearest2(&(*a), nearest_b(&(*a), data.goal, data.pivot), cible) < 0)
			{
//				dprintf(1, "B is nearest, putting B elem in head\n");
				put_in_head(&(*a), nearest_b(&(*a), data.goal, data.pivot));
			}
			else if (cible && nearest2(&(*a), nearest_b(&(*a), data.goal, data.pivot), cible) > 0)
			{
//				dprintf(1, "A is nearest, want to sort A\n");
				put_in_head(&(*a), cible_updated(cible, get_value(&(*a),
						data.goal[get_rank(data.goal, cible->nbr, data.size) + 1])));
				swapp(&(*a));
			}
			else
			{
//				dprintf(1, "A is sorted\n");
				if (!data.pivot || is_full(*b, data.pivot))
				{
					return ;//sais pas si possible de rentrer la dedans qd mm
				}
				else
				{
					data.pivot += pivot_move(&(*a), &(*b), data.goal, data.pivot);
				}
			}
		}
	}
}

int			main(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	t_data			data;

	if (ac == 1)
		return (0);
	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	data.goal = make_goal(a);
	data.size = ac - 1;
	stack_sort(&a, &b, data);
	return (0);
}
