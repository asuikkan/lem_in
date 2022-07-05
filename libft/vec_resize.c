/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:37:27 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/05 15:37:29 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_resize(t_vec *src, size_t target_len)
{
	t_vec	new;

	if (!src)
		return (-1);
	if (vec_new(&new, target_len, src->elem_size) == -1)
		return (-1);
	ft_memcpy(&new, src, src->len * src->elem_size);
	new.len = src->len;
	*src = new;
	return (1);
}
