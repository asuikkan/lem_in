/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:03:34 by asuikkan          #+#    #+#             */
/*   Updated: 2022/06/29 13:03:35 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUF_SIZE 1024

# include "libft.h"

typedef struct s_room
{
	char	*name;
	int		x;
	int		y;
}			t_room;

typedef struct s_info
{
	int		ant_count;
	t_room	*head;
}			t_info;

int	check_ant_count(char *data);

#endif
