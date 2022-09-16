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

static void	free_matrix(int	**matrix)
{
	size_t	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		ft_memdel((void **)&matrix[i]);
		i++;
	}
	ft_memdel((void **)matrix);
}

static void	free_room(t_room *room)
{
	if (room->name)
		ft_strdel(&room->name);
	if (room->next)
		free_room(room->next);
}

static void	free_table(t_vec *table)
{
	size_t	i;
	t_room	*temp;

	if (table->len > 0)
	{
		i = 0;
		while (i < table->len)
		{
			temp = vec_get(table, i);
			free_room(temp);
			i++;
		}
	}
	vec_free(table);
}

void	free_info(t_info *info)
{
	free_table(&info->room_table);
	vec_free(&info->hash_table);
	free_matrix(info->adj_matrix);
}
