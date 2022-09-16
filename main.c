/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:52:00 by asuikkan          #+#    #+#             */
/*   Updated: 2022/06/28 15:52:04 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_info	*initialize_info(void)
{
	t_info	*info;
	int		i;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	i = -1;
	while (++i < 128)
		info->table[i] = NULL;
	info->ant_count = -1;
	return (info);
}

int	main(void)
{
	t_info	*info;

	info = initialize_info();
	if (!info)
		error_handler();
	read_output(info);
	return (0);
}
