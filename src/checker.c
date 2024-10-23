/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:25:05 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/15 13:17:55 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

int	doubles_checker(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (argv[j][0] == '+')
				argv[j] = ft_itoa(ft_atoi(argv[j]));
			if ((ft_strnstr(argv[i], argv[j], ft_strlen(argv[i])))
				&& (ft_strnstr(argv[j], argv[i], ft_strlen(argv[j]))) && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	content_checker(char **argv)
{
	int			i;
	int			j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (ft_atoi(argv[i]) == -1 && !ft_strnstr(argv[i], "-1", 2))
		{
			return (-1);
		}
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]))
				&& (!ft_isvalidsign(argv[i][j], argv[i][j + 1])))
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
