/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:54:38 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/21 08:44:02 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*ps_lstswap(t_dlist *first)
{
	t_dlist	*tmp;
	t_dlist	*second;

	if (!first || !first->next)
		return (first);
	tmp = first;
	second = first->next;
	first = second;
	tmp->next = second->next;
	first->next = tmp;
	first->prev = NULL;
	tmp->prev = first;
	if (tmp->next)
		tmp->next->prev = tmp;
	return (first);
}

t_lists	*ps_lstpushb(t_lists *stacks)
{
	t_dlist	*tmp;
	t_dlist	*new_node;

	if (!stacks->a)
		return (stacks);
	new_node = ps_lstnew(stacks->a->content, stacks->a->index);
	if (!new_node)
		return (stacks);
	if (!stacks->b)
		stacks->b = new_node;
	else
		ps_lstadd_front(&stacks->b, new_node);
	tmp = stacks->a->next;
	free(stacks->a);
	stacks->a = tmp;
	if (stacks->a)
		stacks->a->prev = NULL;
	return (stacks);
}

t_lists	*ps_lstpusha(t_lists *stacks)
{
	t_dlist	*tmp;
	t_dlist	*new_node;

	if (!stacks->b)
		return (stacks);
	new_node = ps_lstnew(stacks->b->content, stacks->b->index);
	if (!new_node)
		return (stacks);
	if (!stacks->a)
		stacks->a = new_node;
	else
		ps_lstadd_front(&stacks->a, new_node);
	tmp = stacks->b->next;
	free(stacks->b);
	stacks->b = tmp;
	if (stacks->b)
		stacks->b->prev = NULL;
	return (stacks);
}

t_dlist	*ps_lstrotate(t_dlist *lst)
{
	t_dlist	*second;
	t_dlist	*last;

	if (!lst || !lst->next)
		return (lst);
	second = lst->next;
	last = ps_lstlast(lst);
	second->prev = NULL;
	last->next = lst;
	lst->prev = last;
	lst->next = NULL;
	lst = second;
	return (lst);
}

t_dlist	*ps_lstrrotate(t_dlist *lst)
{
	t_dlist	*last;
	t_dlist	*slast;

	if (!lst || !lst->next)
		return (lst);
	last = ps_lstlast(lst);
	slast = ps_secondlast(lst);
	if (slast)
	{
		slast->next = NULL;
	}
	last->next = lst;
	last->prev = NULL;
	lst->prev = last;
	return (last);
}
