/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:46:03 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/05 18:46:07 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*find_best_room(t_room *room, int **adj_matrix, int size) // jatka taalta!!
{
	int	i;
	int	

	i = -1;
	while (++i < size)
	{
		
	}
}

static int	shortest_path(t_info *info, t_vec *path, int *closed_list)
{
	t_room	*current;
	t_room	*next;

	current = info->start;
	while (current != info->end)
	{
		if (vec_push(path, current) == -1)
			return (-1);
		next = find_best_room(current, info->adj_matrix, info->room_count);
		if (!next)
		{
			vec_free(path);
			path = NULL;
			return (0);
		}
	}
	return (1);
}

static int	form_path(t_info *info, t_vec *path, int *closed_list)
{
	if (vec_new(path, 2, sizeof(t_room *)) == -1)
		return (-1);
	if (shortest_path(info, path, closed_list) == -1)
		return (-1);
	if (!path)
	{
		vec_free(path);
		path = NULL;
		return (0);
	}
	return (1);
}

int	pathfinder(t_info *info)
{
	t_lists lists;
	t_vec	*path;
	t_vec	*paths;
	int		found_path;

	lists.closed = ft_memalloc(sizeof(int) * info->room_table.len);
	if (!lists.closed)
		return (-1);
	lists.open = ft_memalloc(sizeof(int) * info->room_table.len);
	if (!lists.open)
		return (-1);
	found_path = form_path(info, path, lists.closed);
	if (found_path == -1)
		return (-1);
	if (found_path == 1)
	{
		if (vec_push(paths, path) == -1)
			return (-1);
	}
	return (1);
}
