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
	ft_printf("\n");
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
		(*ant_location)[i] = ft_memalloc(sizeof(size_t) * path->len);
		if (!(*ant_location)[i])
			return (-1);
		i++;
	}
	return (1);
}

static void	traverse_ants(size_t **ant_location, t_pathset *pathset)
{
	size_t		i;
	size_t		j;
	t_room		*room;
	t_vec		*path;

	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i);
		j = 0;
		while (ant_location[i][j] > 0)
			j++;
		if (j == 0)
			break ;
		while (j > 0)
		{
			room = *(t_room **)vec_get(path, j);
			ant_location[i][j] = ant_location[i][j - 1];
			ant_location[i][j - 1] = 0;
			ft_printf("L%lu-%s", ant_location[i][j--], room->name);
		}
		ant_location[i++][path->len - 1] = 0;
	}
}

static void	send_ants(size_t **ant_location, size_t path_index, t_vec *path)
{
	static int	ant_number;
	t_room		*room;

	ant_number++;
	room = *(t_room **)vec_get(path, 0);
	ant_location[path_index][0] = ant_number;
	ft_printf("L%lu-%s", ant_number, room->name);
}

static void	print_solution(int ant_count, t_pathset *pathset, size_t **ant_location)
{
	size_t	ants;
	size_t	line_count;
	size_t	i;
	t_vec	*path;

	ants = ant_count;
	line_count = pathset->total_time + 1;
	while (--line_count > 0)
	{
		i = 0;
		traverse_ants(ant_location, pathset);
		while (ants > 0 && i < pathset->paths.len)
		{
			path = vec_get(&pathset->paths, i);
			send_ants(ant_location, i, path);
			ants--;
			i++;
		}
		ft_printf("\n");
	}
}

int	print_final(int ant_count, t_vec *map_info, t_pathset *pathset)
{
	size_t	**ant_location;

	if (init_ant_location(&ant_location, pathset) == -1)
		return (-1);
	print_map_info(map_info);
	print_solution(ant_count, pathset, ant_location);
	return (1);
}
