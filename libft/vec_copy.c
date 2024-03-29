/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:47:00 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/04 15:47:01 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_copy(t_vec *dst, t_vec *src)
{
	if (!dst || !src)
		return (-1);
	if (!src->memory)
		return (-1);
	if (dst->alloc_size < src->elem_size * src->len)
	{
		ft_memcpy(dst->memory, src->memory, dst->alloc_size);
		dst->len = dst->alloc_size / dst->elem_size;
	}
	else
	{
		ft_memcpy(dst->memory, src->memory, src->elem_size * src->len);
		dst->len = src->elem_size * src->len / dst->elem_size;
	}
	return (1);
}
