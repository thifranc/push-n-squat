/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:03:08 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/06 19:05:56 by thifranc         ###   ########.fr       */
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
				exiting("Error: Same number appeared twice\n");
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
		if (tmp < -2147483648 || tmp > 2147483647)
			exiting("Error: Number overflow int magnitude\n");
		add_node(&a, (int)tmp);
		i++;
	}
	double_check(a);
	return (a);
}
