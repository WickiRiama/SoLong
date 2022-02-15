/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:22:05 by mriant            #+#    #+#             */
/*   Updated: 2022/02/15 11:50:47 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = ft_calloc(sizeof(char), (ft_strlen_gnl(s) + ft_strlen_gnl(s2) + 1));
	if (!res)
	{
		free (s);
		return (NULL);
	}
	while (s && s[i])
	{
		res[i] = s[i];
		i ++;
	}
	while (s2 && s2[j])
	{
		res[i] = s2[j];
		i ++;
		j ++;
	}
	free(s);
	return (res);
}

long int	ft_readline(int fd, char **buf, char **line)
{	
	long int	ret;

	if (!(*buf))
		return (-1);
	ret = 1;
	while (ret > 0 && !ft_strchr(line[0], '\n'))
	{
		ret = read(fd, buf[0], BUFFER_SIZE);
		if (ret >= 0)
		{
			buf[0][ret] = '\0';
			line[0] = ft_strjoin_free(line[0], buf[0]);
		}
	}
	return (ret);
}

void	ft_setline(char **line, char **tail)
{
	char	*endline;

	endline = ft_strchr(line[0], '\n');
	free(*tail);
	if (endline)
	{
		*tail = ft_strdup(endline + 1);
		endline[1] = '\0';
	}
	else
		*tail = NULL;
}

void	ft_clean(char *buf, char *tail, char *line)
{
	free(buf);
	free(tail);
	free(line);
}

char	*get_next_line(int fd)
{
	long int	ret;
	char		*buf;
	static char	*tail[256];
	char		*line;

	if (fd < 0 || fd >= 255 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	tail[fd] = ft_strjoin_free(tail[fd], "\0");
	line = ft_strdup(tail[fd]);
	ret = ft_readline(fd, &buf, &line);
	if (ret < 0 || !buf)
	{
		ft_clean(buf, tail[fd], line);
		return (NULL);
	}
	ft_setline(&line, &tail[fd]);
	if (ret == 0 && !tail[fd] && line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	free(buf);
	return (line);
}
