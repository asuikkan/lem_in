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

unsigned long	hash(char *str, size_t len)
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
	hash = hash % len;
	return (hash);
}

static int	init_hash_table(t_vec *dst, t_vec *src)
{
	if (vec_new(dst, src->len, sizeof(t_room *)) == -1)
		return (-1);
	return (1);
}

static void	add_to_list(t_room *dst, t_room *src)
{
	while (dst->next)
		dst = dst->next;
	dst->next = src;
}

int	hasher(t_info *info)
{
	t_room			*temp;
	t_room			*slotted;
	size_t			i;
	unsigned long	index;

	if (init_hash_table(&info->hash_table, &info->room_table) == -1)
		return (-1);
	i = 0;
	while (i < info->room_table.len)
	{
		index = 0;
		temp = vec_get(&info->room_table, i++);
		index = hash(temp->name, info->room_table.len);
		slotted = *(t_room **)vec_get(&info->hash_table, index);
		if (!slotted)
		{
			if (vec_overwrite(&info->hash_table, &temp, index) == -1)
				return (-1);
		}
		else
			add_to_list(slotted, temp);
	}
	return (1);
}
