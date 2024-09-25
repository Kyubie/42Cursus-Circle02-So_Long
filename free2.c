/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 03:21:25 by grannou           #+#    #+#             */
/*   Updated: 2022/01/16 14:09:13 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	exit(EXIT_FAILURE);
}

static void	clear_image(void *mlx, t_img *image)
{
	if (image && image->img != NULL)
		mlx_destroy_image(mlx, image->img);
	free(image);
}

static void	clear_texture(void *mlx, t_tex *texture)
{
	if (texture && texture->image && texture->image->img != NULL)
	{
		mlx_destroy_image(mlx, texture->image->img);
		free(texture->image);
	}
	free(texture);
}

static void	clear_window(void *mlx, void *win, t_screen *screen)
{
	if (win != NULL)
		mlx_destroy_window(mlx, win);
	if (screen)
		clear_image(mlx, screen->image);
	free(screen);
}

void	clear_data(t_data *data)
{
	if (!data)
		return ;
	free_array(data->array);
	free(data->game);
	clear_texture(data->mlx, data->tex_p);
	clear_texture(data->mlx, data->tex_w);
	clear_texture(data->mlx, data->tex_g);
	clear_texture(data->mlx, data->tex_c);
	clear_texture(data->mlx, data->tex_e);
	clear_window(data->mlx, data->mlx_win, data->screen);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	write(1, "\n", 1);
}
