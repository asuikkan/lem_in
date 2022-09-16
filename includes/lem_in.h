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

enum e_pathset_check
{
	ERROR,
	PATH_NOT_FOUND,
	PATH_FOUND
};

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
	int				index;
	int				distance;
	t_vec			edges;
	struct s_room	*parent;
	struct s_room	*next;
}					t_room;

typedef struct s_bfs
{
	t_llist	*queue;
	int		*visited;
	int		*current;
}			t_bfs;

typedef struct s_edge
{
	int	from;
	int	to;
	int	flow: 1;
}		t_edge;

typedef struct s_path
{
	t_llist	*room;
	int		length;
}			t_path;

typedef struct s_paths
{
	t_vec	paths;
	int		total_time;
}			t_paths;

typedef struct s_pathsets
{
	t_paths	best;
	t_paths	current;
}			t_pathsets;

typedef struct s_info
{
	int				ant_count;
	int				room_count;
	t_read_flags	flags;
	t_vec			room_table;
	t_vec			hash_table;
	t_vec			edge_list;
	t_vec			adj_list;
	int				start;
	int				end;
	t_bfs			bfs;
	t_pathsets		pathsets;
}					t_info;

char			*lem_in_strndup(char *buf, int start, int n);
char			*lem_in_strnjoin(char *line, char *buf, int start, int n);
int				add_distances(t_info *info);
int				add_end(t_info *info, t_room *room);
int				add_to_edge_list(t_vec *edge_list, int room1, int room2);
int				add_adjacency(t_vec *edge_list, t_room *room1, t_room *room2);
int				add_start(t_info *info, t_room *room);
int				bfs(t_info *info);
int				get_link(t_edge *edge, int current);
int				hasher(t_info *info);
int				initialize_bfs_and_pathsets(t_info *info);
int				is_better_path(t_info *info, t_room *end);
int				lem_in_line_len(char *buf, int start);
int				parse_ant_count(t_info *info, char *data);
int				parse_link(t_info *info, char *line);
int				parse_room(t_info *info, char *line);
int				pathfinder(t_info *info);
int				push_room(t_info *info, t_room *room);
int				read_output(t_info *info);
int				**create_matrix(size_t size);
void			*llist_copy_front(void *dst, t_llist *src, size_t size);
void			llist_free(t_llist **src);
t_llist			*llist_new(void *content, size_t size);
int				llist_push(t_llist **dst, void *content, size_t size);
int				llist_push_back(t_llist **dst, void *content, size_t size);
void			llist_pop(t_llist **dst);
unsigned long	hash(char *str, size_t len);
void			error_handler(void);
void			free_and_exit(t_info *info, int error_flag);

#endif
