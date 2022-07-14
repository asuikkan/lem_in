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

static void	free_links(char ***links)
{
	int	i;

	i = -1;
	while ((*links)[++i])
		ft_strdel(&(*links)[i]);
	free(*links);
}

int	free_room(t_room *room)
{
	if (room->name)
		free(room->name);
	if (room->links)
		free_links(&room->links);
	if (room->next)
		free_room(room->next);
	return (-1);
}

void	error_handler(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	free_info(t_info *info)
{
	size_t	i;
	t_room	*temp;

	if (info->room_table.len > 0)
	{
		i = 0;
		while (i < info->room_table.len)
		{
			temp = vec_get(&info->room_table, i);
			free_room(temp);
			i++;
		}
	}
	if (info->start)
		free(info->start);
	if (info->end)
		free(info->end);
	vec_free(&info->room_table);
}
