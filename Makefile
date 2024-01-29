# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doukim <doukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 13:27:04 by doukim            #+#    #+#              #
#    Updated: 2024/01/29 11:45:38 by doukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3D
CC		:= cc
INCLUDE	:= -I./includes -I./libs/libft -I./libs/get_next_line -I./libs/mlx
CFLAGS	:= -Wall -Wextra -Werror
FUNCS	:= \
	-L./libs/mlx -lmlx\
	-L./libs/libft -lft\
	-L./libs/get_next_line -lgnl

SRCDIR	:= ./srcs/
OBJDIR	:= ./objs/

SRCS	:= $(wildcard $(SRCDIR)*.c)
OBJS	:= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))
LIBS	:= \
	./libs/libft/libft.a\
	./libs/get_next_line/libgnl.a\
	./mlx/libmlx.a

bonus : all

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./functions/libft all
	$(MAKE) -C ./functions/get_next_line all
	$(MAKE) -C ./mlx all
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(FUNCS) -framework OpenGL \
		-framework Appkit

$(OBJDIR) :
	@mkdir objects

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	$(MAKE) -C ./functions/libft clean
	$(MAKE) -C ./functions/get_next_line clean
	$(MAKE) -C ./mlx clean
	rm -rf $(OBJDIR)

fclean : clean
	$(MAKE) -C ./functions/libft fclean
	$(MAKE) -C ./functions/get_next_line fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
