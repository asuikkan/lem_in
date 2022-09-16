/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:00:21 by asuikkan          #+#    #+#             */
/*   Updated: 2022/08/30 13:00:23 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_ant_count(t_info *info, char *line)
{
	long	nb;
	int		i;

	nb = 0;
	i = -1;
	while (line[++i] != '\n')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		nb = nb * 10 + (line[i] - '0');
		if (nb > COORD_LIMIT)
			return (-1);
	}
	info->ant_count = nb;
	return (1);
}

