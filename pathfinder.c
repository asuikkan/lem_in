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

static int	create_path_list(t_info *info)
{
	t_room	*room;
	size_t	possible_paths;

	room = vec_get(&info->room_table, info->start);
	possible_paths = room->links.len;
	room = vec_get(&info->room_table, info->end);
	if (room->links.len < possible_paths)
		possible_paths = room->links.len;
	if (vec_new(&info->path_list, possible_paths, sizeof(t_path)) == -1)
		return (-1);
	return (1);
}

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
}

int	pathfinder(t_info *info)
{
	if (initialize_bfs(info) == -1)
		return (-1);
	if (create_path_list(info) == -1)
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
	return (1);
}
