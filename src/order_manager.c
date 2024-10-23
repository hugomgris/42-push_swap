/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:27:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/22 15:00:30 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_b_pos_order(t_lists *stacks, int value)
{
	t_dlist	*current;
	int		position;
	int		b_pos;

	current = stacks->b;
	position = 0;
	b_pos = 0;
	while (current)
	{
		if ((current->prev && value < current->prev->content
				&& value > current->content) || (current->prev
				&& value > current->prev->content && value > current->content))
		{
			b_pos = position;
			break ;
		}
		position++;
		current = current->next;
	}
	if (b_pos == ps_lstsize(stacks->b))
		b_pos = 0;
	return (b_pos);
}

t_order	*ps_fill_order(t_lists *stacks, t_order *order, int a, int b)
{
	int		a_size;
	int		b_size;
	t_dlist	*ac;
	t_dlist	*bc;

	ac = stacks->a;
	bc = stacks->b;
	a_size = ps_lstsize(stacks->a);
	b_size = ps_lstsize(stacks->b);
	order = ps_handle_a(order, a, a_size);
	order = ps_handle_b(order, b, b_size);
	return (order);
}

t_order	*ps_handle_a(t_order *order, int a, int a_size)
{
	if (a < a_size / 2)
	{
		while (a)
		{
			order->ra++;
			a--;
		}
	}
	else
	{
		while (a < a_size)
		{
			order->rra++;
			a++;
		}
	}
	return (order);
}

t_order	*ps_handle_b(t_order *order, int b, int b_size)
{
	if (b < b_size / 2)
	{
		while (b)
		{
			order->rb++;
			b--;
		}
	}
	else
	{
		while (b < b_size)
		{
			order->rrb++;
			b++;
		}
	}
	return (order);
}
