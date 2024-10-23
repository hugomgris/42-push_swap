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

t_dlist	*ps_lstlast(t_dlist	*lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_dlist	*ps_secondlast(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}
