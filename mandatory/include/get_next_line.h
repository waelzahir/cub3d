/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:13:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 02:57:23 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

size_t	_ftstrlen(const char *s);
size_t	_ftstrlcpy(char *dst, const char *src, size_t dstsize);
char	*_ftstrdup(const char *s1);
char	*_ftstrjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		_ftstrchr(const char *p, int c);

#endif