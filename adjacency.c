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

int	add_adjacency(t_room *room1, t_room *room2)
{
	if (vec_push(&room1->links, &room2->index) == -1)
		return (-1);
	if (vec_push(&room2->links, &room1->index) == -1)
		return (-1);
	return (1);
}

t_adj_state	**create_matrix(size_t size)
{
	t_adj_state	**matrix;
	size_t		i;

	matrix = ft_memalloc(sizeof(t_adj_state *) * size);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < size)
	{
		matrix[i] = ft_memalloc(sizeof(t_adj_state) * size);
		if (!matrix[i])
			return (NULL);
		i++;
	}
	return (matrix);
}

void	initialize_flow(t_adj_state **adj_matrix, t_room *room1, t_room *room2)
{	
	adj_matrix[room1->index][room2->index] = NO_FLOW;
	adj_matrix[room2->index][room1->index] = NO_FLOW;
}
