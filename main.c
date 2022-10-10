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
}

static void	initialize_info(t_info *info)
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
}

static void	initialize_flags(t_print_flags *print_flags)
{
	print_flags->path_flag = 0;
	print_flags->line_flag = 0;
}

static int	check_options(int argc, char **argv, t_print_flags *print_flags)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len < 2)
			return (ft_putendl("Invalid option"), -1);
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && argv[i][j] == '-')
				continue ;
			else if (argv[i][j] == 'p')
				print_flags->path_flag = 1;
			else if (argv[i][j] == 'l')
				print_flags->line_flag = 1;
			else
				return (ft_putendl("Invalid option"), -1);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info			info;
	t_print_flags	print_flags;

	initialize_flags(&print_flags);
	if (argc > 1)
	{
		if (check_options(argc, argv, &print_flags) == -1)
			return (1);
	}
	initialize_info(&info);
	if (read_output(&info) == -1)
		return (cleanup(&info, 1), 1);
	if (pathfinder(&info) == -1)
		return (cleanup(&info, 1), 1);
	if (print_final(info.ant_count, &info.map_info, &info.pathset) == -1)
		return (cleanup(&info, 1), 1);
	if (print_flags.path_flag)
		print_paths(&info.pathset);
	if (print_flags.line_flag)
		ft_printf("Lines required: %d\n", info.pathset.total_time);
	cleanup(&info, 0);
	return (0);
}
