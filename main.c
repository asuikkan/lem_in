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

static void	print_rooms(t_vec room_table)
{
	t_room	*temp;
	size_t	i;

	i = 0;
	while (i < room_table.len)
	{
		temp = vec_get(&room_table, i);
		ft_printf("%s\n", temp->name);
		while (temp->next)
		{
			temp = temp->next;
			ft_printf("%s\n", temp->name);
		}
		i++;
	}
}

static int	initialize_info(t_info *info)
{
	info->ant_count = -1;
	if (vec_new(&info->room_table, 2, sizeof(t_room)) == -1)
		return (-1);
	info->adj_matrix = NULL;
	info->start = NULL;
	info->end = NULL;
	info->start_flag = 0;
	info->end_flag = 0;
	info->room_flag = 0;
	return (1);
}

int	main(void)
{
	t_info	info;

	if (initialize_info(&info) == -1)
	{
		free_info(&info);
		error_handler();
	}
	if (read_output(&info) == -1)
	{
		free_info(&info);
		error_handler();
	}
	print_rooms(info.room_table);
	print_rooms(info.hash_table);
	free_info(&info);
	return (0);
}
