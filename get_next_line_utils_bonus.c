/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:24:39 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/15 11:07:29 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] != c))
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	char	*res;
	size_t	r;

	i = 0;
	r = 0;
	if (!str2)
		return (NULL);
	if (!str1)
	{
		str1 = malloc(1 * sizeof(char));
		if (!str1)
			return (NULL);
		str1[0] = '\0';
	}
	res = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!res)
		return (free(str1), NULL);
	while (str1[i])
		res[r++] = str1[i++];
	i = 0;
	while (str2[i])
		res[r++] = str2[i++];
	res[r] = '\0';
	return (free(str1), res);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i] && (i < len))
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
