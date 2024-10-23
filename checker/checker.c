/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:52:18 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/22 18:58:54 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_checker_error(int argc)
{
	if (argc >= 2)
		write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ps_checker_last(t_lists *stacks, char *line)
{
	if (line[2] == 'a')
		ps_rra(stacks, 1);
	else if (line[2] == 'b')
		ps_rrb(stacks, 1);
	else if (line[2] == 'r')
		ps_rrr(stacks, 1);
}

char	*ps_checker_continue(t_lists *stacks, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ps_sa(stacks, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ps_sb(stacks, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ps_pa(stacks, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ps_pb(stacks, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ps_ra(stacks, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ps_rb(stacks, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ps_checker_last(stacks, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ps_rr(stacks, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ps_ss(stacks, 1);
	else
		ps_checker_error(2);
	return (get_next_line(0));
}

void	ps_checker_exe(t_lists *stacks, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ps_checker_continue(stacks, line);
		if (tmp != line)
			free(tmp);
	}
	if (stacks->b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_lists	*stacks;
	char	*line;

	if (argc < 2 || content_checker(&argv[1]) == -1
		|| doubles_checker(&argv[1]) == -1)
		ps_checker_error(argc);
	stacks = malloc(sizeof(t_dlist) * 2);
	if (stacks == NULL)
		ps_checker_error(2);
	stacks = list_builder(stacks, &argv[1]);
	line = get_next_line(0);
	if (!line && !is_sorted(stacks))
		write(1, "KO\n", 3);
	if (!line && is_sorted(stacks))
		write(1, "OK\n", 3);
	else
		ps_checker_exe(stacks, line);
	if (ps_lstsize(stacks->a) > 0)
		ps_lstclear(&stacks->a);
	if (ps_lstsize(stacks->b) > 0)
		ps_lstclear(&stacks->b);
	if (stacks)
		free(stacks);
	return (0);
}
