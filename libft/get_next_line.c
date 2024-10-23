/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:20:24 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/15 13:20:25 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_gnl(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*new_stash(char *stash)
{
	int		len;
	char	*nstash;
	char	*ptr;

	ptr = ft_strchr(stash, '\n');
	if (!ptr)
	{
		nstash = NULL;
		return (ft_free_gnl(&stash));
	}
	else
		len = (ptr - stash) + 1;
	if (!stash[len])
		return (ft_free_gnl(&stash));
	nstash = ft_substr(stash, len, ft_strlen(stash) - len);
	ft_free_gnl(&stash);
	if (!nstash)
		return (NULL);
	return (nstash);
}

char	*make_line(char *stash)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(stash, '\n');
	len = (ptr - stash) + 1;
	line = ft_substr(stash, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_buf(int fd, char *stash)
{
	int		rb;
	char	*buffer;

	rb = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_gnl(&stash));
	buffer[0] = '\0';
	while (rb > 0 && !ft_strchr(buffer, '\n'))
	{
		rb = read(fd, buffer, BUFFER_SIZE);
		if (rb > 0)
		{
			buffer[rb] = '\0';
			stash = ft_strjoin(stash, buffer);
		}
	}
	free(buffer);
	if (rb == -1)
		return (ft_free_gnl(&stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if ((stash[fd] && !ft_strchr(stash[fd], '\n')) || !stash[fd])
		stash[fd] = read_buf(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = make_line(stash[fd]);
	if (!line)
		return (ft_free_gnl(&stash[fd]));
	stash[fd] = new_stash(stash[fd]);
	return (line);
}
