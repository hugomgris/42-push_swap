/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:58:58 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/23 14:00:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	unsigned int	i;
	char			*new_s;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	new_s = (char *)malloc((s_len + 1) * sizeof(char));
	if (new_s)
	{
		i = 0;
		while (i < s_len)
		{
			new_s[i] = f(i, s[i]);
			i++;
		}
		new_s[i] = '\0';
	}
	return (new_s);
}
