/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:01:54 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/27 14:01:55 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_parents(int **parent_list, int size)
{
	int	i;

	i = -1;
	while (++i < size && parent_list[i])
		free(parent_list[i]);
	free(parent_list);
}

static int	initialize_parent_list(int **list, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		list[i] = (int *)malloc(sizeof(int) * 2);
		if (!list[i])
			return (-1);
		list[i][0] = -1;
		list[i][1] = -1;
	}
	return (1);
}

int	initialize_bfs(t_info *info)
{
	info->bfs.visited = ft_memalloc(sizeof(t_entries) * info->room_count);
	if (!info->bfs.visited)
		return (-1);
	info->bfs.current = info->start;
	info->bfs.parent = (int **)malloc(sizeof(int *) * info->room_count);
	if (!info->bfs.parent)
		return (-1);
	if (initialize_parent_list(info->bfs.parent, info->room_count) == -1)
		return (-1);
	return (1);
}

void	free_bfs(t_bfs *bfs, int size)
{
	free(bfs->visited);
	bfs->visited = NULL;
	if (bfs->parent)
		free_parents(bfs->parent, size);
	bfs->parent = NULL;
	llist_free(&bfs->queue);
	bfs->queue = NULL;
}

int	reset_bfs(t_info *info)
{
	free_bfs(&info->bfs, info->room_count);
	if (initialize_bfs(info) == -1)
		return (-1);
	return (1);
}
