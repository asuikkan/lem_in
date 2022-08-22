/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:39:42 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/04 16:39:43 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	initialize_bfs_distance(t_info *info)
{
	QUEUE = llist_new(&END->matrix_index, sizeof(int));
	if (!QUEUE)
		return (-1);
	VISITED = ft_memalloc(sizeof(int) * info->room_count);
	if (!VISITED)
		return (-1);
	DISTANCE_INDEX = (int *)malloc(sizeof(int));
	if (!DISTANCE_INDEX)
		return (-1);
	return (1);
}

static int	bfs(t_info *info)
{
	t_room	*temp;
	int		i;
	int		dist;

	VISITED[END->matrix_index] = 1;
	dist = 1;
	while (QUEUE)
	{
		ft_memcpy(DISTANCE_INDEX, llist_copy_front(QUEUE), sizeof(int));
		llist_pop(&QUEUE);
		i = -1;
		while (++i < info->room_count)
		{
			if (ADJ_MATRIX[*DISTANCE_INDEX][i] == 1 && !VISITED[i])
			{
				temp = vec_get(&info->room_table, i);
				temp->distance = dist;
				VISITED[i] = 1;
				if (llist_push_back(&QUEUE, &i, sizeof(int)) == -1)
					return (-1);
			}
		}
		dist++;
	}
	return (1);
}

int	add_distances(t_info *info)
{
	if (initialize_bfs_distance(info) == -1)
		return (-1);
	bfs(info);
	return (1);
}
