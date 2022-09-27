/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free .c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:11:02 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/02 16:11:04 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_pathset(t_pathset *pathset)
{
	size_t	i;
	t_vec	*path;

	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i++);
		vec_free(path);
	}
	vec_free(&pathset->paths);
}

static void	free_matrix(t_adj_state	**matrix, size_t size)
{
	size_t	i;

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
	ft_strdel(&room->name);
	vec_free(&room->links);
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

static void	free_map_info(t_vec *map_info)
{
	size_t	i;
	char	**line;

	i = 0;
	while (i < map_info->len)
	{
		line = vec_get(map_info, i++);
		free(*line);
	}
	vec_free(map_info);
}

int	free_and_exit(t_info *info, int error_flag)
{
	if (error_flag)
		write(1, "ERROR\n", 6);
	free_map_info(&info->map_info);
	free_table(&info->room_table);
	vec_free(&info->hash_table);
	free_matrix(info->adj_matrix, info->room_count);
	if (info->pathset.paths.memory)
		free_pathset(&info->pathset);
	free_bfs(&info->bfs, info->room_count);
	llist_free(&info->bfs.queue);
	return (0);
}
