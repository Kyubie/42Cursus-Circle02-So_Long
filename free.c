/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:41:16 by grannou           #+#    #+#             */
/*   Updated: 2022/01/16 14:07:09 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map_free_line_exit(t_map **map, char *line)
{
	ft_lst_clear(map);
	free(line);
	exit_error(GNLFAIL);
}

void	clear_map_exit(t_map **map, char *msg)
{
	ft_lst_clear(map);
	exit_error(msg);
}

void	clear_data_map_exit(t_data *data, t_map **map)
{
	clear_data(data);
	clear_map_exit(map, ARRAYFAIL);
}

void	clear_data_array_map_exit(t_data *data, char **array, t_map **map)
{
	ft_lst_clear(map);
	free_array(array);
	clear_data(data);
	exit_error(ARRAYFAIL);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
