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

static int	clean_distance(t_bfs *bfs, int ret)
{
	llist_free(&bfs->queue);
	bfs->queue = NULL;
	free(bfs->visited);
	bfs->visited = NULL;
	free(bfs->index);
	bfs->index = NULL;
	return (ret);
}

static int	initialize_bfs(t_info *info)
{
	info->bfs.queue = llist_new(&info->end, sizeof(int));
	if (!info->bfs.queue)
		return (-1);
	info->bfs.visited = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs.visited)
		return (-1);
	info->bfs.index = ft_memalloc(sizeof(int));
	if (!info->bfs.index)
		return (-1);
	return (1);
}

static int	check_adjacent(t_info *info)
{
	t_room	*temp;
	int		i;
	int		distance;

	temp = vec_get(&info->room_table, *info->bfs.index);
	distance = temp->distance + 1;
	i = -1;
	while (++i < info->room_count)
	{
		if (info->adj_matrix[*info->bfs.index][i] == 1
			&& !info->bfs.visited[i])
		{
			temp = vec_get(&info->room_table, i);
			temp->distance = distance;
			info->bfs.visited[i] = 1;
			if (llist_push_back(
					&info->bfs.queue,
					&i,
					sizeof(int)) == -1)
				return (-1);
		}
	}
	return (1);
}

static int	bfs(t_info *info)
{
	info->bfs.visited[info->end] = 1;
	while (info->bfs.queue)
	{
		llist_copy_front(
			info->bfs.index,
			info->bfs.queue,
			sizeof(int));
		llist_pop(&info->bfs.queue);
		if (check_adjacent(info) == -1)
			return (-1);
	}
	return (1);
}

int	add_distances(t_info *info)
{
	if (initialize_bfs(info) == -1 || bfs(info) == -1)
		return (clean_distance(&info->bfs, -1));
	return (clean_distance(&info->bfs, 1));
}
