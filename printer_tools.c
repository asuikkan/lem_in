/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:27:57 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/29 16:27:59 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_single_line(size_t ant_count, t_pathset *pathset)
{
	size_t	i;
	t_vec	*path;
	t_room	*end;

	path = vec_get(&pathset->paths, 0);
	end = *(t_room **)vec_get(path, 0);
	i = 0;
	while (++i <= ant_count)
	{
		if (i > 1)
			ft_putchar(' ');
		ft_printf("L%lu-%s", i, end->name);
	}
	ft_putchar('\n');
}

void	free_room_info(size_t **room_info, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(room_info[i++]);
	free(room_info);
}

void	print_map_info(t_vec *map_info)
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

int	init_room_info(size_t ***room_info, t_pathset *pathset)
{
	size_t	i;
	t_vec	*path;

	*room_info = ft_memalloc(sizeof(size_t *) * pathset->paths.len);
	if (!*room_info)
		return (-1);
	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i);
		(*room_info)[i] = ft_memalloc(sizeof(size_t) * path->len);
		if (!(*room_info)[i])
			return (free_room_info(*room_info, pathset->paths.len), -1);
		i++;
	}
	return (1);
}

int	print_ant(size_t ant, t_vec *path, size_t room_i, int printed)
{
	t_room	*room;

	if (printed)
		ft_putstr(" ");
	room = *(t_room **)vec_get(path, room_i);
	ft_printf("L%lu-%s", ant, room->name);
	return (1);
}
