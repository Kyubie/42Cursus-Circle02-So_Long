/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:28:17 by grannou           #+#    #+#             */
/*   Updated: 2022/01/16 14:09:45 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_array(t_data *data, t_map *map)
{
	t_map	*tmp;
	char	**array;
	int		height;
	int		i;

	tmp = map;
	height = ft_lst_size(tmp);
	i = 0;
	array = (char **)malloc(sizeof(char *) * (height + 1));
	if (!array)
		clear_data_map_exit(data, &map);
	while (i < height)
	{
		array[i] = ft_strndup(tmp->mapline, tmp->line_size);
		if (!array[i])
			clear_data_array_map_exit(data, array, &map);
		i++;
		tmp = tmp->next;
	}
	array[i] = NULL;
	ft_lst_clear(&map);
	return (array);
}

t_game	*create_game(t_data *data, char **array)
{
	t_game	*game;
	int		height;
	int		width;

	height = 0;
	width = 0;
	while (array[height])
		height++;
	while (array[0][width])
		width++;
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		clear_data(data);
		exit_error(GAMEFAIL);
	}
	game->height = height;
	game->width = width;
	game->player_x = find_player_x(array);
	game->player_y = find_player_y(array);
	game->coll = count_array_collectible(array);
	game->steps = 0;
	return (game);
}

t_data	*create_data(t_map *map)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		clear_map_exit(&map, DATAFAIL);
	data->array = create_array(data, map);
	data->game = create_game(data, data->array);
	return (data);
}

t_screen	*create_screen(t_data *data)
{
	t_screen	*screen;

	screen = (t_screen *)ft_calloc(1, sizeof(t_screen));
	if (!screen || !data)
	{
		clear_data(data);
		exit_error(SCREENFAIL);
	}
	screen->screen_y = data->game->height * TILE;
	screen->screen_x = data->game->width * TILE;
	data->screen = screen;
	create_image(data);
	return (screen);
}

void	create_image(t_data *data)
{
	data->screen->image = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!data->screen->image)
	{
		clear_data(data);
		exit_error(IMGFAIL);
	}
	mlx_window(data);
	mlx_image(data);
	mlx_address(data);
}
