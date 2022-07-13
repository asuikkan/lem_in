/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:11:02 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/02 16:11:04 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_handler(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	free_info(t_info *info)
{
	/*size_t	i;
	size_t	j;
	t_room	*temp;

	i = 0;
	while (i < info->room_table->len)
	{
		temp = vec_get(info->room_table, i);
		j = 0;
		while (temp->links[j])
			ft_strdel(&temp->links[j++]);
		i++;
	}*/
	vec_free(info->room_table);
}
