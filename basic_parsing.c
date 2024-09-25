/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:57:46 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 10:12:00 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_open(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY | O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		exit_error (OPENDIRERR);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error(OPENERR);
	return (fd);
}

static int	check_close(int fd, t_map *map)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
		clear_map_exit(&map, CLOSEERR);
	return (EXIT_SUCCESS);
}

static void	check_argc_and_map_extension(int argc, char **argv)
{
	if (argc == 2)
		if (check_map_extension(argv[1], ".ber"))
			exit_error(WEXT);
	if (argc == 1)
		exit_error(MARG);
	if (argc > 2)
		exit_error(TMARG);
}

static void	check_valid_map(t_map **map)
{
	check_map_size(map);
	check_rectangle_map(map);
	check_map_chars(map);
	check_closed_map(map);
	check_items(map);
}

void	parse(t_data **data, int argc, char **argv)
{
	t_map	*map;
	int		fd;

	map = NULL;
	fd = 0;
	check_argc_and_map_extension(argc, argv);
	fd = check_open(argv[1]);
	fill_map(fd, &map);
	check_close(fd, map);
	check_valid_map(&map);
	*data = create_data(map);
	print_all(*data);
	if (!*data)
		return ;
	(*data)->array[(*data)->game->player_y][(*data)->game->player_x] = '0';
}
