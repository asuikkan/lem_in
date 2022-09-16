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

static void	initialize_parent_list(int **list, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		(*list)[i] = -1;
}

int	initialize_bfs(t_info *info)
{
	info->bfs.visited = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs.visited)
		return (-1);
	info->bfs.current = info->start;
	info->bfs.parent = (int *)malloc(sizeof(int) * info->room_count);
	if (!info->bfs.parent)
		return (-1);
	initialize_parent_list(&info->bfs.parent, info->room_count);
	return (1);
}

int	reset_bfs(t_info *info)
{
	free(info->bfs.visited);
	free(info->bfs.parent);
	llist_free(&info->bfs.queue);
	if (initialize_bfs(info) == -1)
		return (-1);
	return (1);
}

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
		if (!info->bfs.visited[target]
			&& info->adj_matrix[current->index][target] != FLOW)
		{
			if (info->bfs.parent[target] < 0)
				info->bfs.parent[target] = info->bfs.current;
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
		llist_copy_front(&info->bfs.current, info->bfs.queue);
		if (info->bfs.current == info->end)
			return (PATH_FOUND);
		llist_pop(&info->bfs.queue);
		if (check_adjacent(info) == -1)
			return (ERROR);
	}
	return (PATH_NOT_FOUND);
}
