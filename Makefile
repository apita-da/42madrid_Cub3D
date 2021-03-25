# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 11:29:48 by apita-da          #+#    #+#              #
#    Updated: 2021/03/14 12:04:15 by apita-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c bmp.c				\
					parse/colors.c				\
					parse/error.c				\
					parse/get_res.c				\
					parse/get_sprites.c			\
					parse/get_textures.c		\
					parse/init.c				\
					parse/line.c				\
					parse/parse_map.c			\
					parse/readmap.c				\
					movimiento/keys.c			\
					movimiento/move.c			\
					movimiento/movement.c		\
					raycasting/init_game.c		\
					raycasting/print_sprite.c	\
					raycasting/print_sprite1.c	\
					raycasting/print_texture.c	\
					raycasting/raycasting.c		\
					raycasting/window.c			\
					utils/utils1.c				\
					utils/utils2.c				\
					utils/utils3.c				\
					utils/utils4.c		

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I. -g
LIBS			=  -Lmlx -lmlx -framework OpenGL -framework AppKit -o
LIBS			= -lmlx -lX11 -lXext -lbsd -lm
MLX				= libmlx.dylib

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} libmlx.dylib

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .


clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
