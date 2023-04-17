/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:13:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 13:26:52 by tel-mouh         ###   ########.fr       */
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