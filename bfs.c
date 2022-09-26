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
	info->bfs.visited = ft_memalloc(sizeof(t_entries) * info->room_count);
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

static int	validate_visit(t_info *info, t_room *current, t_room *target)
{
	if (info->bfs.visited[target->index] == BOTH)
		return (0);
	if (info->bfs.visited[target->index] == POSITIVE && info->adj_matrix[current->index][target->index] == NO_FLOW)
		return (0);
	if (info->bfs.visited[target->index] == NEGATIVE && info->adj_matrix[current->index][target->index] == NEGATIVE_FLOW)
		return (0);
	return (1);
}

static void	update_visitation(t_info *info, t_room *current, t_room *target)
{
	if (info->bfs.visited[target->index] == POSITIVE || info->bfs.visited[target->index] == NEGATIVE)
		info->bfs.visited[target->index] = BOTH;
	else if (info->adj_matrix[current->index][target->index] == NO_FLOW)
		info->bfs.visited[target->index] = POSITIVE;
	else
		info->bfs.visited[target->index] = NEGATIVE;
}

static int	iterate_links(t_info *info, t_room *current)
{
	int		target_index;
	size_t	i;
	t_room	*target;

	i = 0;
	while (i < current->links.len)
	{
		target_index = *(int *)vec_get(&current->links, i++);
		target = vec_get(&info->room_table, target_index);
		if (validate_visit(info, current, target)
			&& info->adj_matrix[current->index][target_index] != FLOW)
		{
			if (info->bfs.parent[target_index] < 0)
				info->bfs.parent[target_index] = current->index;
			update_visitation(info, current, target);
			if (llist_push(
					&info->bfs.queue,
					&target_index,
					sizeof(int)) == -1)
				return (-1);
		}
	}
	return (1);
}

static int	check_adjacent(t_info *info)
{
	t_room	*current;

	current = vec_get(&info->room_table, info->bfs.current);
	if (current->flow_from >= 0 && info->bfs.visited[current->index] == POSITIVE)
	{
		if (info->bfs.parent[current->flow_from] < 0)
			info->bfs.parent[current->flow_from] = info->bfs.current;
		update_visitation(info, current, vec_get(&info->room_table, current->flow_from));
		if (llist_push(&info->bfs.queue, &current->flow_from, sizeof(int)) == -1)
			return (-1);
		return (1);
	}
	else
		return (iterate_links(info, current));
}

int	bfs(t_info *info)
{
	info->bfs.visited[info->start] = BOTH;
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
