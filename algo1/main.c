/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/15 21:55:57 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

//opti : just avt ra ou rra, check if put middle B in head needs also a rb or rrb

int		get_pivot(int gap, int misplaced, int size)
{
	return (gap > (misplaced * (size / 2)) / 2 ? size / 2 : 0); 
}

int		pivot_move(t_list **a, t_list **b, int *goal, int pivot, int *count)
{

	if (!get_value(&(*a), goal[pivot]))//goal[pivot] is in B
	{
		put_in_head(&(*b), list_max(&(*b)), count);
		push(&(*b), &(*a), count);
	}
	return (-1);
}//do data.pivot += pivot_move;

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

void		stack_sort(t_list **a, t_list **b, t_data data, int *count)
{
	t_list	*cible;

	while ((cible = get_cible(&(*a), NULL, data)) != NULL
			|| (data.pivot != 0 && !is_full(*b, data.pivot)))
	{
		if (belongs_to(*a, data.goal, data.pivot) < 0)
		{
			put_in_head(&(*b), get_cible(&(*b), *a, data), count);
			push(&(*a), &(*b), count);
		}
		else
		{
			if (cible && nearest2(&(*a), nearest_b(&(*a), data.goal, data.pivot), cible) < 0)
				put_in_head(&(*a), nearest_b(&(*a), data.goal, data.pivot), count);
			else if (cible && nearest2(&(*a), nearest_b(&(*a), data.goal, data.pivot), cible) > 0)
			{
				put_in_head(&(*a), cible_updated(cible, get_value(&(*a),
						data.goal[get_rank(data.goal, cible->nbr, data.size) + 1])), count);
				swapp(&(*a), count);
			}
			else
			{
				if (!data.pivot || is_full(*b, data.pivot))
					return ;//sais pas si possible de rentrer la dedans qd mm
				else
					data.pivot += pivot_move(&(*a), &(*b), data.goal, data.pivot, count);
			}
		}
	}
}

int			main(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	t_data			data;
	t_data			new;
	int				count;

	count = 0;
	if (ac == 1)
		return (0);
	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	data.goal = make_goal(a);
	data.size = ac - 1;

	new = count_gap(a, data.goal, data.size);
	data.gap = new.gap;
	data.misplaced = new.misplaced;
	data.pivot = get_pivot(data.gap, data.misplaced, data.size);

	stack_sort(&a, &b, data, &count);

	put_in_head(&a, list_min(&a), &count);
	if (list_max(&b))
	{
		put_in_head(&b, list_max(&b), &count);
		while (b)
			push(&b, &a, &count);
	}
	print_list(a);
	printf("%d == nb de coups to solve this\n", count);
	dellist(&a);
	return (0);
}
