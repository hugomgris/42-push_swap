/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_manager2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:20:13 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/22 17:20:14 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_order	*ps_order_init(t_order *order)
{
	order->ra = 0;
	order->rb = 0;
	order->rra = 0;
	order->rrb = 0;
	order->rr = 0;
	order->rrr = 0;
	order->sa = 0;
	order->sb = 0;
	return (order);
}

t_order	*ps_order_discounter(t_order *order)
{
	while (order->ra && order->rb)
	{
		order->ra--;
		order->rb--;
		order->rr++;
	}
	while (order->rra && order->rrb)
	{
		order->rra--;
		order->rrb--;
		order->rrr++;
	}
	return (order);
}

t_order	*ps_order(t_lists *stacks, t_order *order, int a, int b)
{
	order = ps_order_init(order);
	order = ps_fill_order(stacks, order, a, b);
	order = ps_order_discounter(order);
	return (order);
}
