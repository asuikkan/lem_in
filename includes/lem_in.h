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
# define COORD_LIMIT 2147483647

# include "libft.h"

typedef struct s_room
{
	char			*name;
	int				x;
	int				y;
}					t_room;

typedef struct s_info
{
	int		ant_count;
	t_vec	*room_table;
	char	*start;
	char	*end;
}			t_info;

char	*lem_in_strndup(char *buf, int start, int n);
char	*lem_in_strnjoin(char *line, char *buf, int start, int n);
int		add_start(t_info *info, t_room *room);
int		add_start(t_info *info, t_room *room);
int		lem_in_line_len(char *buf, int start);
int		parse_ant_count(char *data);
int		parse_room(t_info *info, char *line, int start_flag, int end_flag);
int		push_room(t_info *info, t_room *room);
void	error_handler(void);
void	free_info(t_info *info);
void	read_output(t_info *info);

#endif
