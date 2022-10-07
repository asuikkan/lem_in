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
	t_vec	*path;

	i = pathset->paths.len;
	while (--i >= limit)
	{
		path = vec_get(&pathset->paths, i);
		vec_free(path);
		vec_remove(&pathset->paths, i);
	}
}

void	calculate_total_time(t_pathset *pathset, size_t ant_count)
{
	int		sum;
	size_t	longest;
	size_t	remaining_ants;
	t_vec	*path;
	size_t	i;

	sum = 0;
	i = 0;
	while (i < pathset->paths.len)
	{
		path = vec_get(&pathset->paths, i);
		if (ant_count < (i + 1))
			break ;
		if (ant_count - (i + 1) < path->len * (i + 1) - (sum + path->len))
			break ;
		longest = path->len;
		sum += path->len;
		i++;
	}
	remaining_ants = ant_count - (longest * i - sum) - i;
	longest += remaining_ants / i + ((remaining_ants % i) > 0);
	pathset->total_time = longest;
	if (i < pathset->paths.len)
		remove_extra_paths(pathset, i);
}
