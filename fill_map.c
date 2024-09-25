/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:59:08 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 19:28:34 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	recursive_gnl(int fd, char **line, int index)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == -1)
		return (-1);
	if (ret == 1 && buf != '\n')
	{
		if (recursive_gnl(fd, line, index + 1) == -1)
			return (-1);
		(*line)[index] = buf;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * (index + 1));
		if (!(*line))
			return (-1);
		(*line)[index] = '\0';
	}
	return (ret);
}

static int	get_next_line(int fd, char **line)
{
	int	ret;

	ret = recursive_gnl(fd, line, 0);
	if (!line || ret == -1)
		return (-1);
	return (ret);
}

void	fill_map(int fd, t_map **map)
{
	char	*line;
	t_map	*elem;
	int		ret;

	line = NULL;
	elem = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		elem = ft_lst_create(line);
		if (!elem)
			clear_map_free_line_exit(map, line);
		*map = ft_lst_addback(map, elem);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0)
	{
		if (line[0] != '\0')
			*map = ft_lst_addback(map, elem);
		free(line);
	}
	else
		clear_map_free_line_exit(map, line);
}
