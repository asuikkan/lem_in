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