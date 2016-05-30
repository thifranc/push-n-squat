/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:14:32 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/30 15:37:49 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		tablen(int **tab)
{
	int		i;

	i = 0;
	while (*tab[i] != STOP)
	{
		dprintf(1, "tab=%d\n", *tab[i]);
		i++;
	}
	printf("tablen==%d\n", i);
	return (i);
}

void	push(int **a, int **b)
{
	if (!a[0])
		return ;
	if (tablen(b) == 0)
	{
		dprintf(1, "yo");
		*b[0] = *a[0];
	}
	else
	{
		rev_rotate(b, tablen(b) + 1);
		*b[0] = *a[0];
	}
	dprintf(1, "beg3\n");
	a[0] = NULL;
	dprintf(1, "beg4\n");
	rotate(a);//attention p-e segfault rotate + 1 si un seul elem
	dprintf(1, "END\n");
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
