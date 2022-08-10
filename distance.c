/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:39:42 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/04 16:39:43 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_index(int **adj_matrix, int *checked, int i, int size)
{
	int	j;

	j = -1;
	while (++j < size)
	{
		if ()
	}
}

static void	add_distance(t_info *info, int i, int dist)
{
	int		j;
	t_room	*temp;

	j = -1;
	while (++j < info->room_count)
	{
		if (info->adj_matrix[i][j] == 1)
		{
			temp = vec_get(&info->room_table, j);
			if (temp->distance == -1 || temp->distance > dist)
				temp->distance = dist;
		}
	}
}

int	iterate_matrix(t_info *info)
{
	static int	*checked;
	int			index;
	int			dist;

	checked = ft_memalloc(sizeof(int) * info->room_count);
	if (!checked)
		return (-1);
	dist = 1;
	index = info->end->matrix_index;
	while (index != info->start->matrix_index)
	{
		add_distance(info, index, dist);
		checked[index] = 1;
		index = find_index(info->adj_matrix, checked, index, info->room_count);
	}
	return (1);
}
