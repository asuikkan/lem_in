/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:31:59 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/05 16:32:00 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	*vec_get(t_vec *src, size_t index)
{
	if (!src)
		return (NULL);
	if (!src->memory)
		return (NULL);
<<<<<<< HEAD
	if (src->len - 1 < index)
		return (NULL);
=======
>>>>>>> adj_rework
	return (&src->memory[index * src->elem_size]);
}
