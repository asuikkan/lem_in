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

static void	print_map_info(t_vec *map_info)
{
	char	**line;
	size_t	i;

	i = 0;
	while (i < map_info->len)
	{
		line = vec_get(map_info, i++);
		ft_putendl(*line);
	}
}

static int	init_ant_location(size_t ***ant_location, t_pathset *pathset)
{
	size_t	i;
	t_vec	*path;

	*ant_location = ft_memalloc(sizeof(size_t *) * pathset->paths.len);
	if (!*ant_location)
		return (-1);
	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i);
		*ant_location[i] = ft_memalloc(sizeof(size_t) * path->len);
		if (!*ant_location[i])
			return (-1);
		i++;
	}
	return (1);
}

static void	print_path_situation(size_t **ant_location, size_t path_index, t_vec *path, size_t ant_number)
{
	size_t	i;
	t_room	*room;

	i = 0;
	while (ant_location[path_index][i] > 0)
		i++;
	while (i > 0)
	{
		room = vec_get(path, i);
		ant_location[path_index][i] = ant_location[path_index][i - 1];
		ft_printf("L%lu-%s ", ant_location[path_index][i--], room->name);
	}
	room = vec_get(path, i);
	ant_location[path_index][i] = ant_number;
	ft_printf("L%lu-%s", ant_number, room->name);
}

static void	assign_ants(int ant_count, t_pathset *pathset, size_t **ant_location)
{
	size_t	line_count;
	int		ants;
	size_t	ant_number;
	size_t	i;
	t_vec	*path;

	ants = ant_count;
	line_count = pathset->total_time + 1;
	while (--line_count > 0)
	{
		i = 0;
		while (ants > 0 && i < pathset->paths.len)
		{
			path = vec_get(&pathset->paths, i);
			if (path->len > line_count)
				break ;
			ant_number = ant_count - ants + 1;
			print_path_situation(ant_location, i, path, ant_number);
			ants--;
			i++;
		}
		ft_printf("\n");
	}
	
}

int	print_solution(int ant_count, t_vec *map_info, t_pathset *pathset)
{
	size_t	**ant_location;

	ant_location = NULL;
	if (init_ant_location(&ant_location, pathset) == -1)
		return (-1);
	print_map_info(map_info);
	assign_ants(ant_count, pathset, ant_location);
	return (1);
}
