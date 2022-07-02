/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:11:02 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/02 16:11:04 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_handler(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

static void	free_room(t_room *room)
{
	if (!room)
		return ;
	free_room(room->left);
	free_room(room->right);
	free(room);
}

void	free_info(t_info *info)
{
	int		i;

	i = -1;
	while (++i < 128)
	{
		if (info->table[i])
			free_room(info->table[i]);
	}
	free(info);
}
