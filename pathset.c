/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:10:16 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/02 15:10:17 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	initialize_path(t_path *path, t_room *start)
{
	if (llist_push_back(&path->rooms, start, sizeof(t_room *)) == -1)
		retrun (-1);
	path->length = 0;
	return (1);
}

static int	initialize_pathset(t_pathset *pathset)
{
	if (vec_new(&pathset->paths, 1, sizeof(t_path)) == -1)
		return (-1);
	pathset->total_time = 0;
	return (1);
}

static int	save_path(t_info *info, t_pathset *pathset, int start)
{
	t_path	new;
	t_room	*current;
	t_room	*link;
	size_t	i;
	int		link_index;

	current = vec_get(&info->room_table, start);
	if (initialize_path(&new, current) == -1)
		return (-1);
	if (vec_push(&pathset->paths, &new) == -1)
		return (-1);
	i = 0;
	while (i < current->links.len)
	{
		link_index = *(int *)vec_get(&current->links, i++);
		if (info->adj_matrix[current->index][link_index] == FLOW)
		{
			link = vec_get(&info->room_table, link_index);
			if (llist_push_back(&new.rooms, link, sizeof(t_room *)) == -1)
				return (-1);
			current = link;
		}
	}
	return (1);
}

int	save_pathset(t_info *info, t_pathset *new_pathset)
{
	t_room		*current;
	size_t		i;
	int			link;

	if (initialize_pathset(new_pathset) == -1)
		return (-1);
	current = vec_get(&info->room_table, info->start);
	i = 0;
	while (i < current->links.len)
	{
		link = *(int *)vec_get(&current->links, i++);
		if (info->adj_matrix[current->index][link] == FLOW)
		{
			if (save_path(info, new_pathset, link) == -1)
				return (-1);
		}
	}
	return (1);
}
