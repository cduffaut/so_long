# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csil <csil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 14:02:38 by csil              #+#    #+#              #
#    Updated: 2023/11/01 10:06:14 by cduffaut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= \
	so_long.c \
	check_map.c \
	free_all_stock.c \
	map_reading.c \
	size_map_playable.c \
	check_walls_map.c \
	is_map_doable.c \
	push_img_to_screen.c \
	play_game.c

LIBFT	=		./libft/libft.a
LX_LIB = 		./mlx/libmlx.a

MLIBFT	=		$(MAKE) -C libft
MLX_LIB =		$(MAKE) -C mlx

OBJS	= $(SRCS:.c=.o)

GCC	= gcc -Wall -Wextra -Werror

# flags and includes #

INCLUDES = -I/opt/X11/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# compilation part #

all: lib $(NAME)

lib:
	$(MLIBFT) all
	$(MLX_LIB) all

.c.o:
	$(GCC) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(GCC) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(LX_LIB)


# clean part #

clean:
	rm -f $(OBJS)
	$(MLIBFT) clean
	$(MLX_LIB) clean

fclean:	clean
	rm -f $(NAME)
	$(MLIBFT) fclean
	$(MLX_LIB) clean

re:	fclean all

.PHONY : re fclean clean all
