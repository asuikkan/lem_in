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

static void	print_adj_matrix(int **matrix, int size)
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
}

static void	print_rooms(t_vec room_table)
{
	t_room	*temp;
	size_t	i;

	i = 0;
	while (i < room_table.len)
	{
		temp = vec_get(&room_table, i);
		ft_printf("name  = %s\n", temp->name);
		ft_printf("index = %d\n", temp->matrix_index);
		ft_printf("dist  = %d\n\n", temp->distance);
		while (temp->next)
		{
			temp = temp->next;
			ft_printf("name  = %s\n", temp->name);
			ft_printf("index = %d\n", temp->matrix_index);
			ft_printf("dist  = %d\n\n", temp->distance);
		}
		i++;
	}
}

static int	initialize_info(t_info *info)
{
	info->ant_count = -1;
	info->room_count = -1;
	info->flags.end_flag = 0;
	info->flags.start_flag = 0;
	info->flags.room_flag = 0;
	info->room_table.memory = NULL;
	info->hash_table.memory = NULL;
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
	return (1);
}

int	main(void)
{
	t_info	info;

	if (initialize_info(&info) == -1)
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
}
