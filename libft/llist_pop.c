/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:50:54 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/29 16:50:55 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	llist_pop(void *dst, t_llist **src)
{
	t_llist	*temp;

	if (!*src)
		return (-1);
	if (!dst)
		return (-1);
	ft_memcpy(dst, (*src)->content, (*src)->size);
	temp = (*src)->next;
	free((*src)->content);
	(*src)->content = NULL;
	free(*src);
	*src = temp;
	return (1);
}
