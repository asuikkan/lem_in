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
		if (info->flags.start_flag)
			return (-1);
		info->flags.start_flag = 1;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (info->flags.end_flag)
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

int	read_output(t_info *info)
{
	char	*line;
	char	*temp;
	int		state;

	if ((vec_new(&info->room_table, 2, sizeof(t_room))) == -1)
		return (-1);
	state = 1;
	while (get_next_line(0, &line) > 0)
	{
		if (vec_push(&info->map_info, &line) == -1)
			return (-1);
		temp = ft_strdup(line);
		if (!temp)
			return (-1);
		if (state >= 0)
			state = parse_info(info, temp);
		ft_strdel(&temp);
	}
	return (state);
}
