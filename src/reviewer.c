/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reviewer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:05:57 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/16 19:03:45 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_lists *stacks)
{
	int		size;
	int		i;
	t_dlist	*tmp;

	tmp = stacks->a;
	size = ps_lstsize(tmp);
	i = 0;
	while (i < size - 1)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
