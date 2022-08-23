/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:39:42 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/04 16:39:43 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	clean_distance(t_bfs_distance *bfs, int ret)
{
	llist_free(&bfs->queue);
	bfs->queue = NULL;
	free(bfs->visited);
	bfs->visited = NULL;
	free(bfs->index);
	bfs->index = NULL;
	return (ret);
}

static int	initialize_bfs_distance(t_info *info)
{
	info->bfs_distance.queue = llist_new(&info->end->matrix_index, sizeof(int));
	if (!info->bfs_distance.queue)
		return (-1);
	info->bfs_distance.visited = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs_distance.visited)
		return (-1);
	info->bfs_distance.index = ft_memalloc(sizeof(int));
	if (!info->bfs_distance.index)
		return (-1);
	return (1);
}

static int	check_adjacent(t_info *info)
{
	t_room	*temp;
	int		i;
	int		distance;

	temp = vec_get(&info->room_table, *info->bfs_distance.index);
	distance = temp->distance + 1;
	i = -1;
	while (++i < info->room_count)
	{
		if (info->adj_matrix[*info->bfs_distance.index][i] == 1
			&& !info->bfs_distance.visited[i])
		{
			temp = vec_get(&info->room_table, i);
			temp->distance = distance;
			info->bfs_distance.visited[i] = 1;
			if (llist_push_back(
					&info->bfs_distance.queue,
					&i,
					sizeof(int)) == -1)
				return (-1);
		}
	}
	return (1);
}

static int	bfs(t_info *info)
{
	info->bfs_distance.visited[info->end->matrix_index] = 1;
	while (info->bfs_distance.queue)
	{
		llist_copy_front(
			info->bfs_distance.index,
			info->bfs_distance.queue,
			sizeof(int));
		llist_pop(&info->bfs_distance.queue);
		if (check_adjacent(info) == -1)
			return (-1);
	}
	return (1);
}

int	add_distances(t_info *info)
{
	if (initialize_bfs_distance(info) == -1 || bfs(info) == -1)
		return (clean_distance(&info->bfs_distance, -1));
	return (clean_distance(&info->bfs_distance, 1));
}
