/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:36:34 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 08:37:49 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_game_infos(t_game *game)
{
	printf(K A GAME A K);
	printf("\tHeight       = %d", game->height);
	printf("\tWidth      = %d\n", game->width);
	printf("\tWin_width    = %d", game->width * TILE);
	printf("\tWin_height = %d\n", game->height * TILE);
	printf("\tPlayer_x     = %d", game->player_x);
	printf("\tPlayer_y   = %d\n", game->player_y);
	printf("\tCollectibles = %d\n", game->coll);
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	x = data->game->width;
	y = data->game->height;
	printf(K A MAP A K);
	y = 0;
	while (data->array[y])
	{
		x = 0;
		while (data->array[y][x])
		{
			printf("%c ", data->array[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	print_all(t_data *data)
{
	if (!data)
		return ;
	print_game_infos(data->game);
	print_map(data);
}

void	ft_putnbr(int number)
{
	long long int	nbr;

	nbr = (long long int)number;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
