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

	ret = 0;
	while (*data != '\n')
	{
		if (!ft_isdigit(*data))
			return (-1);
		ret = ret * 10 + (*data - '0');
		data++;
	}
	return (ret);
}
