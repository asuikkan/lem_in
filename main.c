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

#include "libft.h"

static void	read_output(void)
{
	int		ret;
	char	buf[1024 + 1];

	while (1)
	{
		ret = read(0, buf, 1024);
		if (ret == 0)
			return ;
		if (ret < 0)
			return ;
		buf[ret] = '\0';
	}
}

int	main(void)
{
	read_output();
	return (0);
}
