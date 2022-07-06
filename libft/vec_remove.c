/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:20:02 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/06 13:20:03 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_remove(t_vec *src, size_t index)
{
	if (!src)
		return (-1);
	if (!src->memory)
		return (-1);
	if (index > src->len - 1)
		return (-1);
	if (index + 1 < src->len)
	{
		ft_memmove(
			vec_get(src, index),
			vec_get(src, index + 1),
			(src->len - index + 1) * src->elem_size);
	}
	else
		ft_bzero(&src->memory[index * src->elem_size], src->elem_size);
	src->len--;
	return (1);
}
