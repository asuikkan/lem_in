/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:52:30 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/17 14:52:33 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	llist_new(t_llist *new, void *content, size_t size)
{
	if (size == 0)
		return (-1);
	new = (t_llist *)malloc(sizeof(t_llist));
	if (!new)
		return (-1);
	new->content = (void *)malloc(size);
	if (!new->content)
		return (-1);
	ft_memcpy(new->content, content, size);
	new->next = NULL;
	return (1);
}

int	llist_push_back(const t_llist *dst, void *content, size_t size)
{
	t_llist *current;

	if (!dst)
		return (-1);
	current = dst;
	while (current->next)
		current = current->next;
	if (llist_new(current->next, content, size) == -1)
		return (-1);
	return (1);
}

void	llist_pop(t_llist *dst)
{
	t_llist *temp;

	if (!dst)
		return ;
	temp = dst->next;
	free(dst->content);
	dst->content = NULL;
	free(dst);
	dst = temp;
}
