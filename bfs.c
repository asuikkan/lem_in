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

static int	validate_visit(t_info *info,
	t_visit *visit, t_room *current, t_room *target)
{
	if (visit->parent == target->index)
		return (0);
	if (info->bfs.trace[target->index].entry_history == BOTH)
		return (0);
	if (info->bfs.trace[target->index].entry_history == POSITIVE
		&& info->adj_matrix[current->index][target->index] == NO_FLOW)
		return (0);
	if (info->bfs.trace[target->index].entry_history == NEGATIVE
		&& info->adj_matrix[current->index][target->index] == NEGATIVE_FLOW)
		return (0);
	return (1);
}

static void	update_visitation(t_info *info, int current, int target)
{
	t_entries	*history;

	history = &info->bfs.trace[target].entry_history;
	if (*history == POSITIVE || *history == NEGATIVE)
		*history = BOTH;
	else if (info->adj_matrix[current][target] == NO_FLOW)
		*history = POSITIVE;
	else
		*history = NEGATIVE;
}

static int	update_trace(t_trace *trace, t_visit *visit, int target, int parent)
{
	if (trace[target].first_visit.parent < 0)
		trace[target].first_visit.parent = parent;
	else if (trace[target].second_visit.parent < 0)
		trace[target].second_visit.parent = parent;
	else
		return (-1);
	if (vec_push(&visit->children, &target) == -1)
		return (-1);
	return (1);
}

static int	iterate_links(t_info *info, t_room *current, t_visit *visit)
{
	int		target_index;
	size_t	i;
	t_room	*target;

	i = 0;
	while (i < current->links.len)
	{
		target_index = *(int *)vec_get(&current->links, i++);
		target = vec_get(&info->room_table, target_index);
		if (validate_visit(info, visit, current, target)
			&& info->adj_matrix[current->index][target_index] != FLOW)
		{
			if (update_trace(info->bfs.trace, visit, target_index, current->index) == -1)
				return (-1);
			update_visitation(info, current->index, target_index);
			if (llist_push(
					&info->bfs.queue,
					&target_index,
					sizeof(int)) == -1)
				return (-1);
		}
	}
	return (1);
}

static int	check_adjacent(t_info *info, t_visit *visit)
{
	t_room	*current;

	current = vec_get(&info->room_table, info->bfs.current);
	if (current->flow_from >= 0
		&& info->adj_matrix[visit->parent][info->bfs.current] == NO_FLOW)
	{
		update_trace(info->bfs.trace,
			visit,
			current->flow_from,
			current->index);
		update_visitation(info, current->index, current->flow_from);
		if (llist_push(&info->bfs.queue,
				&current->flow_from,
				sizeof(int)) == -1)
			return (-1);
		return (1);
	}
	else
		return (iterate_links(info, current, visit));
}

int	bfs(t_info *info)
{
	t_visit	*visit;

	info->bfs.trace[info->start].entry_history = BOTH;
	llist_push(&info->bfs.queue, &info->start, sizeof(int));
	while (info->bfs.queue)
	{
		if (llist_pop(&info->bfs.current, &info->bfs.queue) == -1)
			return (ERROR);
		if (info->bfs.current == info->end)
			return (PATH_FOUND);
		if (!info->bfs.trace[info->bfs.current].first_visit.done)
			visit = &info->bfs.trace[info->bfs.current].first_visit;
		else
			visit = &info->bfs.trace[info->bfs.current].second_visit;
		if (check_adjacent(info, visit) == -1)
			return (ERROR);
		visit->done = 1;
	}
	return (PATH_NOT_FOUND);
}
