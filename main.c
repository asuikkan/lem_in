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

static t_info	*create_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->head = NULL;
	info->ant_count = 0;
	return (info);
}

static void	save_info(char *data)
{
	static int		ant_flag;
	static int		room_flag;
	static t_room	*table[128];
	t_info			*info;

	if (ant_flag == 0)
	{
		info = create_info();
		info->ant_count = check_ant_count(data);
		ant_flag = 1;
	}
}

static int	line_len(char *buf)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (buf[++i] && buf[i] != '\n')
		len++;
	return (len);
}

static int	save_line(char *buf, char **line)
{
	int		len;
	int		i;

	len = line_len(buf);
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (!*line)
		return (0);
	*line[len] = '\0';
	i = -1;
	while (++i < len)
		*line[i] = buf[i];
	return (len);
}

static void	read_output(void)
{
	static char	buf[BUF_SIZE + 1];
	static char	*line;
	int			i;
	int			ret;

	while (1)
	{
		ret = read(0, buf, BUF_SIZE);
		if (ret == 0)
			return ;
		if (ret < 0)
			return ;
		buf[ret] = '\0';
		i = 0;
		while (buf[i])
		{
			i = save_line(buf, &line);
			save_info(line);
			ft_strdel(&line);
		}
	}
}

int	main(void)
{
	read_output();
	return (0);
}
