/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:40:33 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 04:32:16 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_x(char **array)
{
	int	x;
	int	y;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	find_player_y(char **array)
{
	int	x;
	int	y;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	count_array_collectible(char **array)
{
	int	x;
	int	y;
	int	ccount;

	y = 0;
	ccount = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == 'C')
				ccount++;
			x++;
		}
		y++;
	}
	return (ccount);
}
