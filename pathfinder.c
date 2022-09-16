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
	else
		return (1);
}

int	pathfinder(t_info *info)
{
	t_pathset	new_pathset;

	if (initialize_bfs(info) == -1)
		return (-1);
	while (augmenting_paths(info))
	{
		update_flow(info);
		if (save_pathset(info, &new_pathset) == -1)
			return (-1);
		break ;
	}
	return (1);
}
