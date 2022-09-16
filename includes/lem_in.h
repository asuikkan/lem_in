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

typedef struct s_llist
{
	void			*content;
	size_t			size;
	struct s_llist	*next;
}					t_llist;

typedef struct s_read_flags
{
	int	start_flag;
	int	end_flag;
	int	room_flag;
}		t_read_flags;

typedef struct s_room
{
	char			*name;
	int				x;
	int				y;
	int				matrix_index;
	int				distance;
	struct s_room	*next;
}					t_room;

typedef struct s_bfs_distance
{
	t_llist	*queue;
	int		*visited;
	int		*index;
}			t_bfs_distance;

typedef struct s_info
{
	int				ant_count;
	int				room_count;
	t_read_flags	flags;
	t_vec			room_table;
	t_vec			hash_table;
	int				**adj_matrix;
	t_room			*start;
	t_room			*end;
	t_bfs_distance	bfs_distance;
}					t_info;

char			*lem_in_strndup(char *buf, int start, int n);
char			*lem_in_strnjoin(char *line, char *buf, int start, int n);
int				add_start(t_info *info, t_room *room);
int				add_end(t_info *info, t_room *room);
int				pathfinder(t_info *info);
int				hasher(t_info *info);
int				add_distances(t_info *info);
int				lem_in_line_len(char *buf, int start);
void			*llist_copy_front(void *dst, t_llist *src, size_t size);
void			llist_free(t_llist **src);
t_llist			*llist_new(void *content, size_t size);
int				llist_push(t_llist *dst, void *content, size_t size);
int				llist_push_back(t_llist **dst, void *content, size_t size);
void			llist_pop(t_llist **dst);
int				parse_ant_count(t_info *info, char *data);
int				parse_link(t_info *info, char *line);
int				parse_room(t_info *info, char *line);
int				push_room(t_info *info, t_room *room);
int				read_output(t_info *info);
int				**create_matrix(size_t size);
unsigned long	hash(char *str, size_t len);
void			error_handler(void);
void			free_and_exit(t_info *info, int error_flag);

#endif
