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

}

int	add_end(t_info *info, t_room *room)
{
	
}

int	push_room(t_info *info, t_room *room)
{
	static t_vec	table;

	if (!info->room_table)
	{
		if (vec_new(&table, 2, sizeof(t_room)) == -1)
			return (-1);
		info->room_table = &table;
	}
	if (vec_push(info->room_table, &room) == -1)
		return (-1);
	return (1);
}
