/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:46:03 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/05 18:46:07 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	augmenting_paths(t_info *info)
{
	int	state;

	state = bfs(info);
	if (state == ERROR)
		free_and_exit(info, 1);
	if (state == PATH_NOT_FOUND)
		return (0);
	if (state == PATH_FOUND)
		return (1);
}

int	pathfinder(t_info *info)
{
	if (initialize_bfs_and_pathsets(info) == -1)
		return (-1);
	while (augmenting_paths(info))
	{
		add_flow(info);
		save_pathset(info);
	}
	return (1);
}
