/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lister.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:26:15 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/21 16:59:31 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*ps_lstnew(int content, int index)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ps_lstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

void	ps_lstadd_front(t_dlist **lst, t_dlist *new)
{
	if (*lst)
	{
		(*lst)->prev = new;
		new->next = *lst;
	}
	*lst = new;
}

int	ps_lstsize(t_dlist *lst)
{
	t_dlist	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
