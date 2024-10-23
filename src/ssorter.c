/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssorter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:50:30 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/17 13:05:29 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*sort_3(t_lists *stacks)
{
	t_dlist	*lt;
	t_dlist	*ft;	

	while (!is_sorted(stacks))
	{
		lt = ps_lstlast(stacks->a);
		ft = ps_lstfirst(stacks->a);
		if (ft->content < lt->content && ft->next->content > lt->content)
		{
			stacks = ps_sa(stacks, 0);
			stacks = ps_ra(stacks, 0);
		}
		else if (ft->content > ft->next->content && ft->content < lt->content)
			stacks = ps_sa(stacks, 0);
		else if (ft->content > lt->content && ft->content < ft->next->content)
			stacks = ps_rra(stacks, 0);
		else if (ft->content > ft->next->content && ft->content > lt->content)
			stacks = ps_ra(stacks, 0);
		else
		{
			stacks = ps_ra(stacks, 0);
			stacks = ps_sa(stacks, 0);
		}
	}
	return (stacks);
}

t_lists	*sort_4(t_lists *stacks)
{
	int	s_index;

	s_index = ps_s_index(stacks->a);
	if (!is_sorted(stacks))
	{
		stacks = ps_amin_to_top(stacks, stacks->a, s_index);
	}
	if (!is_sorted(stacks))
	{
		stacks = ps_pb(stacks, 0);
		stacks = sort_3(stacks);
		stacks = ps_pa(stacks, 0);
	}
	return (stacks);
}

t_lists	*sort_5(t_lists *stacks)
{
	int	m_index;

	m_index = ps_m_index(stacks->a);
	if (!is_sorted(stacks))
		stacks = ps_amax_to_top(stacks, stacks->a, m_index);
	stacks = ps_pb(stacks, 0);
	if (!is_sorted(stacks))
		stacks = sort_4(stacks);
	stacks = ps_pa(stacks, 0);
	stacks = ps_ra(stacks, 0);
	return (stacks);
}

t_lists	*ps_ssort(t_lists *stacks)
{
	int	i;

	i = ps_lstsize(stacks->a);
	if (i == 2)
	{
		if (stacks->a->content > stacks->a->next->content)
			stacks = ps_sa(stacks, 0);
	}
	else if (i == 3)
		stacks = sort_3(stacks);
	else if (i == 4)
		stacks = sort_4(stacks);
	else if (i == 5)
		stacks = sort_5(stacks);
	return (stacks);
}
