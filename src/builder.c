/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:24:16 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/21 10:18:25 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*ps_lstfirst(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

void	ps_lstclear(t_dlist **lst)
{
	t_dlist	*current;
	t_dlist	*tmp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current -> next;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

t_lists	*list_builder(t_lists *stacks, char **argv)
{
	int		i;
	int		tmp;
	t_dlist	*new_node;

	i = 0;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		new_node = ps_lstnew(tmp, i);
		if (!new_node)
		{
			free(stacks);
			ps_lstclear(&stacks->a);
			return (NULL);
		}
		if (!stacks->a)
			stacks->a = new_node;
		else
			ps_lstadd_back(&stacks->a, new_node);
		i++;
	}
	return (stacks);
}
