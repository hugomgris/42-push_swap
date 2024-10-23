/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:33:39 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/21 17:51:30 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_new_bmax(int value, t_dlist *b)
{
	t_dlist	*nb;

	nb = b;
	while (nb)
	{
		if (nb->content > value)
			return (0);
		nb = nb->next;
	}
	return (1);
}

int	ps_m_index(t_dlist *stack)
{
	t_dlist	*current;
	int		pos;
	int		mpos;
	int		mval;

	if (!stack)
		return (-1);
	pos = 0;
	mpos = 0;
	mval = INT_MIN;
	current = stack;
	while (current)
	{
		if (current->content > mval)
		{
			mval = current->content;
			mpos = pos;
		}
		current = current->next;
		pos++;
	}
	return (mpos);
}

t_lists	*ps_amax_to_top(t_lists *stacks, t_dlist *stack, int m_index)
{
	int	size;
	int	pm;

	size = ps_lstsize(stack);
	pm = size / 2;
	if (m_index < 0 || m_index >= size)
		return (stacks);
	if (m_index <= pm)
	{
		while (m_index > 0)
		{
			stacks = ps_ra(stacks, 0);
			m_index--;
		}
	}
	else
	{
		while (m_index < size)
		{
			stacks = ps_rra(stacks, 0);
			m_index++;
		}
	}
	return (stacks);
}

t_lists	*ps_bmax_to_top(t_lists *stacks, t_dlist *stack, int m_index)
{
	int	size;
	int	pm;

	size = ps_lstsize(stack);
	pm = size / 2;
	if (m_index < 0 || m_index >= size)
		return (stacks);
	if (m_index <= pm)
	{
		while (m_index > 0)
		{
			stacks = ps_rb(stacks, 0);
			m_index--;
		}
	}
	else
	{
		while (m_index < size)
		{
			stacks = ps_rrb(stacks, 0);
			m_index++;
		}
	}
	return (stacks);
}
