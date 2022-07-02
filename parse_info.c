/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:59:55 by asuikkan          #+#    #+#             */
/*   Updated: 2022/06/30 12:59:57 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_ant_count(char *data)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (data[++i] != '\n')
	{
		if (!ft_isdigit(data[i]))
			return (-1);
		ret = ret * 10 + (data[i] - '0');
	}
	return (ret);
}
