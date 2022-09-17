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

static t_room	*validate_node(t_vec *table, char *room_name, int index)
{
	t_room	*temp;

	temp = *(t_room **)vec_get(table, index);
	if (ft_strcmp(temp->name, room_name))
	{
		while (temp->next)
		{
			temp = temp->next;
			if (!ft_strcmp(temp->name, room_name))
				return (temp);
		}
		return (NULL);
	}
	return (temp);
}

static int	save_link(t_info *info, char *node1, char *node2)
{
	t_room	*room1;
	t_room	*room2;
	int		index;

	index = hash(node1, info->room_table.len);
	room1 = validate_node(&info->hash_table, node1, index);
	if (!room1)
		return (-1);
	index = hash(node2, info->room_table.len);
	room2 = validate_node(&info->hash_table, node2, index);
	if (!room2)
		return (-1);
	if (!add_adjacency(room1, room2))
		return (-1);
	if (initialize_flow(info->adj_matrix, room1, room2) == -1)
		return (-1);
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
	ft_memmove(line, line + node1_len + 1, ft_strlen(line) - node1_len);
	node2 = ft_strdup(line);
	if (!node2)
		return (ft_strdel(&node1), -1);
	if (save_link(info, node1, node2) == -1)
		return (ft_strdel(&node1), ft_strdel(&node2), -1);
	ft_strdel(&node1);
	ft_strdel(&node2);
	return (1);
}
