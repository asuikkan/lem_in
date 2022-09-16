/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:46:03 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/05 18:46:07 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*find_next_room(t_info *info, t_room *room)
{
	int		i;
	int		lowest_dist;
	t_room	*temp;
	t_room	*ret;

	lowest_dist = -1;
	ret = NULL;
	i = -1;
	while (++i < info->room_count)
	{
		if (i == room->matrix_index)
			continue ;
		if (info->adj_matrix[room->matrix_index][i] == 1)
		{
			temp = vec_get(&info->room_table, i);
			if (lowest_dist < 0 || temp->distance < lowest_dist)
				ret = temp;
		}
	}
	return (ret);
}

static int	shortest_path(t_info *info, t_vec *path, int *closed_list)
{
	t_room	*current;

	current = info->start;
	while (current->distance > 0)
	{
		current = find_next_room(info, current);
		ft_printf("current name: %s\n", current->name);
		ft_printf("current adr:  %p\n", current);
		ft_printf("end adr:      %p\n", info->end);
		if (!current)
		{
			free(path);
			path = NULL;
			return (0);
		}
		if (vec_push(path, &current->matrix_index) == -1)
			return (-1);
		closed_list[current->matrix_index] = 1;
	}
	return (1);
}

static int	form_path(t_info *info, t_vec *path, int *closed_list)
{
	if (shortest_path(info, path, closed_list) == -1)
		return (-1);
	if (!path)
		return (0);
	return (1);
}

int	pathfinder(t_info *info)
{
	t_lists lists;
	t_vec	path;
	int		found_path;

	if (vec_new(&path, 2, sizeof(int)) == -1)
		return (-1);
	lists.closed = ft_memalloc(sizeof(int) * info->room_count);
	if (!lists.closed)
		return (-1);
	lists.open = ft_memalloc(sizeof(int) * info->room_count);
	if (!lists.open)
		return (-1);
	found_path = form_path(info, &path, lists.closed);
	if (found_path == -1)
		return (-1);
	return (1);
}
