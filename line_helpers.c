/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:13:33 by asuikkan          #+#    #+#             */
/*   Updated: 2022/07/02 15:13:34 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	lem_in_line_len(char *buf, int start)
{
	int	len;
	int	i;

	len = 0;
	i = start;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (len + 1);
		len++;
		i++;
	}
	return (len);
}

char	*lem_in_strndup(char *buf, int start, int n)
{
	int		i;
	int		j;
	char	*ret;

	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	i = -1;
	j = start;
	while (++i < n)
		ret[i] = buf[start++];
	return (ret);
}

char	*lem_in_strnjoin(char *line, char *buf, int start, int n)
{
	char	*ret;
	int		i;

	ret = ft_strnew(ft_strlen(line) + n);
	if (!ret)
		return (NULL);
	i = -1;
	while (line[++i])
		ret[i] = line[i];
	while (n--)
		ret[i++] = buf[start++];
	return (ret);
}
