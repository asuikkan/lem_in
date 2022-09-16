/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:22:07 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/27 16:22:10 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	**create_matrix(size_t size)
{
	int		**matrix;
	size_t	i;

	matrix = ft_memalloc(sizeof(int *) * (size + 1));
	if (!matrix)
		return (NULL);
	matrix[size] = NULL;
	i = 0;
	while (i < size)
	{
		matrix[i] = ft_memalloc(sizeof(int) * (size + 1));
		if (!matrix[i])
			return (NULL);
		matrix[i][size] = -1;
		i++;
	}
	return (matrix);
}
