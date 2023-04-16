/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:15:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2021/12/26 12:57:44 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_ftstrjoin(char *s1, char *s2)
{
	char	*p;
	size_t	lens;
	size_t	lenf;

	if (!s1 || !s2)
		return (NULL);
	lens = _ftstrlen(s2);
	lenf = _ftstrlen(s1);
	p = (char *)malloc(lenf + lens + 1);
	if (!p)
		return (NULL);
	_ftstrlcpy(p, s1, lenf + 1);
	_ftstrlcpy(p + lenf, s2, lenf + lens + 1);
	if (!*p)
		return (free(p), NULL);
	if (*s1)
		free(s1);
	return (p);
}

size_t	_ftstrlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	t;

	t = 0;
	if (!dstsize)
		return (_ftstrlen(src));
	while (src[t] && dstsize - 1)
	{
		dst[t] = src[t];
		t++;
		dstsize--;
	}
	return (dst[t] = 0, _ftstrlen(src));
}

size_t	_ftstrlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*_ftstrdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(_ftstrlen(s1)+1);
	if (p == NULL)
		return (NULL);
	return (_ftstrlcpy(p, s1, _ftstrlen(s1) + 1), p);
}

int	_ftstrchr(const char *p, int c)
{
	int			i;

	i = 0;
	while (p[i] != (char )c && p[i])
		i++;
	if (!p[i])
		return (-1);
	return (i);
}
