/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:16:36 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/05 16:16:38 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_pop(void *dst, t_vec *src)
{
	if (!dst || !src)
		return (-1);
	if (!src->memory)
		return (-1);
	ft_memcpy(
		dst,
		&src->memory[(src->len - 1) * src->elem_size],
		src->elem_size);
	ft_bzero(&src->memory[src->len * src->elem_size], src->elem_size);
	src->len--;
	return (1);
}
