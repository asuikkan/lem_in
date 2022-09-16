/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:50:54 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/02 17:50:55 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	initialize_bfs(t_info *info)
{
	if (vec_new(&info->bfs.current_path, 2, sizeof(t_path)) == -1)
		return (-1);
	info->bfs.current_path->total_time = 0;
	info->bfs.visited = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs.visited)
		return (-1);
	info->bfs.current = ft_memalloc(sizeof(int));
	if (!info->bfs.current)
		return (-1);
	info->bfs.parents = (int *)malloc(sizeof(int) * info->room_count);
	if (!info->bfs.parents)
		return (-1);
	ft_memset(info->bfs.parents, -1, info->room_count);
	return (1);
}

static int	check_adjacent(t_info *info)
{
	t_room	*current;
	size_t	i;
	int		target;
	t_edge	*edge;

	current = vec_get(&info->room_table, *info->bfs.current);
	i = 0;
	while (i < current->edges.len)
	{
		edge = vec_get(&current->edges, i++);
		target = get_link(edge, current->index);
		if (!info->bfs.visited[target])
		{
			if (info->bfs.parents[target] < 0)
				info->bfs.parents[target] = *info->bfs.current;
			info->bfs.visited[target] = 1;
			if (llist_push_back(
					&info->bfs.queue,
					&target,
					sizeof(int)) == -1)
				return (ERROR);
		}
	}
	return (0);
}

int	bfs(t_info *info)
{
	info->bfs.visited[info->start] = 1;
	llist_push_back(&info->bfs.queue, &info->start, sizeof(int));
	while (info->bfs.queue)
	{
		ft_memcpy(info->bfs.current, info->bfs.queue, sizeof(int));
		if (*info->bfs.current == info->end)
			return (PATH_FOUND);
		llist_pop(&info->bfs.queue);
		if (check_adjacent(info) == -1)
			return (ERROR);
	}
	return (PATH_NOT_FOUND);
}
