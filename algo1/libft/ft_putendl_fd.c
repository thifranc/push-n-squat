/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:40:39 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/01 13:48:48 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*out;
	int		len;

	len = ft_strlen(s);
	if (!(out = (char*)malloc(sizeof(char) * (len + 2))))
		return ;
	ft_strcpy(out, s);
	out[len] = '\n';
	out[len + 1] = '\0';
	write(fd, out, len + 2);
	ft_memdel((void**)&out);
}
