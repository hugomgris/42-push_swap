/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:08:52 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/22 11:33:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_mid_return(t_lists *stacks, int value)
{
	t_dlist	*current;
	int		pos;
	int		a_pos;
	int		a_size;

	current = stacks->a;
	a_pos = 0;
	pos = 0;
	a_size = ps_lstsize(stacks->a);
	while (a_size > 0)
	{
		if (value > ps_lstlast(stacks->a)->content
			&& value < stacks->a->content)
			return (0);
		if (current->prev && value > current->prev->content
			&& value < current->content)
			a_pos = pos;
		if (!current->next && current->prev
			&& value > current->prev->content && value < current->content)
			a_pos = pos;
		pos++;
		current = current->next;
		a_size--;
	}
	return (a_pos);
}

int	ps_b_pos_in_a(t_lists *stacks, int value)
{
	if (ps_new_bmin(value, stacks->a))
	{
		stacks = ps_amin_to_top(stacks, stacks->a, ps_s_index(stacks->a));
		return (0);
	}
	else if (ps_new_bmax(value, stacks->a))
	{
		stacks = ps_amin_to_top(stacks, stacks->a, ps_m_index(stacks->a));
		return (0);
	}
	else
		return (ps_mid_return(stacks, value));
}

t_lists	*ps_return_num(t_lists *stacks, int value)
{
	int		a_pos;
	int		a_size;

	a_pos = ps_b_pos_in_a(stacks, value);
	a_size = ps_lstsize(stacks->a);
	if (a_pos < (a_size / 2))
	{
		while (a_pos)
		{
			stacks = ps_ra(stacks, 0);
			a_pos--;
		}
	}
	else
	{
		while (a_pos < a_size)
		{
			stacks = ps_rra(stacks, 0);
			a_pos++;
		}
	}
	stacks = ps_pa(stacks, 0);
	return (stacks);
}
