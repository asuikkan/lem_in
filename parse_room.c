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

int	parse_ant_count(t_info *info, char *line)
{
	long	nb;
	int		i;

	nb = 0;
	i = -1;
	while (line[++i] != '\n')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		nb = nb * 10 + (line[i] - '0');
		if (nb > COORD_LIMIT)
			return (-1);
	}
	info->ant_count = nb;
	return (1);
}

static int	parse_name(t_room *room, char *line)
{
	int	len;

	len = ft_strclen(line, ' ');
	if (len == 0)
		return (-1);
	if (line[len - 1] == '\n' || line[0] == 'L')
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
	if (line[len - 1] == '\n')
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

	len = ft_strclen(line, '\n');
	if (len == 0)
		return (-1);
	nb = 0;
	i = -1;
	while (line[++i] != '\n')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		nb = nb * 10 + (line[i] - '0');
		if (nb > COORD_LIMIT)
			return (-1);
	}
	ft_memmove(line, line + len, ft_strlen(line) - len);
	room->y = (int)nb;
	return (1);
}

int	parse_room(t_info *info, char *line)
{
	t_room		room;

	room.name = NULL;
	if (parse_name(&room, line) == -1)
		return (-1);
	if (parse_x(&room, line) == -1)
		return (-1);
	if (parse_y(&room, line) == -1)
		return (-1);
	if (*line != '\n')
		return (-1);
	room.next = NULL;
	if (push_room(info, &room) == -1)
		return (-1);
	if (info->start_flag == 1)
		return (add_start(info, &room));
	if (info->end_flag == 1)
		return (add_end(info, &room));
	return (1);
}
