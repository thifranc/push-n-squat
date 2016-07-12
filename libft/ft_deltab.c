/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:07:23 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/31 10:35:07 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltab(void **data)
{
	int		i;

	i = 0;
	while (data[i])
	{
		ft_memdel((void**)&data[i]);
		i++;
	}
}
