/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset_comparison.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:55:46 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/25 14:55:48 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	calculate_time(t_info *info, int new_length)
{
	int	time_reduction;

	if (!info->pathsets.current.total_time)
		return (new_length + info->ant_count - 1);
	time_reduction = info->pathsets.current.total_time - new_length;
	return (info->pathsets.current.total_time - time_reduction);
}

int	is_better_path(t_info *info, t_room *end)
{
	t_path	new;
	t_room	*previous;

	new.length = 1;
	if (llist_push(&new.room, &end->matrix_index, sizeof(int)) == -1)
		return (-1);
	previous = end->parent;
	while (previous)
	{
		if (llist_push(&new.room, &previous->matrix_index, sizeof(int)) == -1)
			return (-1);
		new.length++;
		previous = previous->parent;
	}
	if (!info->pathsets.current.total_time || new.length < info->pathsets.current.total_time)
	{
		if (vec_push(&info->pathsets.current.paths, &new) == -1)
			return (-1);
		info->pathsets.current.total_time = calculate_time(info, new.length);
		return (1);
	}
	return (0);
}
