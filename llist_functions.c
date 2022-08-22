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

int	llist_push_back(t_llist **dst, void *content, size_t size)
{
	t_llist	*current;

	if (!content || !size)
		return (-1);
	if (!*dst)
		*dst = llist_new(content, size);
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

int	llist_push(t_llist *dst, void *content, size_t size)
{
	t_llist	*temp;

	if (!content || !size)
		return (-1);
	if (!dst)
		dst = llist_new(content, size);
	else
	{
		temp = NULL;
		temp = llist_new(content, size);
		if (!temp)
			return (-1);
		temp->next = dst;
		dst = temp;
	}
	return (1);
}

void	llist_pop(t_llist **dst)
{
	t_llist	*temp;

	if (!*dst)
		return ;
	temp = (*dst)->next;
	free((*dst)->content);
	(*dst)->content = NULL;
	free(*dst);
	*dst = temp;
}

void	*llist_copy_front(void *dst, t_llist *src, size_t size)
{
	if (!src || !src->content)
		return (NULL);
	return (ft_memcpy(dst, src->content, size));
}

void	llist_free(t_llist **src)
{
	while (*src)
	{
		free((*src)->content);
		(*src)->content = NULL;
		free(*src);
		*src = (*src)->next;
	}
}
