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

/*static void	add_distance(t_info *info, int i, int dist)
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
}*/

int	iterate_matrix(t_info *info)
{
	t_vec	queue;
	int		*visited;
	int		dist;
	int		i;

	if (vec_new(&queue, 2, sizeof(int)) == -1)
		return (-1);
	visited = 
	dist = 0;
	i = -1;
	while (++i < info->room_count)
	{
		
	}
	return (1);
}
