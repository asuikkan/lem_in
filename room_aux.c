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
	if (info->start >= 0)
		return (-1);
	info->start = room->matrix_index;
	info->flags.start_flag = 0;
	return (1);
}

int	add_end(t_info *info, t_room *room)
{
	if (info->end >= 0)
		return (-1);
	info->end = room->matrix_index;
	info->flags.end_flag = 0;
	return (1);
}

int	push_room(t_info *info, t_room *room)
{
	if (vec_push(&info->room_table, room) == -1)
		return (-1);
	return (1);
}
