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

static void	save_info(t_info *info, char *line)
{
	static int	room_flag;

	if (info->ant_count < 0)
	{
		info->ant_count = check_ant_count(line);
		if (info->ant_count < 0)
		{
			free_info(info);
			error_handler();
		}
	}
	room_flag = 1;
}

static void	save_line(char *buf, t_info *info)
{
	static int	start;
	int			len;
	static char	*line;

	len = lem_in_line_len(buf, start);
	if (!line)
		line = lem_in_strndup(buf, start, len);
	else
		line = lem_in_strnjoin(line, buf, start, len);
	if (!line)
	{
		free_info(info);
		error_handler();
	}
	if (line[len - 1] == '\n')
		save_info(info, line);
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
		save_line(buf, info);
	}
}
