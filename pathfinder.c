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

<<<<<<< HEAD
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
=======
static int	augmenting_paths(t_info *info)
{
	int	state;

	state = bfs(info);
	if (state == ERROR)
		free_and_exit(info, 1);
	if (state == PATH_NOT_FOUND)
		return (0);
	else
		return (1);
>>>>>>> adj_rework
}

int	pathfinder(t_info *info)
{
<<<<<<< HEAD
	if (initialize_bfs_path(info) == -1)
=======
	if (initialize_bfs(info) == -1)
		return (-1);
	while (augmenting_paths(info))
	{
		update_flow(info);
		if (save_pathset(info, &info->pathset) == -1)
			return (-1);
		compare_pathsets(&info->pathset);
		if (reset_bfs(info) == -1)
			return (-1);
	}
	if (info->pathset.paths.memory == NULL)
>>>>>>> adj_rework
		return (-1);
	return (1);
}
