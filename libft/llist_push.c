/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:51:29 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/29 16:51:30 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	llist_push(t_llist **dst, void *content, size_t size)
{
	t_llist	*current;

	if (!content || !size)
		return (-1);
	if (!*dst)
	{
		*dst = llist_new(content, size);
		if (!*dst)
			return (-1);
	}
	else
	{
		current = *dst;
		while (current->next)
			current = current->next;
		current->next = llist_new(content, size);
		if (!current->next)
			return (-1);
	}
	return (1);
}
