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

# define BUF_SIZE 2
# define COORD_LIMIT 2147483647

# include "libft.h"

typedef struct s_room
{
	char			*name;
	int				x;
	int				y;
	int				matrix_index;
	int				distance;
	struct s_room	*next;
}					t_room;

typedef struct s_info
{
	int		ant_count;
	int		room_count;
	t_vec	room_table;
	t_vec	hash_table;
	int		**adj_matrix;
	t_room	*start;
	t_room	*end;
	int		start_flag;
	int		end_flag;
	int		room_flag;
}			t_info;

typedef struct s_lists
{
	int		*closed;
	int		*open;
}			t_lists;

char			*lem_in_strndup(char *buf, int start, int n);
char			*lem_in_strnjoin(char *line, char *buf, int start, int n);
int				add_start(t_info *info, t_room *room);
int				add_end(t_info *info, t_room *room);
int				pathfinder(t_info *info);
int				hasher(t_info *info);
int				lem_in_line_len(char *buf, int start);
int				parse_ant_count(t_info *info, char *data);
int				parse_link(t_info *info, char *line);
int				parse_room(t_info *info, char *line);
int				push_room(t_info *info, t_room *room);
int				read_output(t_info *info);
int				**create_matrix(size_t size);
unsigned long	hash(char *str, size_t len);
void			error_handler(void);
void			find_distances(t_info *info, int i, int dist);
void			free_info(t_info *info);

#endif
