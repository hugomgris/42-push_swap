/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:06:46 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/20 15:46:57 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*c;

	if (!lst)
		return ;
	c = *lst;
	while (c)
	{
		node = c->next;
		ft_lstdelone(c, del);
		c = node;
	}
	*lst = NULL;
}
