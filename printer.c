/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:48:59 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/27 15:49:00 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_situation(size_t **room_info, t_pathset *pathset)
{
	int		printed;
	size_t	i;
	size_t	j;
	t_vec	*path;

	printed = 0;
	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i);
		j = path->len;
		while (1)
		{
			if (room_info[i][--j] > 0)
				printed = print_ant(room_info[i][j], path, j, printed);
			if (j == 0)
				break ;
		}
		room_info[i++][path->len - 1] = 0;
	}
}

static void	traverse_ants(size_t **room_info, t_pathset *pathset)
{
	size_t		i;
	int			j;
	t_vec		*path;

	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i);
		j = path->len - 1;
		while (j >= 0 && room_info[i][j] == 0)
			j--;
		while (j >= 0 && room_info[i][j] > 0)
		{
			room_info[i][j + 1] = room_info[i][j];
			room_info[i][j] = 0;
			j--;
		}
		i++;
	}
}

static void	send_ants(size_t **room_info, size_t path_index)
{
	static int	ant_number;

	ant_number++;
	room_info[path_index][0] = ant_number;
}

static void	ant_control(size_t ant_count,
	t_pathset *pathset, size_t **room_info)
{
	size_t	line_count;
	size_t	ants;
	size_t	i;
	t_vec	*path;

	ants = ant_count;
	line_count = pathset->total_time + 1;
	while (--line_count > 0)
	{
		i = 0;
		traverse_ants(room_info, pathset);
		while (ants > 0 && i < pathset->paths.len)
		{
			path = vec_get(&pathset->paths, i);
			if (path->len > line_count)
				break ;
			send_ants(room_info, i);
			ants--;
			i++;
		}
		check_situation(room_info, pathset);
		ft_putstr("\n");
	}
}

int	print_final(size_t ant_count, t_vec *map_info, t_pathset *pathset)
{
	size_t	**room_info;

	if (init_room_info(&room_info, pathset) == -1)
		return (-1);
	print_map_info(map_info);
	ant_control(ant_count, pathset, room_info);
	free_room_info(room_info, pathset->paths.len);
	return (1);
}
