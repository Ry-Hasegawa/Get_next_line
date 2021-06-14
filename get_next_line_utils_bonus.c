/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:13:33 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/27 18:32:25 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int		index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*ptr;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (src == 0)
		return (0);
	ptr = (char *)malloc(i + 1);
	if (ptr == 0)
		return (0);
	ft_strcpy(ptr, src);
	return (ptr);
}

static int	total_len(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\n' && s2[j] != '\0')
		j++;
	return (i + j);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*heap;
	int		k;
	int		l;
	int		m;

	l = 0;
	k = total_len(line, buf);
	m = 0;
	heap = (char *)malloc(k + 1);
	if (!heap)
		return (NULL);
	while (line[m] != '\0')
	{
		heap[m] = line[m];
		m++;
	}
	while (buf[l] != '\n' && buf[l] != '\0')
	{
		heap[m] = buf[l];
		m++;
		l++;
	}
	heap[m] = '\0';
	return (heap);
}
