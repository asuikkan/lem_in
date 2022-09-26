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

static int	check_adjacent(t_info *info)
{
	t_room	*current;
	size_t	i;
	int		target;

	current = vec_get(&info->room_table, info->bfs.current);
	i = 0;
	while (i < current->links.len)
	{
		target = *(int *)vec_get(&current->links, i++);
		if (!info->bfs.visited[target] && current->flow_to != target)
		{
			if (current->flow_from >= 0)
				//validate_path()
			info->bfs.parent[target] = info->bfs.current;
			info->bfs.visited[target] = 1;
			if (llist_push(
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
	llist_push(&info->bfs.queue, &info->start, sizeof(int));
	while (info->bfs.queue)
	{
		llist_copy_front(&info->bfs.current, info->bfs.queue);
		if (info->bfs.current == info->end)
			return (PATH_FOUND);
		llist_pop(&info->bfs.queue);
		if (check_adjacent(info) == -1)
			return (ERROR);
	}
	return (PATH_NOT_FOUND);
}
