/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:05:56 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/22 14:55:53 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_index(int n, t_dlist *stack)
{
	t_dlist	*current;
	int		pos;
	int		cpos;

	if (!stack)
		return (-1);
	pos = -1;
	cpos = 0;
	current = stack;
	while (current)
	{
		if (current->content == n)
			pos = cpos;
		cpos++;
		current = current->next;
	}
	return (pos);
}

int	ps_a_pos_in_b(t_lists *stacks, int value)
{
	t_dlist	*c;
	int		pos;
	int		b_pos;

	c = stacks->b;
	b_pos = 0;
	pos = 0;
	while (c)
	{
		if (ps_new_bmax(value, stacks->b) || ps_new_bmin(value, stacks->b))
		{
			b_pos = ps_m_index(stacks->b);
			break ;
		}
		else if (c->prev && value > c->content && value < c->prev->content)
		{
			b_pos = pos;
			break ;
		}
		pos++;
		c = c->next;
	}
	if (!c)
		b_pos = 0;
	return (b_pos);
}
