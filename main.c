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

/*static void	print_adj_matrix(t_adj_state **matrix, int size)
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
{
	t_room	*temp;
	size_t	i;

	i = 0;
	while (i < room_table.len)
	{
		temp = vec_get(&room_table, i);
		ft_printf("name  = %s\n", temp->name);
		ft_printf("index = %d\n", temp->index);
		print_links(temp);
		ft_printf("\n");
		while (temp->next)
		{
			temp = temp->next;
			ft_printf("name  = %s\n", temp->name);
			ft_printf("index = %d\n", temp->matrix_index);
			ft_printf("dist  = %d\n\n", temp->distance);
		}
		i++;
	}
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
}

static int	initialize_info(t_info *info)
{
	info->map_info.memory = NULL;
	info->map_info.elem_size = sizeof(char *);
	info->ant_count = -1;
	info->room_count = -1;
	info->flags.end_flag = 0;
	info->flags.start_flag = 0;
	info->flags.room_flag = 0;
	info->room_table.memory = NULL;
	info->hash_table.memory = NULL;
	info->start = -1;
	info->end = -1;
	info->bfs.queue = NULL;
	info->bfs.visited = NULL;
	info->bfs.parent = NULL;
	info->adj_matrix = NULL;
	info->pathset.paths.memory = NULL;
	return (1);
}

int	main(void)
{
	t_info	info;

	if (initialize_info(&info) == -1)
		return (free_and_exit(&info, 1));
	if (read_output(&info) == -1)
		return (free_and_exit(&info, 1));
	if (pathfinder(&info) == -1)
		return (free_and_exit(&info, 1));
	//print_rooms(info.room_table);
	//print_adj_matrix(info.adj_matrix, info.room_count);
	print_final(info.ant_count, &info.map_info, &info.pathset);
	print_paths(info.pathset);
	return (free_and_exit(&info, 0));
}
