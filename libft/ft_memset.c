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
<<<<<<< HEAD
	unsigned char	*ptr;
	unsigned char	uc;
	unsigned long	i;

	ptr = (unsigned char *)str;
=======
	unsigned char	uc;
	unsigned long	i;

>>>>>>> adj_rework
	uc = c;
	i = 0;
	while (i < n)
	{
<<<<<<< HEAD
		ptr[i] = uc;
=======
		((unsigned char *)str)[i] = uc;
>>>>>>> adj_rework
		i++;
	}
	return (str);
}
