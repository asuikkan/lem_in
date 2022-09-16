/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:11:24 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/26 16:11:27 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	initialize_edges(t_info *info) // jatka edgejen lisaamisella
{
	if (vec_new(&info->edge_list, 2, sizeof()))
	return (1);
}
