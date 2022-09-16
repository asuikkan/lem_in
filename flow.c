/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:01:29 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/07 11:01:30 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	initialize_flow(t_adj_state **adj_matrix, t_room *room1, t_room *room2)
{
	if (room1 == room2)
		adj_matrix[room1->index][room2->index] = SELF_LINK;
	else
	{		
		adj_matrix[room1->index][room2->index] = NO_FLOW;
		adj_matrix[room2->index][room1->index] = NO_FLOW;
	}
}

/*void    add_flow(t_info *info)
{
}*/
