/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:26:26 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 04:45:48 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_size(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	if (ft_lst_size(tmp) == 0)
		clear_map_exit(map, EMPTYMAP);
	if (ft_lst_size(tmp) > 22)
	{
		printf(RED SCREEN GREEN SCREENY RESET "\n");
		clear_map_exit(map, MAPTOOHIGH);
	}
	if ((tmp)->line_size > 40)
	{
		printf(RED SCREEN GREEN SCREENX RESET "\n");
		clear_map_exit(map, MAPTOOWIDE);
	}
}

void	check_rectangle_map(t_map **map)
{
	int		len;
	t_map	*tmp;

	tmp = *map;
	len = (tmp)->line_size;
	while (tmp)
	{
		if (tmp->line_size != len)
			clear_map_exit(map, NRECTMAP);
		tmp = tmp->next;
	}
}

void	check_map_chars(t_map **map)
{
	t_map	*tmp;
	char	*str;
	int		i;

	tmp = *map;
	while (tmp)
	{
		str = tmp->mapline;
		i = 0;
		while (str[i])
		{
			if (!is_map_char(str[i]))
				clear_map_exit(map, WCHARMAP);
			i++;
		}
		tmp = tmp->next;
	}
}

void	check_closed_map(t_map **map)
{
	t_map	*tmp;
	char	*str;

	tmp = *map;
	if (not_only_wall(tmp->mapline))
		clear_map_exit(map, NCLOSEDMAP);
	else
		tmp = tmp->next;
	while (tmp && tmp->next)
	{
		str = tmp->mapline;
		if ((str[0] != '1') || (str[tmp->line_size - 1] != '1'))
			clear_map_exit(map, NCLOSEDMAP);
		tmp = tmp->next;
	}
	if (not_only_wall(tmp->mapline))
		clear_map_exit(map, NCLOSEDMAP);
}

void	check_items(t_map **map)
{
	count_player(map);
	count_collectible(map);
	count_exit(map);
}
