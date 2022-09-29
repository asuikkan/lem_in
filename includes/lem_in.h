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

enum e_pathset_check
{
	ERROR,
	PATH_NOT_FOUND,
	PATH_FOUND
};

typedef enum e_entries
{
	NONE,
	POSITIVE,
	NEGATIVE,
	BOTH
}	t_entries;

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
	t_vec			links;
	int				flow_from;
	int				flow_to;
	struct s_room	*next;
}					t_room;

typedef enum e_adj_state
{
	NO_LINK,
	NO_FLOW,
	FLOW,
	NEGATIVE_FLOW
}	t_adj_state;

typedef struct s_pathset
{
	t_vec	paths;
	int		total_time;
}			t_pathset;

typedef struct s_bfs
{
	t_llist		*queue;
	t_entries	*visited;
	int			**parent;
	int			current;
}				t_bfs;

typedef struct s_info
{
	t_vec			map_info;
	int				ant_count;
	int				room_count;
	t_read_flags	flags;
	t_vec			room_table;
	t_vec			hash_table;
	t_adj_state		**adj_matrix;
	int				start;
	int				end;
	t_bfs			bfs;
	t_pathset		pathset;
}					t_info;

int				add_adjacency(t_room *room1, t_room *room2);
int				add_end(t_info *info, t_room *room);
int				add_start(t_info *info, t_room *room);
int				bfs(t_info *info);
int				free_and_exit(t_info *info, int error_flag);
int				hasher(t_info *info);
int				init_room_info(size_t ***room_info, t_pathset *pathset);
int				initialize_bfs(t_info *info);
int				initialize_flow(t_adj_state **adj_matrix,
					t_room *room1,
					t_room *room2);
int				parse_ant_count(t_info *info, char *data);
int				parse_link(t_info *info, char *line);
int				parse_room(t_info *info, char *line);
int				pathfinder(t_info *info);
int				print_ant(size_t ant, t_vec *path, size_t room_i, int printed);
int				print_final(int ant_count, t_vec *map_info, t_pathset *pathset);
int				push_room(t_info *info, t_room *room);
int				read_output(t_info *info);
int				reset_bfs(t_info *info);
int				save_pathset(t_info *info, t_pathset *new_pathset);
t_adj_state		**create_matrix(size_t size);
unsigned long	hash(char *str, size_t len);
void			calculate_total_time(t_pathset *pathset, int ant_count);
void			compare_pathsets(t_pathset *new_pathset);
void			free_bfs(t_bfs *bfs, int size);
void			free_pathset(t_pathset *pathset);
void			free_room_info(size_t **room_info, size_t size);
void			print_map_info(t_vec *map_info);
void			update_flow(t_info *info);

#endif
