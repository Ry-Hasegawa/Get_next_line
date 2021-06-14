/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:22:18 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/27 18:32:17 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_put(char **line, char **fd_s, char *buf, int fd)
{
	int		i;
	int		flg;
	char	*tmp;

	i = 0;
	flg = 0;
	tmp = ft_strjoin(*line, buf);
	if (!tmp)
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		tmp = ft_strdup(&buf[i + 1]);
		if (!tmp)
			return (-1);
		flg = 1;
	}
	free(fd_s[fd]);
	fd_s[fd] = tmp;
	return (flg);
}

static ssize_t	ft_read_file(char *buf, int fd, ssize_t *i)
{
	*i = read(fd, buf, (size_t)BUFFER_SIZE);
	return (*i);
}

static int	ft_line_init(char **line)
{
	*line = (char *)malloc(1);
	if (!(*line))
		return (-1);
	*line[0] = '\0';
	return (0);
}

static int	free_if_error(char **fd_s, char **line, int flg, ssize_t i)
{	
	if (flg == -1)
	{
		free(fd_s);
		free(*line);
	}
	if (flg == -1 || i == -1)
		return (-1);
	else
		return (flg);
}

int	get_next_line(int fd, char **line)
{
	static char	*fd_s[256];
	char		*buf;
	int			flg;
	ssize_t		i;

	flg = 0;
	i = 0;
	if (!line || fd < 0 || 256 <= fd)
		return (-1);
	if (ft_line_init(line) == -1)
		flg = -1;
	if (fd_s[fd])
		flg = ft_put(line, fd_s, fd_s[fd], fd);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		flg = -1;
	while (flg == 0 && ft_read_file(buf, fd, &i) > 0)
	{
		buf[i] = '\0';
		flg = ft_put(line, fd_s, buf, fd);
	}
	free(buf);
	flg = free_if_error(fd_s, line, flg, i);
	return (flg);
}
