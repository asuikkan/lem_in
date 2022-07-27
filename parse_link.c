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

int	parse_link(t_info *info, char *line)
{
	int		i;
	int		len;
	char	*node1;
	char	*node2;

	node1 = NULL;
	node2 = NULL;
	len = ft_strlen(line);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '-')
		{
			node1 = ft_strsub(line, 0, i);
			ft_printf("node1 = %s\n", node1);
			node2 = ft_strsub(line, i + 1, len - i - 2);
			ft_printf("node2 = %s\n", node2);
			break ;
		}
	}
	if (!node1 || !node2)
		return (-1);
	(void)info;
	return (1);
}
