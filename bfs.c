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

/*static int	validate_visit(t_info *info, t_room *current, t_room *target)
{
	if (info->bfs.parent[current->index][0] == target->index
		|| info->bfs.parent[current->index][1] == target->index)
		return (0);
	if (info->bfs.visited[target->index] == BOTH)
		return (0);
	if (info->bfs.visited[target->index] == POSITIVE
		&& info->adj_matrix[current->index][target->index] == NO_FLOW)
		return (0);
	if (info->bfs.visited[target->index] == NEGATIVE
		&& info->adj_matrix[current->index][target->index] == NEGATIVE_FLOW)
		return (0);
	return (1);
}*/

/*static void	update_visitation(t_info *info, t_room *current, t_room *target)
{
	if (info->bfs.visited[target->index] == POSITIVE
		|| info->bfs.visited[target->index] == NEGATIVE)
		info->bfs.visited[target->index] = BOTH;
	else if (info->adj_matrix[current->index][target->index] == NO_FLOW)
		info->bfs.visited[target->index] = POSITIVE;
	else
		info->bfs.visited[target->index] = NEGATIVE;
}*/

/*static void	update_parents(t_trace *trace, int target, int parent)
{
	if (parent_list[target][0] < 0)
		parent_list[target][0] = parent;
	else
		parent_list[target][1] = parent;
}*/

static void	update_trace(t_info *info, int target, int parent) //finish here!!
{
	t_visit	*visit;

	if (!info->bfs.trace[target].first_visit.done)
		visit = &info->bfs.trace[target].first_visit;
	else
		visit = &info->bfs.trace[target].second_visit;
	visit->parent = parent;
	update_children(info, target);
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
			update_parents(info->bfs.parent, target_index, current->index);
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

	/*current = vec_get(&info->room_table, info->bfs.current);
	if (current->flow_from >= 0
		&& info->bfs.trace[current->index].entry_history == POSITIVE)
	{
		update_trace(info,
			current->flow_from,
			current->index);
		update_visitation(info,
			current,
			vec_get(&info->room_table, current->flow_from));
		if (llist_push(&info->bfs.queue,
				&current->flow_from,
				sizeof(int)) == -1)
			return (-1);
		return (1);
	}*/
	//else
		return (iterate_links(info, current));
}

int	bfs(t_info *info)
{
	info->bfs.trace[info->start].entry_history = BOTH;
	llist_push(&info->bfs.queue, &info->start, sizeof(int));
	while (info->bfs.queue)
	{
		if (llist_pop(&info->bfs.current, &info->bfs.queue) == -1)
			return (ERROR);
		if (info->bfs.current == info->end)
			return (PATH_FOUND);
		if (check_adjacent(info) == -1)
			return (ERROR);
	}
	return (PATH_NOT_FOUND);
}
