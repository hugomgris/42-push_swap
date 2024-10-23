/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:28:44 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/22 11:34:29 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*sort(t_lists *stacks)
{
	int	i;

	if (is_sorted(stacks))
		return (stacks);
	i = ps_lstsize(stacks->a);
	if (i <= 5)
		stacks = ps_ssort(stacks);
	else
	{
		stacks = ps_pb(stacks, 0);
		stacks = ps_pb(stacks, 0);
		stacks = ps_bsort(stacks);
	}
	return (stacks);
}

t_lists	*ps_stacks_init(t_lists *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->count = 0;
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_lists	*stacks;

	if (argc < 2 || content_checker(&argv[1]) == -1
		|| doubles_checker(&argv[1]) == -1)
	{
		if (argc >= 2)
			write(1, "Error\n", 6);
		exit (1);
	}
	stacks = malloc(sizeof(t_dlist) * 2);
	if (stacks == NULL)
		return (0);
	stacks = ps_stacks_init(stacks);
	stacks = list_builder(stacks, &argv[1]);
	stacks = sort(stacks);
	if (ps_lstsize(stacks->a) > 0)
		ps_lstclear(&stacks->a);
	if (ps_lstsize(stacks->b) > 0)
		ps_lstclear(&stacks->b);
	free(stacks);
	return (0);
}
