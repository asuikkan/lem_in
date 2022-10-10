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
	if (info->room_table.len == 0)
		return (0);
	if (!ft_strchr(line, ' '))
	{
		info->flags.room_flag = 1;
		return (1);
	}
	return (0);
}

static int	comment_check(t_info *info, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (info->flags.start_flag || info->start >= 0)
			return (-1);
		info->flags.start_flag = 1;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (info->flags.end_flag || info->end >= 0)
			return (-1);
		info->flags.end_flag = 1;
	}
	if ((info->flags.start_flag || info->flags.end_flag)
		&& info->ant_count == 0)
		return (-1);
	return (1);
}

static int	parse_info(t_info *info, char *line)
{
	if (line[0] == '#')
		return (comment_check(info, line));
	else if (info->ant_count == 0)
		return (parse_ant_count(info, line));
	else if (!info->flags.room_flag)
	{
		if (!rooms_read(info, line))
			return (parse_room(info, line));
	}
	if (!info->adj_matrix)
	{
		if (hasher(info) == -1)
			return (-1);
		info->adj_matrix = create_matrix(info->room_table.len);
		if (!info->adj_matrix)
			return (-1);
		info->room_count = info->room_table.len;
	}
	return (parse_link(info, line));
}

static int	save_and_copy_line(t_vec *map_info, char **dst, char *line)
{
	if (vec_push(map_info, &line) == -1)
		return (-1);
	*dst = ft_strdup(line);
	if (!(*dst))
		return (-1);
	return (1);
}

int	read_output(t_info *info)
{
	int		state;
	int		ret;
	char	*line;
	char	*temp;

	if ((vec_new(&info->room_table, 2, sizeof(t_room))) == -1)
		return (-1);
	state = 1;
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		if (save_and_copy_line(&info->map_info, &temp, line) == -1)
			return (-1);
		if (state >= 0)
			state = parse_info(info, temp);
		ft_strdel(&temp);
	}
	if (info->start < 0 || info->end < 0 || !info->flags.room_flag)
		return (-1);
	return (state);
}
