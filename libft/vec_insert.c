/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:45:10 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/05 17:45:12 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_insert(t_vec *dst, void *src, size_t index)
{
	if (!dst || !src)
		return (-1);
	if (!dst->memory)
		return (-1);
	if (dst->alloc_size < (dst->len + 1) * dst->elem_size)
	{
		if (vec_resize(dst, dst->len * 2) == -1)
			return (-1);
	}
	ft_memmove(
		vec_get(dst, index + 1),
		vec_get(dst, index),
		(dst->len - index) * dst->elem_size);
	ft_memcpy(&dst->memory[index * dst->elem_size], src, dst->elem_size);
	dst->len++;
	return (1);
}
