/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:46:03 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/05 18:46:07 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	initialize_bfs_path(t_info *info)
{
	info->bfs_path.queue = llist_new(&info->start->matrix_index, sizeof(int));
	if (!info->bfs_path.queue)
		return (-1);
	info->bfs_path.visited = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs_path.visited)
		return (-1);
	info->bfs_path.closed = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs_path.closed)
		return (-1);
	info->bfs_distance.index = ft_memalloc(sizeof(int));
	if (!info->bfs_path.index)
		return (-1);
	return (1);
}

int	pathfinder(t_info *info)
{
	if (initialize_bfs_path(info) == -1)
		return (-1);
	return (1);
}
