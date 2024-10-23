/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:51:06 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/22 14:57:12 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*ps_execute_continue(t_lists *stacks, t_order *order)
{
	while (order->rrb)
	{
		ps_rrb(stacks, 0);
		order->rrb--;
	}
	while (order->rrr)
	{
		ps_rrr(stacks, 0);
		order->rrr--;
	}
	return (stacks);
}

t_lists	*ps_execute(t_lists *stacks, t_order *order)
{
	while (order->ra)
	{
		ps_ra(stacks, 0);
		order->ra--;
	}
	while (order->rb)
	{
		ps_rb(stacks, 0);
		order->rb--;
	}
	while (order->rr)
	{
		ps_rr(stacks, 0);
		order->rr--;
	}
	while (order->rra)
	{
		ps_rra(stacks, 0);
		order->rra--;
	}
	stacks = ps_execute_continue(stacks, order);
	stacks = ps_pb(stacks, 0);
	return (stacks);
}
