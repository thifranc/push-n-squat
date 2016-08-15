/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/15 09:17:00 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		wesh(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("tmp is %d\n", tmp->nbr);
		tmp = tmp->next;
	}
}

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

t_list	*get_value_classic(t_list **list, int value)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->nbr != value)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (tmp);
}

int			next_placed(t_list **list, t_data data, int beg, int end)
{
	if (!*list)
		return (beg + 1);
	if (!get_value_classic(&(*list), data.goal[beg + 1]))
		return (beg + 1);
	while (beg != end && get_value_classic(&(*list), data.goal[beg + 1]))
	{
		if (beg == data.size)
			beg = 0;
		else
			beg++;
	}
	return (beg + 1);
}

int			list_count(t_list *list)
{
	if (!list)
		return (0);
	else
		return (1 + list_count(list->next));
}

int			get_gap(t_list **list, t_data data)
{
	int		i;
	int		size;
	int		back;
	t_list	*misplaced;
	t_list	*tmp;

	size = list_size(*list);
	tmp = longest_row(&(*list), data);
	i = get_rank(data.goal, tmp->nbr, data.size);
	misplaced = NULL;
	i == data.size ? (back = -1) : (back = i - 1);
	while (i != back)
	{
		if (!size)
			return (list_count(misplaced));
		if (tmp->nbr == data.goal[i])
			i = next_placed(&misplaced, data, i, back);
		else
			add_node(&misplaced, tmp->nbr);
		size--;
		tmp = tmp->next;
	}
	return (list_count(misplaced));
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
	quick_sort(&a, &b, data, 1);
	print_list(a);
	print_list(b);
	//stack_sort(&a, &b, data);
	return (0);
}
