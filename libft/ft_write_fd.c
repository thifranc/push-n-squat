/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:40:39 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/01 14:58:17 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write_fd(char *s, int fd)
{
	char	*out;
	int		len;

	len = ft_strlen(s);
	if (!(out = (char*)malloc(sizeof(char) * (len + 1))))
		return ;
	ft_strcpy(out, s);
	out[len] = '\n';
	write(fd, out, len + 1);
	ft_memdel((void**)&out);
}
