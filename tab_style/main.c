/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:14:54 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/31 12:41:53 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

long long	ft_atoll(char *str)
{
	int					i;
	int					sign;
	long long int		out;
	int					tmp;

	i = 0;
	sign = 0;
	out = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		tmp = str[i] - 48;
		out = out * 10 + tmp;
		i++;
	}
	if (str[i])
		exiting("Error: Numbers entered are not correct\n");
	if (sign)
		out = -out;
	return (out);
}

void		double_check(int **tab, int size)
{
	int		i;
	int		b;

	i = 0;
	while (i < size)
	{
		b = i + 1;
		while (b < size)
		{
			if (*tab[b] == *tab[i])
				exiting("Same number appeared twice\n");
			b++;
		}
		i++;
	}
}

int			**make_tab(int ac, char **av)
{
	int			i;
	int			**a;
	long long	tmp;

	i = 1;
	if (ac < 2 || !(a = (int**)malloc(sizeof(int*) * (ac))))
		return (NULL);
	while (i < ac)
	{
		tmp = (int)atoll(av[i]);
		if (tmp == STOP)
			exiting("A nb is a STOP nb. Change the header file svp\n");
		if (tmp < -2147483647 || tmp > 2147483648)
			exiting("Error: Number overflow int magnitude\n");
		if (!(a[i - 1] = (int*)malloc(sizeof(int))))
			return (0);
		*a[i - 1] = (int)tmp;
		i++;
	}
	if (!(a[i - 1] = (int*)malloc(sizeof(int))))
		return (0);
	*a[i - 1] = STOP;//THIS ONE ISNT MALLOC MAYBE SEGFAULT WILL COME
	return (a);
}

//note:rotate attention si un seul elem tj malloc de 2 ac tab[1] = NULL

int			main(int ac, char **av)
{
	int		**a;
	int		**b;
	int		**goal;
	t_data	data;

	if (!(a = make_tab(ac, av)))
		exiting("Couldn't create tab\n");
	//faire un wild_cases correect svp
	b = (int**)malloc(sizeof(int*) * ac);
	mem_tab(b, ac, STOP);
	double_check(a, ac - 1);
	print_tab(a);
	goal = make_goal(a, ac - 1);
	data = count_gap(a, goal, ac -1);
	printf("GAP:%d, misplace:%d\n", data.step, data.misplaced);
	dprintf(1, "goal coming\n");
	print_tab(goal);
	dprintf(1, "goal end\n");
	rotate(a);
	dprintf(1, "rotated\n");
	print_tab(a);
	dprintf(1, "rev_rotated\n");
	rev_rotate(a, ac - 2);
	print_tab(a);
	dprintf(1, "pushed on b\n");
	push(a, b);
	print_tab(a);
	dprintf(1, "a is up and b is down\n");
	print_tab(b);
	return (0);
}
