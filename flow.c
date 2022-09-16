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

static void	update_link(t_adj_state **matrix, int from, int to, int state)
{
	if (state == FLOW)
		return ;
	if (state == NO_FLOW)
	{
		matrix[from][to] = FLOW;
		matrix[to][from] = NEGATIVE_FLOW;
	}
	else if (state == NEGATIVE_FLOW)
	{
		matrix[from][to] = NO_FLOW;
		matrix[to][from] = NO_FLOW;
	}
}

void	update_flow(t_info *info)
{
	int	parent;
	int	current;
	int	state;

	current = info->bfs.current;
	while (current != info->start)
	{
		parent = info->bfs.parent[current];
		state = info->adj_matrix[parent][current];
		update_link(info->adj_matrix, parent, current, state);
		current = parent;
	}
}
