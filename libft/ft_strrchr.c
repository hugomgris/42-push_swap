/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:46 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/12 18:19:17 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			idx;
	int				last_found;
	unsigned char	target;

	last_found = -1;
	idx = 0;
	target = (unsigned char)c;
	while (s[idx] != '\0')
	{
		if (s[idx] == target)
			last_found = idx;
		idx++;
	}
	if (last_found == -1 && target != '\0')
		return (NULL);
	if (last_found == -1 && target == '\0')
		return ((char *)(s + idx));
	return ((char *)(s + last_found));
}
