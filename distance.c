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
	info->bfs_distance.visited = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs_distance.visited)
		return (-1);
	return (1);
}

static int	bfs(t_info *info)
{
	t_room	*temp;
	int		*t;
	int		index;
	int		i;
	int		dist;

	index = info->end->matrix_index;
	info->bfs_distance.visited[index] = 1;
	if (llist_new(info->bfs_distance.queue, &index, sizeof(int)) == -1)
		return (-1);
	dist = 1;
	while (info->bfs_distance.queue)
	{
		llist_pop(info->bfs_distance.queue);
		i = -1;
		while (++i < info->room_count)
		{
			if (info->adj_matrix[index][i] == 1 && !info->bfs_distance.visited[i])
			{
				temp = vec_get(&info->room_table, i);
				temp->distance = 1;
				info->bfs_distance.visited[i] = 1;
				if (vec_insert(&QUEUE, &i, 0) == -1)
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
