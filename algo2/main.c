/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/14 11:22:22 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"


t_list		*longest_row(t_list **list, t_data data)
{
	int		i;
	t_list	*tmp;
	int		back[2];
	int		count[2];

	i = 0;
	back[0] = 0;
	back[1] = 0;
	while (i < data.size)
	{
		tmp = get_value(&(*list), data.goal[i]);
		count[0] = i;
		count[1] = 0;
		while (i < data.size && data.goal[i + 1] == tmp->next->nbr)
		{
			tmp = tmp->next;
			i++;
			count[1]++;
		}
		if (count[1] > back[1])
		{
			back[0] = count[0];
			back[1] = count[1];
		}
		i++;
	}
	return (get_value(&(*list), data.goal[back[0]]));
}

int			get_gap(t_list **list, t_data data)
{
	int		i;
	int		size;
	int		misplaced;
	t_list	*tmp;

	size = list_size(*list);
	tmp = *list; // should use longest_row
	i = 0;	//is related to longest_row
	printf("i is %d and tmp is %d\n", i, tmp->nbr);
	misplaced = 0;
	while (i < data.size) //wrong
	{
		while (size && tmp->next->nbr != data.goal[i + 1])
		{
			printf("YES i is %d and tmp is %d\n", i, tmp->nbr);
			tmp = tmp->next;
			size--;
			misplaced++;
			//i++;
		}
		if (!size)
			return (misplaced);
		tmp = tmp->next;
		i++;
	}
	return (misplaced);
}

/*
void		stack_sort(t_list **a, t_list **b, t_data data)
{
	int		count;

	count = 0;
	get_gap();
	while (gap)
	{
		if (gap > HUGE)
		{
			quick_sort(count);
			count++;
		}
		else
			insertion_sort();
		get_gap();
	}
}
*/

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
	printf("longest row begins at %d\n", longest_row(&a, data)->nbr);
	printf("gap is %d\n", get_gap(&a, data));
	//stack_sort(&a, &b, data);
	return (0);
}
