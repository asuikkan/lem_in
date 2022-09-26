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

static void	calculate_total_time(t_pathset *pathset, int ant_count)
{
	int		time;
	int		sum;
	size_t	ants;
	t_path	*path;
	size_t	i;

	ants = ant_count;
	sum = 0;
	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i++);
		sum += path->rooms.len;
		if (ants <= path->rooms.len * i - sum)
			break ;
		ants -= path->rooms.len * i - sum - 1;
		time = path->rooms.len;
	}
	time += ants / i + ((ants % i) > 0);
	pathset->total_time = time;
}

static void	initialize_path(t_path *path)
{
	path->name = NULL;
	path->rooms.memory = NULL;
	path->rooms.elem_size = sizeof(int);
	path->hash_collision = NULL;
}

static int	insert_to_position(t_pathset *pathset, t_path *path)
{
	size_t	i;
	t_path	*saved_path;

	i = 0;
	while (i < pathset->paths.len)
	{
		saved_path = vec_get(&pathset->paths, i);
		if (saved_path->rooms.len >= path->rooms.len)
			break ;
		i++;
	}
	if (vec_insert(&pathset->paths, path, i) == -1)
		return (-1);
	return (1);
}

static int	find_next_room(t_info *info, int current)
{
	t_room	*room;
	size_t	i;
	int		next;

	room = vec_get(&info->room_table, current);
	i = 0;
	while (i < room->links.len)
	{
		next = *(int *)vec_get(&room->links, i++);
		if (info->adj_matrix[room->index][next] == FLOW)
			return (next);
	}
	return (NULL);
}

static int	add_room(t_path *path, t_room *room)
{
	char	*temp;

	temp = path->name;
	if (!temp)
		path->name = ft_strdup(room->name);
	else
	{
		path->name = ft_strjoin(path->name, room->name);
		ft_strdel(&temp);
	}
	if (!path->name)
		return (-1);
	if (vec_push(&path->rooms, &room->index) == -1)
		return (-1);
	return (1);
}

static int	add_path(t_info *info, t_pathset *pathset, int start)
{
	t_path	new_path;
	int		current;
	int		next;

	initialize_path(&new_path);
	current = start;
	if (add_room(&new_path, vec_get(&info->room_table, current)) == -1)
		return (-1);
	while (current != info->end)
	{
		next = find_next_room(info, current);
		if (!next)
			return (-1);
		current = next;
		if (add_room(&new_path, vec_get(&info->room_table, current)) == -1)
			return (-1);
	}
	if (insert_to_position(pathset, &new_path) == -1)
		return (-1);
	return (1);
}

int	save_pathset(t_info *info, t_pathset *new_pathset)
{
	t_room		*current;
	size_t		i;
	int			link;

	if (vec_new(&new_pathset->paths, 1, sizeof(t_path *)) == -1)
		return (-1);
	current = vec_get(&info->room_table, info->start);
	i = 0;
	while (i < current->links.len)
	{
		link = *(int *)vec_get(&current->links, i++);
		if (info->adj_matrix[current->index][link] == FLOW)
		{
			if (add_path(info, new_pathset, link) == -1)
				return (free_pathset(new_pathset), -1);
		}
	}
	ft_printf("Lines required: %d\n", new_pathset->total_time); //temp
	calculate_total_time(new_pathset, info->ant_count);
	return (1);
}
