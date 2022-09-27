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

static void	print_paths(t_pathset pathset)
{
	size_t	i;
	size_t	j;
	t_vec	*path;
	t_room	*room;

	i = 0;
	while (i < pathset.paths.len)
	{
		path = vec_get(&pathset.paths, i++);
		j = 0;
		while (j < path->len)
		{
			room = *(t_room **)vec_get(path, j);
			ft_printf("%s", room->name);
			if (j != path->len - 1)
				ft_printf("->");
			j++;
		}
		ft_printf("\n");
	}
	ft_printf("Lines required: %d\n", pathset.total_time);
}

static void	calculate_total_time(t_pathset *pathset, int ant_count)
{
	int		time;
	int		sum;
	size_t	ants;
	t_vec	*path;
	size_t	i;

	ants = ant_count;
	sum = 0;
	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i++);
		sum += path->len;
		if (ants <= path->len * i - sum)
			break ;
		ants -= path->len * i - sum;
		ants--;
		time = path->len;
	}
	time += ants / i + ((ants % i) > 0);
	pathset->total_time = time;
}

static void	initialize_path(t_vec *path)
{
	path->memory = NULL;
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
	int		next_index;

	i = 0;
	while (i < current->links.len)
	{
		next_index = *(int *)vec_get(&current->links, i++);
		if (info->adj_matrix[current->index][next_index] == FLOW)
			return (vec_get(&info->room_table, next_index));
	}
	return (NULL);
}

static int	add_path(t_info *info, t_pathset *pathset, int start)
{
	t_vec	new_path;
	t_room	*current;
	t_room	*next;

	initialize_path(&new_path);
	current = vec_get(&info->room_table, start);
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
	t_room		*current;
	size_t		i;
	int			link;

	if (vec_new(&new_pathset->paths, 1, sizeof(t_vec)) == -1)
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
	calculate_total_time(new_pathset, info->ant_count);
	print_paths(*new_pathset);
	ft_printf("Lines required: %d\n", new_pathset->total_time); //temp
	return (1);
}
