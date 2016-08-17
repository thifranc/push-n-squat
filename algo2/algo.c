/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:10:08 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/17 11:18:30 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*get_cible(t_list **a, t_list *elem, t_data data)
{
	int		size;
	t_list	*tmp;

	tmp = NULL;
	size = data.size - 1;
		if (!(*a))
			return (NULL);
		size = list_size(*a);
		tmp = list_max(&(*a));
		while (size)
		{
			if (elem->nbr > tmp->nbr)
				return (tmp);
			tmp = tmp->next;
			size--;
		}
		return (list_max(&(*a)));
}
