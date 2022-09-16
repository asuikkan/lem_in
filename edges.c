/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:11:24 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/26 16:11:27 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_link(t_edge *edge, int current)
{
	if (edge->from == current)
		return (edge->to);
	else
		return (edge->from);
}

int	add_to_edge_list(t_vec *edge_list, int room1, int room2)
{
	t_edge	edge;

	edge.from = room1;
	edge.to = room2;
	edge.flow = 0;
	if (vec_push(edge_list, &edge) == -1)
		return (0);
	return (1);
}

int	add_adjacency(t_vec *edge_list, t_room *room1, t_room *room2)
{
	t_edge *edge;

	edge = vec_get(edge_list, edge_list->len - 1);
	if (vec_push(&room1->edges, edge) == -1)
		return (0);
	if (vec_push(&room2->edges, edge) == -1)
		return (0);
	return (1);
}
