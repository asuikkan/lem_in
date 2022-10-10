/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:35:02 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/10 11:35:04 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	validate_digit(char c, long *number, int sign, int i)
{
	int	digit;

	if (!ft_isdigit(c))
		return (0);
	if (sign > 0 && (*number == 0 && i > 0))
		return (0);
	digit = c - '0';
	if (*number == 0 && (digit == 0 && i > 0))
		return (0);
	*number = *number * 10 + digit;
	if (sign > 0 && *number > COORD_LIMIT)
		return (0);
	if (sign < 0 && *number > COORD_LIMIT + (long)1)
		return (0);
	return (1);
}
