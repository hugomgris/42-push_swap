/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:44:10 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/16 14:19:28 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*ps_pb(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "pb\n", 3);
	stacks->count++;
	ps_lstpushb(stacks);
	return (stacks);
}

t_lists	*ps_pa(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "pa\n", 3);
	stacks->count++;
	ps_lstpusha(stacks);
	return (stacks);
}
