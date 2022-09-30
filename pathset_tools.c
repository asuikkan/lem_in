/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:33 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/28 15:21:35 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	remove_extra_paths(t_pathset *pathset, size_t limit)
{
	size_t	i;

	i = pathset->paths.len;
	while (--i >= limit)
		vec_remove(&pathset->paths, i);
}

void	calculate_total_time(t_pathset *pathset, int ant_count)
{
	int		time;
	int		sum;
	size_t	ants;
	t_vec	*path;
	size_t	i;

	print_paths(pathset); //temp
	ants = ant_count;
	sum = 0;
	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i);
		sum += path->len;
		if (ants <= path->len * (i + 1) - sum)
			break ;
		i++;
		ants -= path->len * i - sum;
		time = path->len;
	}
	ants -= i;
	time += ants / i + ((ants % i) > 0);
	pathset->total_time = time;
	if (i < pathset->paths.len)
		remove_extra_paths(pathset, i);
}
