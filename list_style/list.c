/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:49:51 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/08 10:46:08 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*new_node(int nbr)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	new->prev = NULL;
	new->str = NULL;
	return (new);
}

void	add_node(t_list **list, int nbr)
{
	if (!(*list))
		(*list) = new_node(nbr);
	else if (!(*list)->next)
	{
		(*list)->next = new_node(nbr);
		((*list)->next)->prev = (*list);
	}
	else
		add_node(&(*list)->next, nbr);
}

int		list_size(t_list *head)
{
	t_list	*first;
	t_list	*tmp;
	int		out;

	if (!head)
		return (0);
	out = 1;
	first = head;
	tmp = head;
	tmp = tmp->next;
	while (first != tmp)
	{
		tmp = tmp->next;
		out++;
	}
	return (out);
}

void	print_list(t_list *list)
{
	t_list	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = list;
	size = list_size(tmp);
	printf("list will be printed\n");
	while (size)
	{
		printf("%d and str =%s\n", tmp->nbr, tmp->str);
		tmp = tmp->next;
		size--;
	}
}

void	print_tab(int *tab, int size)
{
	int		i;

	i = 0;
	printf("tab will be printed\n");
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

void	circle_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (!list)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = list;
	list->prev = tmp;
}
