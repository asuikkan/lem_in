/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:59:55 by asuikkan          #+#    #+#             */
/*   Updated: 2022/06/30 12:59:57 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	initialize_room(t_room *room)
{
	room->name = NULL;
	room->next = NULL;
	room->links.memory = NULL;
	room->links.elem_size = sizeof(int);
	room->links.len = 0;
	room->flow_from = -1;
	room->flow_to = -1;
}

static int	parse_name(t_room *room, char *line)
{
	int	len;

	len = ft_strclen(line, ' ');
	if (len == 0)
		return (-1);
	if (line[0] == 'L')
		return (-1);
	room->name = ft_strnew(len);
	if (!room->name)
		return (-1);
	room->name = ft_strncpy(room->name, line, len);
	ft_memmove(line, line + len + 1, ft_strlen(line) - len);
	return (1);
}

static int	parse_x(t_room *room, char *line)
{
	int		len;
	int		i;
	long	nb;

	len = ft_strclen(line, ' ');
	if (len == 0)
		return (-1);
	nb = 0;
	i = -1;
	while (line[++i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		nb = nb * 10 + (line[i] - '0');
		if (nb > COORD_LIMIT)
			return (-1);
	}
	ft_memmove(line, line + len + 1, ft_strlen(line) - len);
	room->x = (int)nb;
	return (1);
}

static int	parse_y(t_room *room, char *line)
{
	int		len;
	int		i;
	long	nb;

	len = ft_strlen(line);
	if (len == 0)
		return (-1);
	nb = 0;
	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		nb = nb * 10 + (line[i] - '0');
		if (nb > COORD_LIMIT)
			return (-1);
	}
	ft_memmove(line, line + len, len);
	room->y = (int)nb;
	return (1);
}

int	parse_room(t_info *info, char *line)
{
	t_room		room;

	initialize_room(&room);
	if (parse_name(&room, line) == -1)
		return (-1);
	if (parse_x(&room, line) == -1)
		return (free(room.name), -1);
	if (parse_y(&room, line) == -1)
		return (free(room.name), -1);
	if (*line)
		return (-1);
	room.index = info->room_table.len;
	if (push_room(info, &room) == -1)
		return (-1);
	if (info->flags.start_flag == 1)
		return (add_start(info, &room));
	if (info->flags.end_flag == 1)
		return (add_end(info, &room));
	return (1);
}
