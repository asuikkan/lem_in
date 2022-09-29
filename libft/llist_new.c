/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:52:11 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/29 16:52:12 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist	*llist_new(void *content, size_t size)
{
	t_llist	*new;

	if (!content || !size)
		return (NULL);
	if (size == 0)
		return (NULL);
	new = (t_llist *)malloc(sizeof(t_llist));
	if (!new)
		return (NULL);
	new->content = (void *)malloc(size);
	if (!new->content)
		return (NULL);
	ft_memcpy(new->content, content, size);
	new->size = size;
	new->next = NULL;
	return (new);
}
