/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:10:16 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/02 15:10:17 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	initialize_path(t_vec *path)
{
	path->memory = NULL;
	path->len = 0;
	path->elem_size = sizeof(t_room *);
}

static int	insert_to_position(t_pathset *pathset, t_vec *path)
{
	size_t	i;
	t_vec	*saved_path;

	i = 0;
	while (i < pathset->paths.len)
	{
		saved_path = vec_get(&pathset->paths, i);
		if (saved_path->len >= path->len)
			break ;
		i++;
	}
	if (vec_insert(&pathset->paths, path, i) == -1)
		return (-1);
	return (1);
}

static t_room	*find_next_room(t_info *info, t_room *current)
{
	size_t	i;
	t_room	*next;
	int		next_index;

	i = 0;
	while (i < current->links.len)
	{
		next_index = *(int *)vec_get(&current->links, i++);
		if (info->adj_matrix[current->index][next_index] == FLOW)
		{
			next = vec_get(&info->room_table, next_index);
			return (next);
		}
	}
	return (NULL);
}

static int	add_path(t_info *info, t_pathset *pathset, t_room *current)
{
	t_vec	new_path;
	t_room	*next;

	initialize_path(&new_path);
	if (vec_push(&new_path, &current) == -1)
		return (-1);
	while (current->index != info->end)
	{
		next = find_next_room(info, current);
		if (!next)
			return (-1);
		if (vec_push(&new_path, &next) == -1)
			return (-1);
		current = next;
	}
	if (insert_to_position(pathset, &new_path) == -1)
		return (-1);
	return (1);
}

int	save_pathset(t_info *info, t_pathset *new_pathset)
{
	t_room	*current;
	t_room	*next;
	size_t	i;
	int		next_index;

	new_pathset->total_time = -1;
	if (vec_new(&new_pathset->paths, 1, sizeof(t_vec)) == -1)
		return (-1);
	current = vec_get(&info->room_table, info->start);
	i = 0;
	while (i < current->links.len)
	{
		next_index = *(int *)vec_get(&current->links, i++);
		if (info->adj_matrix[current->index][next_index] == FLOW)
		{
			next = vec_get(&info->room_table, next_index);
			if (add_path(info, new_pathset, next) == -1)
				return (free_pathset(new_pathset), -1);
		}
	}
	calculate_total_time(new_pathset, info->ant_count);
	return (1);
}
