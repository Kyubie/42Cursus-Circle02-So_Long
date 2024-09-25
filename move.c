/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:22:26 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 10:49:20 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	get_next_tile(t_data *data, int move)
{
	int		x;
	int		y;
	char	next_tile;

	x = data->game->player_x;
	y = data->game->player_y;
	if (move == UP)
		next_tile = data->array[y - 1][x];
	if (move == DOWN)
		next_tile = data->array[y + 1][x];
	if (move == LEFT)
		next_tile = data->array[y][x - 1];
	if (move == RIGHT)
		next_tile = data->array[y][x + 1];
	return (next_tile);
}

static void	handle_collectibles(t_data *data, char next_tile)
{
	if (next_tile == 'C' && data->game->coll > 0)
	{
		data->game->coll--;
		replace_array_char(data, '0');
	}
}

static void	handle_exit(t_data *data, char next_tile)
{
	if (next_tile == 'E')
	{
		if (data->game->coll > 0)
			printf("-> %d remaining collectibles\n", data->game->coll);
		else
		{
			clear_data(data);
			exit(0);
		}
	}
}

int	move(t_data *data, int move)
{
	char	next_tile;

	next_tile = get_next_tile(data, move);
	if (next_tile != '1')
	{
		if (move == UP)
			data->game->player_y -= 1;
		if (move == DOWN)
			data->game->player_y += 1;
		if (move == LEFT)
			data->game->player_x -= 1;
		if (move == RIGHT)
			data->game->player_x += 1;
		data->game->steps++;
		write(1, "\r", 1);
		ft_putnbr(data->game->steps);
		write(1, " steps", 6);
	}
	handle_collectibles(data, next_tile);
	handle_exit(data, next_tile);
	draw(data);
	return (EXIT_SUCCESS);
}
