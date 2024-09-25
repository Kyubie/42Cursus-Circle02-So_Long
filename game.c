/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:42:31 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 10:13:11 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_no_event(t_data **data)
{
	(void)data;
	return (EXIT_SUCCESS);
}

static int	handle_keypress(int keysym, t_data **data)
{
	if (keysym == XK_Escape)
	{
		clear_data(*data);
		exit(EXIT_SUCCESS);
	}
	if (keysym == XK_w || keysym == XK_Up)
		move(*data, UP);
	if (keysym == XK_s || keysym == XK_Down)
		move(*data, DOWN);
	if (keysym == XK_a || keysym == XK_Left)
		move(*data, LEFT);
	if (keysym == XK_d || keysym == XK_Right)
		move(*data, RIGHT);
	return (EXIT_SUCCESS);
}

static int	handle_mouseclick(t_data **data)
{
	clear_data(*data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	game(t_data *data)
{
	start_mlx(data);
	data->screen = create_screen(data);
	data->tex_p = create_texture(data, PLAYER);
	data->tex_w = create_texture(data, WALL);
	data->tex_g = create_texture(data, GROUND);
	data->tex_c = create_texture(data, COLL);
	data->tex_e = create_texture(data, EXIT);
	draw(data);
	mlx_loop_hook(data->mlx, &handle_no_event, &data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, \
		&handle_mouseclick, &data);
	mlx_loop(data->mlx);
}
