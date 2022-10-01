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

/*static void	free_parents(int **parent_list, int size)
{
	int	i;

	i = -1;
	while (++i < size && parent_list[i])
		free(parent_list[i]);
	free(parent_list);
	parent_list = NULL;
}*/

static void	initialize_trace(t_trace *trace, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		trace[i].first_visit.done = 0;
		trace[i].first_visit.parent = -1;
		trace[i].first_visit.children.memory = NULL;
		trace[i].first_visit.children.elem_size = sizeof(int);
		trace[i].second_visit.done = 0;
		trace[i].second_visit.parent = -1;
		trace[i].second_visit.children.memory = NULL;
		trace[i].second_visit.children.elem_size = sizeof(int);
		trace[i].entry_history = NONE;
	}
}

static void	free_trace(t_trace *trace, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		vec_free(&trace->first_visit.children);
		vec_free(&trace->second_visit.children);
	}
	free(trace);
}

/*static int	initialize_parent_list(int **list, int size)
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
}*/

int	initialize_bfs(t_info *info)
{
	info->bfs.current = info->start;
	info->bfs.trace = (t_trace *)malloc(sizeof(t_trace) * info->room_count);
	if (!info->bfs.trace)
		return (-1);
	/*if (initialize_parent_list(info->bfs.trace, info->room_count) == -1)
		return (-1);*/
	initialize_trace(info->bfs.trace, info->room_count);
	return (1);
}

void	free_bfs(t_bfs *bfs, int size)
{
	//free(bfs->visited);
	//bfs->visited = NULL;
	//if (bfs->trace)
	//	free_parents(bfs->trace, size);
	//bfs->parent = NULL;
	free_trace(&bfs->trace, size);
	bfs->trace = NULL;
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
