/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:53:17 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/05 18:53:19 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	update_visitation(t_info *info, int current, int target)
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

int	update_trace(t_trace *trace, t_visit *visit, int target, int parent)
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
