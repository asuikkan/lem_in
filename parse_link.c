/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:51:52 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/13 13:51:53 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	save_link(t_info *info, char *node1, char *node2) // jatka täältä!!!!
{
	t_room	*temp;
	int		index;

	index = hash(node1, info->room_table.len);
	temp = vec_get(&info->hash_table, index);
	if (ft_strcmp(node1, temp->name))
	{
		while (temp->next)
		{
			temp = temp->next;
			if (!ft_strcmp(node1, temp->name))
				return (1);
		}
	}
	return (1);
}

int	parse_link(t_info *info, char *line)
{
	char	*node1;
	char	*node2;
	int		node1_len;

	node1 = NULL;
	node2 = NULL;
	node1_len = ft_strclen(line, '-');
	node1 = ft_strsub(line, 0, node1_len);
	if (!node1)
		return (-1);
	ft_memmove(line, line + node1_len + 1, ft_strlen(line) - node1_len + 1);
	node2 = ft_strdup(line);
	if (!node2)
		return (-1);
	node2[ft_strlen(node2) - 1] = '\0';
	if (save_link(info, node1, node2) == -1)
		return (-1);
	ft_strdel(&node1);
	ft_strdel(&node2);
	return (1);
}
