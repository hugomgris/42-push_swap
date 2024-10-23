/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:13:41 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/16 15:57:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s) + 1;
	s2 = (char *)malloc(sizeof(char) * (len));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s, len);
	return (s2);
}
