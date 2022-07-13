/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:47:50 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/02 17:47:51 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	rooms_read(t_info *info, char *line)
{
	if (!info->room_table)
		return (0);
	if (!ft_strchr(line, ' '))
		return (1);
	return (0);
}

static int	comment_check(t_info *info, char *line)
{
	if (ft_strcmp(line, "##start\n") == 0)
	{
		if (info->start_flag)
			return (-1);
		info->start_flag = 1;
	}
	else if (ft_strcmp(line, "##end\n") == 0)
	{
		if (info->end_flag)
			return (-1);
		info->end_flag = 1;
	}
	if ((info->start_flag || info->end_flag) && info->ant_count < 0)
		return (-1);
	return (1);
}

static int	parse_info(t_info *info, char *line)
{
	static int	room_flag;
	int			ret;

	ret = 1;
	if (line[0] == '#')
		ret = comment_check(info, line);
	else if (info->ant_count < 0)
		ret = parse_ant_count(info, line);
	else if (room_flag == 0)
	{
		ret = parse_room(info, line);
		if (ret == -1 && rooms_read(info, line) == 1)
			room_flag = 1;
	}
	if (room_flag == 1 && line[0] != '#')
		ret = parse_link(info, line);
	return (ret);
}

static int	save_line(char *buf, t_info *info)
{
	int			len;
	static int	start;
	static char	*line;

	while (buf[start])
	{
		len = lem_in_line_len(buf, start);
		if (!line)
			line = lem_in_strndup(buf, start, len);
		else
			line = lem_in_strnjoin(&line, buf, start, len);
		if (!line)
			return (-1);
		if (line[len - 1] != '\n')
			return (1);
		else
		{
			if (parse_info(info, line) == -1)
				return (-1);
			ft_strdel(&line);
		}
		start += len;
	}
	start = 0;
	return (1);
}

void	read_output(t_info *info)
{
	static char	buf[BUF_SIZE + 1];
	int			bytes;
	int			ret;

	while (1)
	{
		bytes = read(0, buf, BUF_SIZE);
		if (bytes == 0)
			return ;
		if (bytes < 0)
			return ;
		buf[bytes] = '\0';
		ret = save_line(buf, info);
		if (ret == -1)
		{
			free_info(info);
			error_handler();
		}
	}
}
