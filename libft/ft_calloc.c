/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:54:13 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/20 09:13:51 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*res;

	res = (void *)malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, (nmemb * size));
	return (res);
}
