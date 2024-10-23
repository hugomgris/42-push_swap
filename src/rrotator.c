/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:07:10 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/16 14:22:49 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*ps_rrb(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "rrb\n", 4);
	stacks->count++;
	stacks->b = ps_lstrrotate(stacks->b);
	return (stacks);
}

t_lists	*ps_rra(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "rra\n", 4);
	stacks->count++;
	stacks->a = ps_lstrrotate(stacks->a);
	return (stacks);
}

t_lists	*ps_rrr(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "rrr\n", 4);
	stacks->count += 2;
	stacks->a = ps_lstrrotate(stacks->a);
	stacks->b = ps_lstrrotate(stacks->b);
	return (stacks);
}
