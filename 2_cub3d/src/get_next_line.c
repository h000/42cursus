/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 20:18:05 by hpark             #+#    #+#             */
/*   Updated: 2020/06/25 13:46:09 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free(char **p, int ret)
{
	if (*p && ret != 1)
	{
		free(*p);
		*p = 0;
	}
	return (ret);
}

int			join_line_and_src(char *src, char **line)
{
	char	*tmp;

	tmp = *line;
	if (!(*line = ft_strjoin(*line, src)))
		return (ft_free(&tmp, -1));
	free(tmp);
	tmp = 0;
	ft_bzero(src, ft_strlen(src));
	return (0);
}

int			fill_line(char *src, char **line)
{
	char	*tmp;
	int		i;

	if (src == 0)
		return (0);
	if ((tmp = ft_strchr(src, '\n')) != 0)
	{
		*tmp = '\0';
		if (join_line_and_src(src, line) == -1)
			return (-1);
		i = 0;
		while (*(++tmp) != '\0')
		{
			src[i++] = *tmp;
			*tmp = '\0';
		}
		return (1);
	}
	else
	{
		if (join_line_and_src(src, line) == -1)
			return (-1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*rest;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	int			ret2;

	if (BUFFER_SIZE < 1 || line == NULL || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if ((ret = (fill_line(rest, line))) != 0)
		return (ret);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((ret2 = fill_line(buff, line)) == 1)
		{
			if (ft_free(&rest, 0) == 0 && !(rest = ft_strdup(buff)))
				return (-1);
			ft_bzero(buff, BUFFER_SIZE);
			return (1);
		}
		else if (ret2 == -1)
			return (ret2);
	}
	return (ft_free(&rest, ret));
}
