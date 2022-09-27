/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:48:59 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/27 15:49:00 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_map_info(t_vec *map_info)
{
	char	**line;
	size_t	i;

	i = 0;
	while (i < map_info->len)
	{
		line = vec_get(map_info, i++);
		ft_putendl(*line);
	}
}

void	print_solution(int ant_count, t_vec *map_info, t_pathset *pathset)
{
	(void) ant_count;
	(void) pathset;
	print_map_info(map_info);
}
