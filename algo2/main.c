/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/17 11:23:50 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

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

void		wesh(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	dprintf(1, "LIST PRINT IS ONl\n");
	while (tmp)
	{
		dprintf(1, "tmp is %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	dprintf(1, "LIST PRINT IS OFF\n");
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

int			stack_sort(t_list **a, t_list **b, t_data data, int count)
{
	int		gap;
	int		step;

	step = 0;
	gap = get_gap(&(*a), data);
	while (gap)
	{
		step += quick_sort(&(*a), &(*b), data, count);
		count++;
		gap = get_gap(&(*a), data);
	}
	printf("number of steps == %d\n", step);
	return (step);
}

int			mega_sort(int ac, char **av)
{
	t_list			*a;
	t_list			*b;
	t_list			*c;
	t_list			*d;
	t_data			data;
	int				out;
	int				gap;
	int		quick;
	int		insert;
	int		count;

	if (ac == 1)
		return (0);
	b = NULL;
	c = NULL;
	d = NULL;
	out = 0;
	count = 1;
	a = list_arg(ac, av);
	circle_list(a);
	data.goal = make_goal(a);
	data.size = ac - 1;
	gap = get_gap(&a, data);
	while (gap)
	{//passer ca en recursif
		b = copy_list(a);
		c = copy_list(a);
		quick = stack_sort(&b, &d, data, count);
		insert = insert_sort(&c, &d, data);
		if (insert < quick)
			out += insert_sort(&a, &d, data);
		else
			out += quick_sort(&a, &d, data, count);
		gap = get_gap(&a, data);
		count++;
	}
	return (out);
}

int		main(int ac, char **av)
{
	int		quick;
	int		merged;
	int		insert;
	t_list			*a;
	t_list			*b;
	t_data			data;

	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	data.goal = make_goal(a);
	data.size = ac - 1;

	quick = stack_sort(&a, &b, data, 1);
	insert = thibault(ac, av);
	merged = mega_sort(ac, av);
	printf("%d is quick and %d is insert and %d is merged\n", quick, insert, merged);

	return (0);
}
