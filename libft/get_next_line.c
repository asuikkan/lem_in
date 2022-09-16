/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:43:47 by asuikkan          #+#    #+#             */
/*   Updated: 2021/12/07 10:44:43 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *data)
{
	char	*line;
	size_t	len;

	if (data == NULL)
		return (NULL);
	len = ft_strclen(data, '\n');
	line = ft_strsub(data, 0, len);
	return (line);
}

static char	*remove_line(char *data)
{
	char	*new;
	size_t	new_len;
	size_t	line_len;
	size_t	data_len;

	line_len = ft_strclen(data, '\n');
	data_len = ft_strlen(data);
	if (line_len == data_len)
		new = ft_strnew(0);
	else
	{
		new_len = data_len - line_len - 1;
		new = ft_strsub(data, (unsigned int)line_len + 1, new_len);
	}
	ft_strdel(&data);
	data = ft_strdup_free(new);
	return (data);
}

static int	find_line(char **array, const int fd, char **line)
{
	if (array[fd])
	{
		*line = set_line(array[fd]);
		array[fd] = remove_line(array[fd]);
		if (array[fd] && !*array[fd])
			ft_strdel(&array[fd]);
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*array[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	int			bytes;

	if (line == NULL || fd < 0 || fd > MAX_FD)
		return (-1);
	if (array[fd] && ft_strchr(array[fd], '\n'))
		return (find_line(array, fd, line));
	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes == -1)
		return (-1);
	else if (bytes == 0)
		return (find_line(array, fd, line));
	else
	{
		buf[bytes] = '\0';
		if (!array[fd])
			array[fd] = ft_strdup(buf);
		else
			array[fd] = ft_strjoin_free(array[fd], buf);
		return (get_next_line(fd, line));
	}
}
