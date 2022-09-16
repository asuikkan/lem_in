/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:39:45 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/12 17:39:46 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	add_start(t_info *info, t_room *room)
{
	if (info->start)
		return (-1);
	info->start = (t_room *)malloc(sizeof(room));
	if (!info->start)
		return (-1);
	ft_memcpy(info->start, room, sizeof(room));
	info->start_flag = 0;
	return (1);
}

int	add_end(t_info *info, t_room *room)
{
	t_room	*end;

	if (info->end)
		return (-1);
	info->end = (t_room *)malloc(sizeof(room));
	if (!info->end)
		return (-1);
	end = vec_get(&info->room_table, room->matrix_index);
	end->distance = 0;
	room->distance = 0;
	ft_memcpy(info->end, room, sizeof(room));
	info->end_flag = 0;
	return (1);
}

int	push_room(t_info *info, t_room *room)
{
	if (vec_push(&info->room_table, room) == -1)
		return (-1);
	return (1);
}
