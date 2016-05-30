/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:32:52 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/12 10:09:12 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	dellist(t_list **b)
{
	int		first;

	if (!(*b))
		return ;
	first = (*b)->nbr;
	(*b) = (*b)->next;
	while ((*b)->nbr != first)
	{
		*b = (*b)->next;
		free((*b)->prev);
	}
}

void	ft_putstr_del(char *str)
{
	write(1, str, ft_strlen(str));
	free(str);
}

void	pa(t_list **a, t_list **b, char *out)
{
	t_list	*head;

	head = (*a)->next;
	if (*a == (*a)->next)
		head = NULL;
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	if (*b)
	{
		(*a)->next = *b;
		(*a)->prev = (*b)->prev;
		(*b)->prev->next = *a;
		(*b)->prev = *a;
		*b = (*b)->prev;
	}
	else
	{
		*b = *a;
		(*b)->next = *b;
		(*b)->prev = *b;
	}
	*a = head;
	if (head == NULL && out[1] == 'b')
		out[2] = '\0';
	ft_putstr_del(out);
}

void	rb(t_list **b)
{
	*b = (*b)->next;
	write(1, "rb ", 3);
}
