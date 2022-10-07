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

void	print_paths(t_pathset *pathset)
{
	size_t	i;
	size_t	j;
	t_vec	*path;
	t_room	*room;

	ft_printf("\n");
	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i++);
		j = 0;
		while (j < path->len)
		{
			room = *(t_room **)vec_get(path, j);
			ft_printf("|%s| ", room->name);
			if (j != path->len - 1)
				ft_printf("-> ");
			j++;
		}
		ft_printf("\n------------\n");
	}
	ft_printf("Lines required: %d\n", pathset->total_time);
}

static int	initialize_info(t_info *info)
{
	info->map_info.memory = NULL;
	info->map_info.elem_size = sizeof(char *);
	info->map_info.len = 0;
	info->ant_count = 0;
	info->room_count = -1;
	info->flags.end_flag = 0;
	info->flags.start_flag = 0;
	info->flags.room_flag = 0;
	info->room_table.memory = NULL;
	info->hash_table.memory = NULL;
	info->start = -1;
	info->end = -1;
	info->bfs.queue = NULL;
	info->bfs.trace = NULL;
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
	print_final(info.ant_count, &info.map_info, &info.pathset);
	ft_printf(">>>> %d <<<<\n", info.pathset.total_time);
	//ft_printf("ANT COUNT: %d\n\n", info.ant_count); // temp
	//print_paths(&info.pathset); //temp
	return (free_and_exit(&info, 0));
}
