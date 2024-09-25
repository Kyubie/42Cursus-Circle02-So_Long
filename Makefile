# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grannou <grannou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 19:07:05 by grannou           #+#    #+#              #
#    Updated: 2022/01/16 13:49:30 by grannou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -fsanitize=undefined -fsanitize=leak

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NORME = norminette *.c norminette *.h
RM = rm -rf

MLX = mlx_linux

NAME = so_long
SRCS = main.c \
	basic_parsing.c \
	fill_map.c \
	check_map.c \
	create.c \
	create2.c \
	game.c \
	move.c \
	draw.c \
	free.c \
	free2.c \
	utils.c \
	utils2.c \
	array_utils.c \
	map_utils.c \
	map_utils2.c \
	check_items_utils.c \
	mlx_utils.c \
	print.c

NAME_BONUS = so_long_bonus
SRCS_BONUS = main.c \
	basic_parsing.c \
	fill_map.c \
	check_map.c \
	create.c \
	create2.c \
	game.c \
	move.c \
	draw_bonus.c \
	free.c \
	free2.c \
	utils.c \
	utils2.c \
	array_utils.c \
	map_utils.c \
	map_utils2.c \
	check_items_utils.c \
	mlx_utils.c \
	print.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -I $(dir so_long.h) -I/usr/include -Imlx_linux -c $< -o $@

.PHONY: all
all: $(MLX)/libmlx_Linux.a $(NAME)

.PHONY: $(MLX)
$(MLX)/libmlx_Linux.a:
	@make -C $(MLX)

$(NAME): $(OBJS)
	@echo "\n"
	@echo "$(shell tput setaf 198)███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 208)███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 214)╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝$(shell tput sgr0)"
	@echo "\n"
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

.PHONY: norme
norme:
	@echo "\n"
	@echo "$(shell tput setaf 201)███╗   ██╗ ██████╗ ██████╗ ███╗   ███╗██╗███╗   ██╗███████╗████████╗████████╗███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 200)████╗  ██║██╔═══██╗██╔══██╗████╗ ████║██║████╗  ██║██╔════╝╚══██╔══╝╚══██╔══╝██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 199)██╔██╗ ██║██║   ██║██████╔╝██╔████╔██║██║██╔██╗ ██║█████╗     ██║      ██║   █████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 198)██║╚██╗██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██╔══╝     ██║      ██║   ██╔══$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██║ ╚████║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██║ ╚████║███████╗   ██║      ██║   ███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝      ╚═╝   ╚══════╝$(shell tput sgr0)"
	@echo "\n"
	@$(NORME)

.PHONY: clean
clean:
	@echo "\n"
	@echo "$(shell tput setaf 51) ██████╗██╗     ███████╗ █████╗ ███╗   ██╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 50)██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 49)██║     ██║     █████╗  ███████║██╔██╗ ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 48)██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 47)╚██████╗███████╗███████╗██║  ██║██║ ╚████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 46) ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝$(shell tput sgr0)"
	@echo "\n"
	$(RM) $(OBJS) $(OBJS_BONUS)

.PHONY: display_fclean
display_fclean:
	@echo "\n"
	@echo "$(shell tput setaf 45)███████╗ ██████╗██╗     ███████╗ █████╗ ███╗   ██╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 44)██╔════╝██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 43)█████╗  ██║     ██║     █████╗  ███████║██╔██╗ ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 42)██╔══╝  ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 41)██║     ╚██████╗███████╗███████╗██║  ██║██║ ╚████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 40)╚═╝      ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝$(shell tput sgr0)"
	@echo "\n"

.PHONY: fclean
fclean: display_fclean clean
	$(RM) $(NAME) $(NAME_BONUS)

.PHONY: display_make_re
display_make_re:
	@echo "\n"
	@echo "$(shell tput setaf 201)███╗   ███╗ █████╗ ██╗  ██╗███████╗    ██████╗ ███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 200)████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ██╔══██╗██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 199)██╔████╔██║███████║█████╔╝ █████╗      ██████╔╝█████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 198)██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██╔══██╗██╔══╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║  ██║███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝$(shell tput sgr0)"
	@echo "\n"

.PHONY: re
re: display_make_re fclean all

.PHONY: bonus
bonus: $(OBJS_BONUS)
	@echo "\n"
	@echo "$(shell tput setaf 226)██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 220)██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 214)██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 208)██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝$(shell tput sgr0)"
	@echo "\n"
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME_BONUS)


.PHONY: fox
fox:
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)        $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)        $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0) $(shell tput setaf 94)∂∂∂∂$(shell tput setaf 202)ΩΩΩ$(tput sgr0)     $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)      $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0) $(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(tput sgr0)     $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)     $(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈$(shell tput setaf 94)∂$(shell tput sgr0)   $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩ  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 202)ΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@$(shell tput setaf 40)@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@$(shell tput setaf 40)@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput setaf 40)@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈$(sh    ell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππππππππ$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 208)ππππππππππ$(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ∂∂$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 94)∂$(shell tput sgr0)ΩΩ$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩ:::$(shell tput sgr0)ΩΩΩΩΩΩΩ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)ΩΩΩΩΩΩ:::$(shell tput sgr0)ΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput sgr0)ΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)"
	@echo "$(shell tput setaf 94)∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩ$(shell tput sgr0)     :::::$(shell tput sgr0)     $(shell tput sgr0)ΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)             $(shell tput sgr0)ΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)           $(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 0)≈≈∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)         ΩΩΩΩΩΩΩΩΩΩ:ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂∂$(shell tput setaf 0)≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂$(shell tput sgr0)ΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 94)∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ::$(shell tput sgr0)$(shell tput setaf 196)ΩΩΩ$(shell tput sgr0)::ΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput sgr0):::$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 196)ΩΩΩ$(shell tput sgr0)ΩΩΩΩ:::$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput sgr0)ΩΩΩ$(shell tput setaf 196)Ω$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
