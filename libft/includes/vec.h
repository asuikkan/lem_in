/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:32:01 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/04 14:32:02 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include "libft.h"

typedef struct s_vec
{
	unsigned char	*memory;
	size_t			elem_size;
	size_t			alloc_size;
	size_t			len;
}					t_vec;

int		vec_copy(t_vec *dst, t_vec *src);
int		vec_from(t_vec *dst, void *src, size_t len, size_t elem_size);
int		vec_new(t_vec *src, size_t init_len, size_t elem_size);
int		vec_pop(void *dst, t_vec *src);
int		vec_push(t_vec *dst, void *src);
int		vec_resize(t_vec *src, size_t target_len);
void	vec_free(t_vec *src);
void	*vec_get(t_vec *src, size_t index);

#endif
