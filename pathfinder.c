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

static int	initialize_bfs_and_pathsets(t_info *info)
{
	info->bfs_path.visited = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs_path.visited)
		return (-1);
	info->bfs_path.closed = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs_path.closed)
		return (-1);
	info->bfs_path.index = ft_memalloc(sizeof(int));
	if (!info->bfs_path.index)
		return (-1);
	if (vec_new(&info->pathsets.current.paths, 2, sizeof(t_path)) == -1)
		return (-1);
	info->pathsets.current.total_time = 0;
	info->pathsets.best.total_time = 0;
	return (1);
}

static int	check_adjacent(t_info *info)
{
	t_room	*temp;
	int		i;

	i = -1;
	while (++i < info->room_count)
	{
		if (info->adj_matrix[*info->bfs_path.index][i] == 1
			&& !info->bfs_path.visited[i])
		{
			temp = vec_get(&info->room_table, i);
			if (!temp->parent)
				temp->parent = vec_get(&info->room_table, *info->bfs_path.index);
			if (i == info->end)
				return (is_better_path(info, temp));
			if (llist_push_back(
					&info->bfs_path.queue,
					&i,
					sizeof(int)) == -1)
				return (-1);
		}
	}
	return (0);
}

static int	bfs_path(t_info *info)
{
	info->bfs_path.visited[info->start] = 1;
	llist_push_back(&info->bfs_path.queue, &info->start, sizeof(int));
	while (info->bfs_path.queue)
	{
		llist_copy_front(
			info->bfs_path.index,
			info->bfs_path.queue,
			sizeof(int));
		llist_pop(&info->bfs_path.queue);
		if (check_adjacent(info) == -1)
			return (-1);
	}
	return (1);
}

int	pathfinder(t_info *info)
{
	if (initialize_bfs_and_pathsets(info) == -1)
		return (-1);
	if (bfs_path(info) == -1)
		return (-1);
	return (1);
}
