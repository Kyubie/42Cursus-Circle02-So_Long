/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:15:45 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 11:28:22 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(t_data *data)
{
	if (!data)
		return ;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		clear_data(data);
		exit_error(MLXINITFAIL);
	}
}

void	mlx_window(t_data *data)
{
	int		width;
	int		height;
	char	*str;

	width = data->screen->screen_x;
	height = data->screen->screen_y;
	str = "Welcome in Kyubie World by Akatsuki grannou";
	data->mlx_win = mlx_new_window(data->mlx, width, height, str);
	if (!data->mlx_win)
	{
		clear_data(data);
		exit_error(MLXWINFAIL);
	}
}

void	mlx_image(t_data *data)
{
	data->screen->image->img = mlx_new_image(data->mlx, \
		data->screen->screen_x, data->screen->screen_y);
	if (!data->screen->image || !data->screen->image->img)
	{
		clear_data(data);
		exit_error(MLXIMGFAIL);
	}
}

void	mlx_address(t_data *data)
{
	data->screen->image->addr = \
		mlx_get_data_addr(data->screen->image->img, \
		&data->screen->image->bits_per_pixel, \
		&data->screen->image->line_length, \
		&data->screen->image->endian);
	if (!data->screen->image->addr)
	{
		clear_data(data);
		exit_error(MLXADDRFAIL);
	}
}
