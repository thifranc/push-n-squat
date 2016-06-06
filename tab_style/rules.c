/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:14:32 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/06 11:44:13 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		tablen(int **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	push(int **a, int **b)
{
	if (!a[0])
		return ;
	if (tablen(b) == 0)
	{
		b[0] = b[1] - 1;
		*b[0] = *a[0];
		b[1] = NULL;
	}
	else
	{
		swapp(b, tablen(b) + 1, 0);//je mets un valeur = 0 en tete
		swapp(b, tablen(b), tablen(b) + 1);//je decale mon NULL derriere last elem
		*b[0] = *a[0];
	}//attention cette technique n'est pas protegee si B est full (swap de 0 avec tablen(b) + 1 est indetermine car celui-ci ne sera pas init a 0)
	*a[0] = 0;//prepare mon nouveau 0 en stock
	rotate(a, tablen(a));//0 en stock juste avant NULL ptr
	swapp(a, tablen(a), tablen(a - 1));//swap 0 et NULL
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

void	rotate(int **tab, int last)
{
	int		i;

	i = 0;
	while (last && i + 1 < last)//projet last = tablen(tab);
	{
		swapp(tab, i, i + 1);
		i++;
	}
}
