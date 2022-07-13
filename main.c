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

static int	initialize_info(t_info *info)
{
	info->ant_count = -1;
	info->room_table = NULL;
	info->start = NULL;
	info->end = NULL;
	info->start_flag = 0;
	info->end_flag = 0;
	return (1);
}

int	main(void)
{
	t_info	info;

	initialize_info(&info);
	read_output(&info);
	free_info(&info);
	return (0);
}
