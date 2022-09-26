/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:46:36 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/26 10:46:40 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	initialize_parent_list(int **list, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		(*list)[i] = -1;
}

int	initialize_bfs(t_info *info)
{
	info->bfs.visited = ft_memalloc(sizeof(int) * info->room_count);
	if (!info->bfs.visited)
		return (-1);
	info->bfs.current = info->start;
	info->bfs.parent = (int *)malloc(sizeof(int) * info->room_count);
	if (!info->bfs.parent)
		return (-1);
	initialize_parent_list(&info->bfs.parent, info->room_count);
	return (1);
}

int	reset_bfs(t_info *info)
{
	free(info->bfs.visited);
	free(info->bfs.parent);
	llist_free(&info->bfs.queue);
	if (initialize_bfs(info) == -1)
		return (-1);
	return (1);
}
