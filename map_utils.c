/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:00:42 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 11:15:33 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lst_size(t_map *map)
{
	int	i;

	i = 0;
	while (map)
	{
		i++;
		map = map->next;
	}
	return (i);
}

t_map	*ft_lst_create(char *line)
{
	t_map	*elem;

	elem = (t_map *)malloc(sizeof(t_map));
	if (!elem)
		return (NULL);
	elem->mapline = line;
	elem->line_size = ft_strlen(line);
	elem->next = NULL;
	return (elem);
}

void	ft_lst_clear(t_map **map)
{
	t_map	*ptr;
	t_map	*next;

	ptr = *map;
	while (ptr)
	{
		next = ptr->next;
		free(ptr->mapline);
		free(ptr);
		ptr = next;
	}
}

t_map	*ft_lstlast(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

t_map	*ft_lst_addback(t_map **map, t_map *elem)
{
	if (*map)
		ft_lstlast(*map)->next = elem;
	else
		*map = elem;
	return (*map);
}
