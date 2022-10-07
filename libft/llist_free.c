/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:44:33 by asuikkan          #+#    #+#             */
/*   Updated: 2022/09/29 16:44:35 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	llist_free(t_llist **src)
{
	t_llist	*temp;

	while (*src)
	{
		temp = (*src)->next;
		free((*src)->content);
		(*src)->content = NULL;
		free(*src);
		*src = temp;
	}
}
