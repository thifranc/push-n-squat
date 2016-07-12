/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 11:06:28 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/30 11:07:11 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc(char **var, int add, int del)
{
	int		i;
	char	**new;

	i = 0;
	while (var[i])
		i++;
	if (!(new = (char**)malloc(sizeof(char*) * (i + 1 + add))))
		return (NULL);
	i = 0;
	while (var[i])
	{
		new[i] = ft_strdup(var[i]);
		if (del)
			ft_memdel((void**)&var[i]);
		i++;
	}
	if (del)
		ft_memdel((void**)&var[i]);
	new[i] = NULL;
	while (add)
		new[i + add--] = NULL;
	return (new);
}
