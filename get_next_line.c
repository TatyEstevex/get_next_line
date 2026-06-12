/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:46:27 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/12 16:06:24 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract(char **stash)
{
	char		*result;
	char		*temp;

	if (ft_strlen(*stash) == 0)
		return (free(*stash), *stash = NULL, NULL);
	if (!ft_strchr(*stash, '\n'))
		return (result = *stash, *stash = NULL, result);
	result = ft_substr(*stash, 0, ft_strchr(*stash, '\n') - *stash + 1);
	if (!result)
		return (free (*stash), *stash = NULL, NULL);
	temp = ft_substr(*stash, ft_strchr(*stash, '\n') - *stash + 1,
			ft_strlen(*stash) - ft_strlen(result));
	free(*stash);
	*stash = NULL;
	if (!temp)
		return (free (result), result = NULL, NULL);
	*stash = temp;
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buf;
	ssize_t		bytes_read;
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	if (!stash)
		return (free(buf), NULL);
	line = ft_extract(&stash);
	return (free(buf), line);
}
