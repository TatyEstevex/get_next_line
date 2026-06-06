/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:58:27 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/06 20:18:43 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char *ft_strchr(const char *s, int c)
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
	char	*to_free;

	i = 0;
	r = 0;
	to_free = str1;
	if (!str1)
		str1 = "";
	if (!str2)
		return (NULL);
	res = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!res)
		return (NULL);
    while (str1[i])
        res[r++] = str1[i++]; 
    i = 0;
    while (str2[i])
        res[r++] = str2[i++];
	res[r] = '\0';
   	free(to_free);
	return (res);
}
char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	res = malloc (len + 1);
	if (!res)
		return (NULL);
	while(str[i] && (i < len))
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

