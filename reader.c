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

static int	parse_info(t_info *info, char *line)
{
	static int	room_flag;
	static int	start_flag;
	static int	end_flag;

	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start\n") == 0)
			start_flag = 1;
		else if (ft_strcmp(line, "##end\n") == 0)
			end_flag = 1;
		if ((start_flag || end_flag) && (info->ant_count < 0 || room_flag == 1))
			return (-1);
	}
	else if (info->ant_count < 0)
	{
		info->ant_count = parse_ant_count(line); // tee tama paremmin!
		return (info->ant_count);
	}
	else if (room_flag == 0)
		return (parse_room(info, line, start_flag, end_flag));
	else
		return (1);
}

static int	save_line(char *buf, t_info *info)
{
	static int	start;
	int			len;
	static char	*line;

	while (buf[start])
	{
		len = lem_in_line_len(buf, start);
		if (!line)
			line = lem_in_strndup(buf, start, len);
		else
			line = lem_in_strnjoin(line, buf, start, len);
		if (!line)
			return (-1);
		if (line[len - 1] == '\n')
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
	int			ret;

	while (1)
	{
		ret = read(0, buf, BUF_SIZE);
		if (ret == 0)
			return ;
		if (ret < 0)
			return ;
		buf[ret] = '\0';
		if (save_line(buf, info) == -1)
		{
			free_info(info);
			error_handler();
		}
	}
}
