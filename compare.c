/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:26:19 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/09 15:26:20 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_paths(t_vec *paths) 
{
	size_t	i;
	t_path	*path;

	i = 0;
	while (i < paths->len)
	{
		path = vec_get(paths, i++);
		llist_free(&path->rooms);
	}
	vec_free(paths);
}

static int	copy_pathset(t_pathset *dst, t_pathset *src)
{
	if (dst->paths.memory)
		free_paths(&dst->paths);
	if (vec_from(&dst->paths,
		src->paths.memory,
		src->paths.len,
		src->paths.elem_size) == -1)
		return (-1);
	dst->total_time = src->total_time;
	return (1);
}

int	compare_pathsets(t_info *info, t_pathset *new_pathset)
{
	if (!info->best_pathset.paths.memory
		|| info->best_pathset.total_time > new_pathset->total_time)
	{
		if (copy_pathset(&info->best_pathset, new_pathset) == -1)
			return (-1);
	}
	vec_free(&new_pathset->paths);
	//free_paths(&new_pathset->paths);
	return (1);
}