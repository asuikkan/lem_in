/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:13:18 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/14 12:13:19 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned long	hash(char *str)
{
	unsigned long	hash;
	int				c;
	int				i;

	hash = 5381;
	i = -1;
	while (str[++i])
	{
		c = str[i];
		hash = ((hash << 5) + hash) + c;
	}
	return (hash);
}

int	hasher(t_info *info)
{
	t_vec			hash_table;
	t_room			*temp;
	size_t			i;
	unsigned long	index;

	if (vec_new(
			&hash_table, info->room_table->len,
			info->room_table->elem_size) == -1)
		return (-1);
	i = 0;
	while (i < info->room_table->len)
	{
		index = 0;
		temp = vec_get(info->room_table, i++);
		index = hash(temp->name);
		index = index % info->room_table->len;
		if (!vec_get(info->room_table, index))
		{
			if (vec_insert(&hash_table, temp, index) == -1)
				return (-1);
		}
		else
			
	}
	return (1);
}
