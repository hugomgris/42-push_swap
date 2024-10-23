/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:02:07 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/16 15:36:22 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*ps_rb(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "rb\n", 3);
	stacks->count++;
	stacks->b = ps_lstrotate(stacks->b);
	return (stacks);
}

t_lists	*ps_ra(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "ra\n", 3);
	stacks->count++;
	stacks->a = ps_lstrotate(stacks->a);
	return (stacks);
}

t_lists	*ps_rr(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "rr\n", 3);
	stacks->count += 2;
	stacks->b = ps_lstrotate(stacks->b);
	stacks->a = ps_lstrotate(stacks->a);
	return (stacks);
}
