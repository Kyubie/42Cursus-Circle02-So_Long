/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:33:06 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 11:21:36 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*create_tex_img(t_data *data, char *path, int *width, int *height)
{
	t_img	*image;

	image = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!image)
	{
		clear_data(data);
		exit_error(IMGTEXFAIL);
	}
	image->img = mlx_xpm_file_to_image(data->mlx, path, width, height);
	if (!image->img)
	{
		clear_data(data);
		exit_error(MLXIMGFAIL);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
		&image->line_length, &image->endian);
	if (!image->addr)
	{
		clear_data(data);
		exit_error(MLXADDRFAIL);
	}
	return (image);
}

t_tex	*create_texture(t_data *data, char *path)
{
	t_tex	*tex;

	tex = (t_tex *)ft_calloc(1, sizeof(t_tex));
	if (!tex)
	{
		clear_data(data);
		exit_error(TEXFAIL);
	}
	tex->image = create_tex_img(data, path, &tex->width, &tex->height);
	return (tex);
}
