/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:00:48 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 13:02:11 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_rank(int *tab, int value, int size)
{
	int		i;

	i = 0;
	while (tab[i] != value && i < size)
		i++;
	return (i == size ? -1 : i);
}
