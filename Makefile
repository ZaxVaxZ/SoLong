# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 09:28:37 by ehammoud          #+#    #+#              #
#    Updated: 2024/06/11 16:42:53 by ehammoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		  = cc
CFLAGS	  = -Wall -Wextra -Werror
ORG		  = ./solong_mandatory
BON		  = ./solong_bonus
SRCS	  = $(ORG)/main.c $(ORG)/map_utils.c $(ORG)/hook_handles.c			\
			$(ORG)/render_utils.c $(ORG)/extra_utils.c $(ORG)/animation.c	\
		    $(ORG)/get_next_line_utils.c $(ORG)/utils.c $(ORG)/freeing.c	\
			$(ORG)/get_next_line.c $(ORG)/main_utils2.c $(ORG)/main_utils1.c
OBJS	  = $(SRCS:.c=.o)
SRCSBONUS = $(BON)/main.c $(BON)/map_utils.c $(BON)/hook_handles.c			\
			$(BON)/render_utils.c $(BON)/extra_utils.c $(BON)/animation.c	\
		    $(BON)/get_next_line_utils.c $(BON)/utils.c $(BON)/freeing.c	\
			$(BON)/get_next_line.c $(BON)/main_utils2.c $(BON)/main_utils1.c
OBJSBONUS = $(SRCSBONUS:.c=.o)
MLX		  = mlx
OGLFLAGS  = -L$(MLX) -lmlx -framework OpenGL -framework Appkit
NAME	  = so_long
NAMEBONUS = so_long_bonus

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(OGLFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAMEBONUS)

$(NAMEBONUS): $(OBJSBONUS)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(OGLFLAGS) $(OBJSBONUS) -o $(NAMEBONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJSBONUS)

fclean: clean
	make clean -C $(MLX)
	rm -rf $(NAME)
	rm -rf $(NAMEBONUS)

re: fclean all

.PHONY: all clean fclean re
