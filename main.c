/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:52:00 by asuikkan          #+#    #+#             */
/*   Updated: 2022/06/28 15:52:04 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

<<<<<<< HEAD
static void	print_adj_matrix(int **matrix, int size)
=======
/*static void	print_adj_matrix(t_adj_state **matrix, int size)
>>>>>>> adj_rework
{
	int	i;
	int	j;

	i = -1;
	ft_printf("\nMATRIX:\n");
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			ft_printf("%d", matrix[i][j]);
		}
		ft_printf("\n");
	}
	ft_printf("\n");
<<<<<<< HEAD
}

static void	print_rooms(t_vec room_table)
=======
}*/

/*static void	print_links(t_room *room)
{
	size_t	i;
	int		link;

	ft_printf("LINKS:\n");
	i = 0;
	while (i < room->links.len)
	{
		link = *(int *)vec_get(&room->links, i++);
		ft_printf("%d\n", link);
	}
}*/

/*static void	print_rooms(t_vec room_table)
>>>>>>> adj_rework
{
	t_room	*temp;
	size_t	i;

	i = 0;
	while (i < room_table.len)
	{
		temp = vec_get(&room_table, i);
		ft_printf("name  = %s\n", temp->name);
<<<<<<< HEAD
		ft_printf("index = %d\n", temp->matrix_index);
		ft_printf("dist  = %d\n\n", temp->distance);
=======
		ft_printf("index = %d\n", temp->index);
		print_links(temp);
		ft_printf("\n");
>>>>>>> adj_rework
		while (temp->next)
		{
			temp = temp->next;
			ft_printf("name  = %s\n", temp->name);
			ft_printf("index = %d\n", temp->matrix_index);
			ft_printf("dist  = %d\n\n", temp->distance);
		}
		i++;
	}
<<<<<<< HEAD
=======
}*/

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
>>>>>>> adj_rework
}

static int	initialize_info(t_info *info)
{
<<<<<<< HEAD
=======
	info->map_info.memory = NULL;
	info->map_info.elem_size = sizeof(char *);
>>>>>>> adj_rework
	info->ant_count = -1;
	info->room_count = -1;
	info->flags.end_flag = 0;
	info->flags.start_flag = 0;
	info->flags.room_flag = 0;
	info->room_table.memory = NULL;
	info->hash_table.memory = NULL;
<<<<<<< HEAD
	info->adj_matrix = NULL;
	info->start = NULL;
	info->end = NULL;
	info->bfs_distance.queue = NULL;
	info->bfs_distance.visited = NULL;
	info->bfs_distance.index = NULL;
	info->bfs_path.queue = NULL;
	info->bfs_path.visited = NULL;
	info->bfs_path.closed = NULL;
	info->bfs_path.index = NULL;
=======
	info->start = -1;
	info->end = -1;
	info->bfs.queue = NULL;
	info->bfs.visited = NULL;
	info->bfs.parent = NULL;
	info->adj_matrix = NULL;
	info->pathset.paths.memory = NULL;
>>>>>>> adj_rework
	return (1);
}

int	main(void)
{
	t_info	info;

	if (initialize_info(&info) == -1)
<<<<<<< HEAD
		free_and_exit(&info, 1);
	if (read_output(&info) == -1)
		free_and_exit(&info, 1);
	if (add_distances(&info) == -1)
		free_and_exit(&info, 1);
	//pathfinder(&info);
	print_rooms(info.room_table);
	print_adj_matrix(info.adj_matrix, info.room_count);
	free_and_exit(&info, 0);
	return (0);
=======
		return (free_and_exit(&info, 1));
	if (read_output(&info) == -1)
		return (free_and_exit(&info, 1));
	if (pathfinder(&info) == -1)
		return (free_and_exit(&info, 1));
	//print_rooms(info.room_table);
	//print_adj_matrix(info.adj_matrix, info.room_count);
	print_solution(info.ant_count, &info.map_info, &info.pathset);
	print_paths(info.pathset);
	return (free_and_exit(&info, 0));
>>>>>>> adj_rework
}
