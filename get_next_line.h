/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:49:16 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/06 20:06:36 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h> // malloc, free
# include <unistd.h> // write, read
#include <fcntl.h> // open
#include <stdio.h> // printf

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *str, unsigned int start, size_t len);

#endif 