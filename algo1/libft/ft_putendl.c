/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:16:49 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/28 11:33:34 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	char	*out;
	int		len;

	len = ft_strlen(s);
	if (!(out = (char*)malloc(sizeof(char) * (len + 2))))
		return ;
	ft_strcpy(out, s);
	out[len] = '\n';
	out[len + 1] = '\0';
	write(1, out, len + 2);
	ft_memdel((void**)&out);
}
