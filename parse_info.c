/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:59:55 by asuikkan          #+#    #+#             */
/*   Updated: 2022/06/30 12:59:57 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_ant_count(char *data)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (data[++i] != '\n')
	{
		if (!ft_isdigit(data[i]))
			return (-1);
		ret = ret * 10 + (data[i] - '0');
	}
	return (ret);
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
	line = line + len;
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
	line += len;
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
	line += len;
	room->y = (int)nb;
	return (1);
}

int	parse_room(t_info *info, char *line)  //tee parsetus loppuun, taa on rikki!
{
	t_room	room;
	t_vec	table;
	char	*temp;

	temp = line;
	if (parse_name(&room, temp) == -1)
		return (-1);
	if (parse_x(&room, temp) == -1)
		return (-1);
	if (parse_y(&room, temp) == -1)
		return (-1);
	if (!info->room_table)
		info->room_table = &table;
	return (1);
}
