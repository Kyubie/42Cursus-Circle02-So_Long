/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:25:55 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 04:30:09 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}

int	count_item(char *str, char c)
{
	char	*tmp;
	int		count;

	tmp = str;
	count = 0;
	while (*tmp)
	{
		if (*tmp == c)
			count++;
		tmp++;
	}
	return (count);
}

void	count_player(t_map **map)
{
	t_map	*tmp;
	int		pcount;

	tmp = *map;
	pcount = 0;
	while (tmp)
	{
		pcount += count_item(tmp->mapline, 'P');
		tmp = tmp->next;
	}
	if (pcount == 0)
		clear_map_exit(map, ZEROPMAP);
	if (pcount > 1)
		clear_map_exit(map, MULTIPMAP);
}

void	count_collectible(t_map **map)
{
	t_map	*tmp;
	int		ccount;

	tmp = *map;
	ccount = 0;
	while (tmp)
	{
		ccount += count_item(tmp->mapline, 'C');
		tmp = tmp->next;
	}
	if (ccount == 0)
		clear_map_exit(map, ZEROCMAP);
}

void	count_exit(t_map **map)
{
	t_map	*tmp;
	int		ecount;

	tmp = *map;
	ecount = 0;
	while (tmp)
	{
		ecount += count_item(tmp->mapline, 'E');
		tmp = tmp->next;
	}
	if (ecount == 0)
		clear_map_exit(map, ZEROEMAP);
}
