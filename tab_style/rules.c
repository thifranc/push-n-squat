/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:14:32 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/31 12:35:44 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		tablen(int **tab)
{
	int		i;

	i = 0;
	while (*tab[i] != STOP)
		i++;
	return (i);
}

void	push(int **a, int **b)
{
	if (!a[0])
		return ;
	if (tablen(b) == 0)
		*b[0] = *a[0];
	else
	{
		rev_rotate(b, tablen(b) + 1);
		*b[0] = *a[0];
	}
	*a[0] = STOP;
	rotate(a);//attention p-e segfault rotate + 1 si un seul elem
}

void	swapp(int **tab, int nb1, int nb2)
{
	int		*back;

	back = tab[nb1];
	tab[nb1] = tab[nb2];
	tab[nb2] = back;
}

void	rev_rotate(int **tab, int last)
{
	swapp(tab, 0, last);
	while (last && last - 1)
	{
		swapp(tab, last, last - 1);
		last--;
	}
}

void	rotate(int **tab)
{
	int		i;

	i = 0;
	while (*tab[i + 1] != STOP)
	{
		swapp(tab, i, i + 1);
		i++;
	}
}
