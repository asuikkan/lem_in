/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:52:47 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/03 13:53:50 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	uc;
	unsigned long	i;

	uc = c;
	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = uc;
		i++;
	}
	return (str);
}
