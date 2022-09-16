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
	free(bfs->current);
	bfs->current = NULL;
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
	info->bfs.current = ft_memalloc(sizeof(int));
	if (!info->bfs.current)
		return (-1);
	return (1);
}

static int	check_adjacent(t_info *info)
{
	t_room	*current;
	t_room	*temp;
	int		target;
	int		distance;
	size_t	i;

	current = vec_get(&info->room_table, *info->bfs.current);
	distance = current->distance + 1;
	i = 0;
	while (i < current->edges.len)
	{
		target = get_link(&current->edges, i);
		if (!info->bfs.visited[target])
		{
			temp = vec_get(&info->room_table, i);
			temp->distance = distance;
			info->bfs.visited[target] = 1;
			if (llist_push_back(
					&info->bfs.queue,
					&target,
					sizeof(int)) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}

static int	bfs(t_info *info)
{
	info->bfs.visited[info->end] = 1;
	while (info->bfs.queue)
	{
		llist_copy_front(
			info->bfs.current,
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
