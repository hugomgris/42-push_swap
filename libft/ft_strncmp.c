/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:18:24 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/12 15:57:17 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;
	size_t			i;

	if (n)
	{
		ucs1 = (unsigned char *) s1;
		ucs2 = (unsigned char *) s2;
		i = 0;
		while (i < n && s1[i] != '\0' && s2[i] != '\0' && ucs1[i] == ucs2[i])
			i++;
		if (i >= n)
			return (0);
		else
			return (ucs1[i] - ucs2[i]);
	}
	return (0);
}
