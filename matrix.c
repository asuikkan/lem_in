/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:55:36 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/07 11:55:50 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adj_state	**create_matrix(size_t size)
{
	t_adj_state	**matrix;
	size_t		i;

	matrix = ft_memalloc(sizeof(t_adj_state *) * size);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < size)
	{
		matrix[i] = ft_memalloc(sizeof(t_adj_state) * size);
		if (!matrix[i])
			return (NULL);
		i++;
	}
	return (matrix);
}
