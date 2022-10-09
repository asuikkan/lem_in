/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:01:29 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/07 11:01:30 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	update_link(t_info *info, int from, int to, int state)
{
	t_room *room;

	room = vec_get(&info->room_table, to);
	if (state == NO_FLOW)
	{
		room = vec_get(&info->room_table, to);
		room->flow_from = from;
		info->adj_matrix[from][to] = FLOW;
		info->adj_matrix[to][from] = NEGATIVE_FLOW;
		
	}
	else if (state == NEGATIVE_FLOW)
	{
		room = vec_get(&info->room_table, from);
		room->flow_from = -1;
		info->adj_matrix[from][to] = NO_FLOW;
		info->adj_matrix[to][from] = NO_FLOW;
	}
}

int	check_parent(t_trace *trace, int current, int prev)
{
	int			child;
	t_visit		*visit;
	size_t		i;

	visit = &trace[current].first_visit;
	if (!trace[current].second_visit.done)
		return (visit->parent);
	else
	{
		i = 0;
		while (i < visit->children.len)
		{
			child = *(int *)vec_get(&visit->children, i++);
			if (child == prev)
				return (visit->parent);
		}
	}
	return (trace[current].second_visit.parent);
}

void	update_flow(t_info *info)
{
	int		prev;
	int		parent;
	int		current;
	int		state;

	prev = -1;
	current = info->bfs.current;
	while (current != info->start)
	{
		parent = check_parent(info->bfs.trace, current, prev);
		state = info->adj_matrix[parent][current];
		update_link(info, parent, current, state);
		prev = current;
		current = parent;
	}
}
