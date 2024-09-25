/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:32:43 by grannou           #+#    #+#             */
/*   Updated: 2022/01/16 14:08:43 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# define K "🔮🧡🍁🐞🍄🍀🌸🐹🌳🦊🐼🌿🧡🦊🧡🌿🐼🦊🌳🐹🌸🍀🍄🐞🍁🧡🔮\n"
# define Y "⛩ 🌸🦊    Launch ./so_long map_filename.ber     🦊🌸⛩\n"
# define A "⛩ 🌸🦊                                          🦊🌸⛩\n"
# define MARG "⛩ 🌸🦊             Missing Map file             🦊🌸⛩\n"
# define TMARG "⛩ 🌸🦊           Too Many Arguments             🦊🌸⛩\n"
# define WEXT "⛩ 🌸🦊           Wrong Map Extension            🦊🌸⛩\n"
# define OPENERR "⛩ 🌸🦊           Can't Open Map File            🦊🌸⛩\n"
# define OPENDIRERR "⛩ 🌸🦊      Map is  Directory not a File        🦊🌸⛩\n"
# define CLOSEERR "⛩ 🌸🦊           Can't Close Map File            🦊🌸⛩\n"
# define EMPTYMAP "⛩ 🌸🦊               Map is empty               🦊🌸⛩\n"
# define NRECTMAP "⛩ 🌸🦊          Map is not a rectangle          🦊🌸⛩\n"
# define WCHARMAP "⛩ 🌸🦊   Map is not only 0, 1, P, C, E chars    🦊🌸⛩\n"
# define NCLOSEDMAP "⛩ 🌸🦊        Map is not closed by 1 chars      🦊🌸⛩\n"
# define ZEROPMAP "⛩ 🌸🦊             Map has no player            🦊🌸⛩\n"
# define MULTIPMAP "⛩ 🌸🦊        Map has more than one player       🦊🌸⛩\n"
# define ZEROCMAP "⛩ 🌸🦊          Map has no collectible          🦊🌸⛩\n"
# define ZEROEMAP "⛩ 🌸🦊              Map has no exit             🦊🌸⛩\n"
# define GNLFAIL "⛩ 🌸🦊           Gnl Malloc fail error          🦊🌸⛩\n"
# define DATAFAIL "⛩ 🌸🦊          Data Malloc fail error          🦊🌸⛩\n"
# define ARRAYFAIL "⛩ 🌸🦊          Array Malloc fail error         🦊🌸⛩\n"
# define GAMEFAIL "⛩ 🌸🦊           Game Malloc fail error         🦊🌸⛩\n"
# define SCREENFAIL "⛩ 🌸🦊           Sceen Malloc fail error        🦊🌸⛩\n"
# define IMGFAIL "⛩ 🌸🦊           Image Malloc fail error        🦊🌸⛩\n"
# define TEXFAIL "⛩ 🌸🦊          Texture Malloc fail error        🦊🌸⛩\n"
# define IMGTEXFAIL "⛩ 🌸🦊       Texture Image Malloc fail error     🦊🌸⛩\n"
# define MLXINITFAIL "⛩ 🌸🦊     Mlx init fail (nice try env -i)      🦊🌸⛩\n"
# define MLXWINFAIL "⛩ 🌸🦊          Mlx new window failed           🦊🌸⛩\n"
# define MLXIMGFAIL "⛩ 🌸🦊           Mlx new image failed           🦊🌸⛩\n"
# define MLXADDRFAIL "⛩ 🌸🦊         Mlx data address failed          🦊🌸⛩\n"
# define GAME "⛩ 🌸🦊                Game Infos                🦊🌸⛩\n"
# define MAP "⛩ 🌸🦊                  Map                     🦊🌸⛩\n"
# define SCREEN "Max res = 2560 * 1440\n"
# define SCREENY "Map y = 22 tiles * 64 pixels = 1408"
# define SCREENX "Map x = 40 tiles * 64 pixels = 2560"
# define MAPTOOWIDE "⛩ 🌸🦊      Map's width is too big (40 max)     🦊🌸⛩\n"
# define MAPTOOHIGH "⛩ 🌸🦊      Map's height is too big (22 max)    🦊🌸⛩\n"

# define PLAYER "textures/Kyubie42.xpm"
# define WALL "textures/Tree42.xpm"
# define GROUND "textures/Leaves42.xpm"
# define COLL "textures/Sakura42.xpm"
# define EXIT "textures/Tori42.xpm"

# define BLACK_PIX 0x000000

# define TILE 64

typedef struct s_map		t_map;

struct	s_map
{
	char		*mapline;
	int			line_size;
	t_map		*next;
};

typedef struct s_game		t_game;

struct	s_game
{
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	int			coll;
	int			steps;
};

typedef struct s_img		t_img;

struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
};

typedef struct s_screen		t_screen;

struct s_screen
{
	int			screen_x;
	int			screen_y;
	t_img		*image;
};

typedef struct s_tex		t_tex;

struct s_tex
{
	int			width;
	int			height;
	t_img		*image;
};

typedef struct s_data		t_data;

struct	s_data
{
	char		**array;
	t_game		*game;
	t_screen	*screen;
	int			res_x;
	int			res_y;
	t_tex		*tex_p;
	t_tex		*tex_w;
	t_tex		*tex_g;
	t_tex		*tex_c;
	t_tex		*tex_e;
	void		*mlx;
	void		*mlx_win;
};

enum	e_MOVE
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum	e_TEXTURE
{
	GROUNDTEX,
	WALLTEX,
	COLLECTIBLETEX,
	EXITTEX
};

// basic_parsing.c
void		parse(t_data **data, int argc, char **argv);

// fill_map.c
void		fill_map(int fd, t_map **map);

// check_map.c
void		check_map_size(t_map **map);
void		check_rectangle_map(t_map **map);
void		check_map_chars(t_map **map);
void		check_closed_map(t_map **map);
void		check_items(t_map **map);

// create.c
char		**create_array(t_data *data, t_map *map);
t_game		*create_game(t_data *data, char **array);
t_data		*create_data(t_map *map);
void		create_image(t_data *data);
t_screen	*create_screen(t_data *data);

//create2.c
t_img		*create_tex_img(t_data *data, char *path, int *width, int *height);
t_tex		*create_texture(t_data *data, char *path);

// game.c
void		game(t_data *data);

// move.c
int			move(t_data *data, int move);

// draw.c
void		draw(t_data *data);

// free.c
void		clear_map_free_line_exit(t_map **map, char *line);
void		clear_map_exit(t_map **map, char *msg);
void		clear_data_map_exit(t_data *data, t_map **map);
void		clear_data_array_map_exit(t_data *data, char **array, t_map **map);
void		free_array(char **array);

// free2.c
void		exit_error(char *msg);
void		clear_data(t_data *data);

// utils.c
void		ft_putchar(char c);
int			ft_strlen(char *str);
void		*ft_memset(void *area, int character, size_t len);
void		*ft_calloc(int count, int size);
char		*ft_strndup(char *str, int n);

// utils2.c
char		*ft_itoa(int n);

// ft_array_utils.c
int			find_player_x(char **array);
int			find_player_y(char **array);
int			count_array_collectible(char **array);

// map_utils.c
int			ft_lst_size(t_map *map);
t_map		*ft_lst_create(char *line);
void		ft_lst_clear(t_map **map);
t_map		*ft_lstlast(t_map *map);
t_map		*ft_lst_addback(t_map **map, t_map *elem);

// map_utils2.c
void		replace_array_char(t_data *data, char new);
int			check_map_extension(char *str, char *ext);
int			not_only_wall(char *str);

// check_items_utils.c
int			is_map_char(char c);
int			count_item(char *str, char c);
void		count_player(t_map **map);
void		count_collectible(t_map **map);
void		count_exit(t_map **map);

// mlx_utils.c
void		start_mlx(t_data *data);
void		mlx_window(t_data *data);
void		mlx_image(t_data *data);
void		mlx_address(t_data *data);

// print.c
void		print_game_infos(t_game *game);
void		print_map(t_data *data);
void		print_all(t_data *data);
void		ft_putnbr(int number);

#endif
