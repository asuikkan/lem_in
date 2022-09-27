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
	if (state == NO_FLOW)
	{
		info->adj_matrix[from][to] = FLOW;
		info->adj_matrix[to][from] = NEGATIVE_FLOW;
		((t_room *)(vec_get(&info->room_table, from)))->flow_to = to;
		((t_room *)(vec_get(&info->room_table, to)))->flow_from = from;
	}
	else if (state == NEGATIVE_FLOW)
	{
		info->adj_matrix[from][to] = NO_FLOW;
		info->adj_matrix[to][from] = NO_FLOW;
		((t_room *)(vec_get(&info->room_table, from)))->flow_to = -1;
		((t_room *)(vec_get(&info->room_table, to)))->flow_from = -1;
	}
}

void	update_flow(t_info *info)
{
	t_room	*parent;
	t_room	*current;
	int		state;

	current = vec_get(&info->room_table, info->bfs.current);
	while (current->index != info->start)
	{
		parent = vec_get(&info->room_table, info->bfs.parent[current->index]);
		state = info->adj_matrix[parent->index][current->index];
		update_link(info, parent->index, current->index, state);
		current = parent;
	}
}
