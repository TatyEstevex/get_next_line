/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:56 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/06 20:25:15 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	ssize_t 		bytes_read;
	static char		*stash;
	char			*result;
	char			*temp;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return (stash);
	buf[bytes_read] = '\0';
	stash = ft_strjoin(stash, buf);
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		buf[bytes_read]= '\0';
		stash = ft_strjoin(stash, buf);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (!ft_strchr(stash, '\n'))
		return (stash);
	temp = stash;
	result = ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1); 
	stash = ft_substr(stash, ft_strchr(stash, '\n') - stash + 1, ft_strlen(stash));
	return (result);
}
