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

int	ps_position_bcost(int b_size, int position, t_order **order)
{
	if (position <= b_size / 2)
	{
		(*order)->rb += position;
		return (position);
	}
	else
	{
		(*order)->rrb += (b_size - position);
		return (b_size - position);
	}
}

int	ps_position_acost(int a_size, int position, t_order **order)
{
	if (position < a_size / 2)
	{
		(*order)->ra += position;
		return (position);
	}
	else
	{
		(*order)->rra += (a_size - position);
		return (a_size - position);
	}
}

int	ps_discounter(int cost, t_order **order)
{
	if ((*order)->ra && (*order)->rb)
	{
		while ((*order)->ra && (*order)->rb)
		{
			(*order)->ra--;
			(*order)->rb--;
			(*order)->rr++;
			cost--;
		}
	}
	if ((*order)->rra && (*order)->rrb)
	{
		while ((*order)->rra && (*order)->rrb)
		{
			(*order)->rra--;
			(*order)->rrb--;
			(*order)->rrr++;
			cost--;
		}
	}
	return (cost);
}

int	ps_final_cost(t_lists *stacks, int value, t_order **order)
{
	int	cost;
	int	position;
	int	a_size;
	int	b_size;

	cost = 1;
	a_size = ps_lstsize(stacks->a);
	b_size = ps_lstsize(stacks->b);
	if (ps_new_bmax(value, stacks->b) || ps_new_bmin(value, stacks->b))
		position = ps_m_index(stacks->b);
	else
		position = ps_a_pos_in_b(stacks, value);
	cost += ps_position_bcost(b_size, position, order);
	position = ps_index(value, stacks->a);
	cost += ps_position_acost(a_size, position, order);
	cost = ps_discounter(cost, order);
	return (cost);
}

int	ps_cheapest_position(t_lists *stacks, t_order **order)
{
	int		cheapest;
	int		cost;
	int		pos;
	int		cheapest_pos;
	t_dlist	*ac;

	cheapest = INT_MAX;
	pos = 0;
	ac = stacks->a;
	while (ac)
	{
		*order = ps_order_init(*order);
		cost = ps_final_cost(stacks, ac->content, order);
		if (cost < cheapest)
		{
			cheapest = cost;
			cheapest_pos = pos;
		}
		pos++;
		ac = ac->next;
	}
	return (cheapest_pos);
}
