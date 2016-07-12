/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:18:03 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/23 16:33:39 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		make_line(char **buf, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = ft_get_char(buf[fd], '\n');
	if (i >= 0)
	{
		buf[fd][i] = '\0';
		*line = ft_strdup(buf[fd]);
		tmp = ft_strdup(buf[fd] + i + 1);
		ft_memdel((void**)&buf[fd]);
		buf[fd] = ft_strdup(tmp);
		ft_memdel((void**)&tmp);
		return (1);
	}
	if (buf[fd] && buf[fd][0] != '\0')
	{
		*line = ft_strdup(buf[fd]);
		ft_memdel((void**)&buf[fd]);
		return (1);
	}
	return (0);
}

int		ft_gnl(int fd, char **line)
{
	char		tmp[BUFF_SIZE + 1];
	static char	*buf[NB_FD];
	int			red;
	char		*tmp2;

	if (fd < 0 || BUFF_SIZE < 1 || (red = read(fd, tmp, BUFF_SIZE)) == -1)
		return (-1);
	tmp[red] = '\0';
	if (buf[fd])
	{
		tmp2 = ft_strdup(buf[fd]);
		ft_memdel((void**)&buf[fd]);
		buf[fd] = ft_strjoin(tmp2, tmp);
		ft_memdel((void**)&tmp2);
	}
	if (!buf[fd])
		buf[fd] = ft_strdup(tmp);
	if (ft_get_char(buf[fd], '\n') != -1 || red == 0)
		return (make_line(buf, &(*line), fd));
	return (ft_gnl(fd, &(*line)));
}
