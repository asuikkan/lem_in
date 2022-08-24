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

static void	free_matrix(int	**matrix, int size)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
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

void	free_and_exit(t_info *info, int error_flag)
{
	if (error_flag)
		write(1, "ERROR\n", 6);
	free_table(&info->room_table);
	vec_free(&info->hash_table);
	free_matrix(info->adj_matrix, info->room_count);
	exit(1);
}
