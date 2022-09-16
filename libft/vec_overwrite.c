/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_overwrite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:40:33 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/14 17:40:35 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_overwrite(t_vec *dst, void *src, size_t index)
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
	ft_memcpy(&dst->memory[index * dst->elem_size], src, dst->elem_size);
	dst->len++;
	return (1);
}
