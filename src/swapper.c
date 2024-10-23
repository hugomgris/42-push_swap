/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:57 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/16 14:19:54 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*ps_sa(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "sa\n", 3);
	stacks->count++;
	stacks->a = ps_lstswap(stacks->a);
	return (stacks);
}

t_lists	*ps_sb(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "sb\n", 3);
	stacks->count++;
	stacks->b = ps_lstswap(stacks->b);
	return (stacks);
}

t_lists	*ps_ss(t_lists *stacks, int flag)
{
	if (flag == 0)
		write(1, "ss\n", 3);
	stacks->count += 2;
	stacks->a = ps_lstswap(stacks->a);
	stacks->b = ps_lstswap(stacks->b);
	return (stacks);
}
