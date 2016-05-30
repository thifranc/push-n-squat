/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:08:34 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/11 17:11:55 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		ft_error(int code)
{
	if (code == 1)
		ft_putstr("Error: Numbers entered are not correct\n");
	if (code == 2)
		ft_putstr("Error: Number overflow int magnitude\n");
	if (code == 3)
		ft_putstr("Same number appeared twice\n");
	exit(-1);
}

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
		ft_error(1);
	if (sign)
		out = -out;
	return (out);
}

void		double_check(t_list *a)
{
	t_list	*tmp;
	t_list	*rabbit;

	tmp = a;
	while (tmp)
	{
		rabbit = tmp->next;
		while (rabbit)
		{
			if (rabbit->nbr == tmp->nbr)
				ft_error(3);
			rabbit = rabbit->next;
		}
		tmp = tmp->next;
	}
}

t_list		*list_arg(int ac, char **av)
{
	long long int	tmp;
	t_list			*a;
	int				i;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ft_atoll(av[i]);
		if (tmp < -2147483647 || tmp > 2147483648)
			ft_error(2);
		add_node(&a, (int)tmp);
		i++;
	}
	double_check(a);
	return (a);
}

int			main(int ac, char **av)
{
	int				first;
	t_list			*a;
	t_list			*b;

	b = NULL;
	a = list_arg(ac, av);
	circle_list(a);
	print_list(a, 1);
	pa(&a, &b, ft_strdup("pa "));
	while (a)
	{
		first = b->nbr;
		while (b->next->nbr != first && a->nbr < b->nbr)
			rb(&b);
		if (b->next->nbr == first && a->nbr < b->nbr)
			rb(&b);
		pa(&a, &b, ft_strdup("pa "));
		min_in_first(&b);
	}
	while (b)
		pa(&b, &a, ft_strdup("pb "));
	write(1, "\n", 1);
	print_list(a, 1);
	dellist(&a);
	return (0);
}
