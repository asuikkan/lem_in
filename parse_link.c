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

static void	add_to_matrix(t_info *info, t_room *room1, t_room *room2)
{
	if (room1 == room2)
		info->adj_matrix[room1->matrix_index][room1->matrix_index] = 2;
	else
	{
		info->adj_matrix[room1->matrix_index][room2->matrix_index] = 1;
		info->adj_matrix[room2->matrix_index][room1->matrix_index] = 1;
	}
}

static t_room	*validate_node(t_vec *table, char *room_name, int index)
{
	t_room	*temp;

	temp = vec_get(table, index);
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
	if (!add_to_edge_list(&info->edge_list, room1->matrix_index, room2->matrix_index))
		return (-1);
	if (!add_edge_rooms(
		&info->edge_list,
		vec_get(&info->room_table, room1->matrix_index),
		vec_get(&info->room_table, room2->matrix_index)))
			return (-1);
	add_to_matrix(info, room1, room2);
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
		return (-1);
	node2[ft_strlen(node2) - 1] = '\0';
	if (save_link(info, node1, node2) == -1)
		return (-1);
	ft_strdel(&node1);
	ft_strdel(&node2);
	return (1);
}
