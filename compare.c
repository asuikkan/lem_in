/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:26:19 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/09 15:26:20 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*static int	copy_pathset(t_pathset *dst, t_pathset *src)
{
	free_pathset(dst);
	if (vec_from(&dst->paths,
		src->paths.memory,
		src->paths.len,
		src->paths.elem_size) == -1)
		return (-1);
	dst->total_time = src->total_time;
	return (1);
}*/

void	compare_pathsets(t_pathset *new_pathset)
{
	static t_pathset	best;

	if (!best.paths.memory || best.total_time > new_pathset->total_time)
	{
		free_pathset(&best);
		best = *new_pathset;
	}
	else
	{
		free_pathset(new_pathset);
		*new_pathset = best;
	}
}