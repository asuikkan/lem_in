/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:57:09 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/05 15:57:10 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_push(t_vec *dst, void *src)
{
	if (!dst || !src)
		return (-1);
	if (!dst->memory)
	{
		if (vec_new(dst, 1, dst->elem_size) == -1)
			return (-1);
	}
	if (dst->elem_size * dst->len >= dst->alloc_size)
	{
		if (vec_resize(dst, dst->len * 2) == -1)
			return (-1);
	}
	ft_memcpy(&dst->memory[dst->len * dst->elem_size], src, dst->elem_size);
	dst->len++;
	return (1);
}
