/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:31:47 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 19:31:49 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_texure(t_data *data, int texture, int x, int y)
{
	if (texture == GROUNDTEX)
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->tex_g->image->img, x * TILE, y * TILE);
	if (texture == WALLTEX)
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->tex_w->image->img, x * TILE, y * TILE);
	if (texture == COLLECTIBLETEX)
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->tex_c->image->img, x * TILE, y * TILE);
	if (texture == EXITTEX)
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->tex_e->image->img, x * TILE, y * TILE);
}

static int	draw_map_mlx(t_data *data)
{
	int	x;
	int	y;
	int	img_size;

	img_size = 64;
	y = 0;
	while (data->array[y])
	{
		x = 0;
		while (data->array[y][x])
		{
			if (data->array[y][x] == '0')
				draw_texure(data, GROUNDTEX, x, y);
			else if (data->array[y][x] == '1')
				draw_texure(data, WALLTEX, x, y);
			else if (data->array[y][x] == 'C')
				draw_texure(data, COLLECTIBLETEX, x, y);
			else if (data->array[y][x] == 'E')
				draw_texure(data, EXITTEX, x, y);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

static void	draw_player(t_data *data)
{
	int	xmap;
	int	ymap;

	xmap = data->game->player_x * TILE;
	ymap = data->game->player_y * TILE;
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->tex_p->image->img, xmap, ymap);
}

static void	draw_counter(t_data *data)
{
	char	*steps;
	char	*coll;

	steps = ft_itoa(data->game->steps);
	coll = ft_itoa(data->game->coll);
	mlx_string_put(data->mlx, data->mlx_win, 16, 20, BLACK_PIX, steps);
	mlx_string_put(data->mlx, data->mlx_win, 32, 20, BLACK_PIX, "steps");
	mlx_string_put(data->mlx, data->mlx_win, 80, 20, BLACK_PIX, coll);
	mlx_string_put(data->mlx, data->mlx_win, 96, 20, BLACK_PIX, "sakura left");
	free(steps);
	free(coll);
}

void	draw(t_data *data)
{
	draw_map_mlx(data);
	draw_player(data);
	draw_counter(data);
}
