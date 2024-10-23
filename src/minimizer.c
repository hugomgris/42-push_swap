/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:03:09 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/21 16:29:13 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_new_bmin(int value, t_dlist *b)
{
	t_dlist	*nb;

	nb = b;
	while (nb)
	{
		if (nb->content < value)
			return (0);
		nb = nb->next;
	}
	return (1);
}

int	ps_s_index(t_dlist *stack)
{
	t_dlist	*current;
	int		pos;
	int		spos;
	int		sval;

	if (!stack)
		return (-1);
	pos = 0;
	spos = 0;
	sval = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->content < sval)
		{
			sval = current->content;
			spos = pos;
		}
		current = current->next;
		pos++;
	}
	return (spos);
}

t_lists	*ps_amin_to_top(t_lists *stacks, t_dlist *stack, int s_index)
{
	int	size;
	int	pm;
	int	i;

	size = ps_lstsize(stack);
	pm = size / 2;
	if (s_index < 0 || s_index >= size)
		return (stacks);
	if (s_index <= pm)
	{
		i = 0;
		while (i++ < s_index)
			stacks = ps_ra(stacks, 0);
	}
	else
	{
		i = size;
		while (i-- > s_index)
			stacks = ps_rra(stacks, 0);
	}
	return (stacks);
}

t_lists	*ps_bmin_to_top(t_lists *stacks, t_dlist *stack, int s_index)
{
	int	size;
	int	pm;
	int	i;

	size = ps_lstsize(stack);
	pm = size / 2;
	if (s_index < 0 || s_index >= size)
		return (stacks);
	if (s_index <= pm)
	{
		i = 0;
		while (i++ < s_index)
			stacks = ps_rb(stacks, 0);
	}
	else
	{
		i = size;
		while (i-- > s_index)
			stacks = ps_rrb(stacks, 0);
	}
	return (stacks);
}
