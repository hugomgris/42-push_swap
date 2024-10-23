/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsorter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:59:30 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/22 14:43:04 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*ps_finalize(t_lists *stacks)
{
	stacks = ps_amin_to_top(stacks, stacks->a, ps_s_index(stacks->a));
	return (stacks);
}

t_lists	*ps_return(t_lists *stacks)
{
	stacks = sort_3(stacks);
	stacks = ps_bmax_to_top(stacks, stacks->b, ps_m_index(stacks->b));
	while (ps_new_bmax(stacks->b->content, stacks->a))
		stacks = ps_pa(stacks, 0);
	while (stacks->b)
		stacks = ps_return_num(stacks, stacks->b->content);
	return (stacks);
}

t_lists	*ps_bsort(t_lists *stacks)
{
	t_order	*order;
	int		cheapest_position;

	order = malloc(sizeof(t_order));
	if (!order)
		return (NULL);
	order = ps_order_init(order);
	while (!is_sorted(stacks))
	{
		cheapest_position = ps_find_cheapest_position(stacks, &order);
		stacks = ps_process_pos(stacks, order, cheapest_position);
		if (ps_lstsize(stacks->a) == 3)
			break ;
	}
	stacks = ps_return(stacks);
	stacks = ps_finalize(stacks);
	free(order);
	return (stacks);
}

int	ps_find_cheapest_position(t_lists *stacks, t_order **order)
{
	*order = ps_order_init(*order);
	return (ps_cheapest_position(stacks, order));
}

t_lists	*ps_process_pos(t_lists *stacks, t_order *order, int cheapest_position)
{
	int		i;
	t_dlist	*current;
	int		cheapest_b;

	i = 0;
	current = stacks->a;
	while (current && i++ < cheapest_position)
		current = current->next;
	cheapest_b = ps_a_pos_in_b(stacks, current->content);
	order = ps_order_init(order);
	order = ps_order(stacks, order, cheapest_position, cheapest_b);
	return (ps_execute(stacks, order));
}
