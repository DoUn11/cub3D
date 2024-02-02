# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doukim <doukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 13:27:04 by doukim            #+#    #+#              #
#    Updated: 2024/01/30 17:13:30 by doukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3D
CC		:= cc
INCLUDE	:= -I./incs -I./libs/libft -I./libs/get_next_line -I./libs/mlx
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
	./libs/mlx/libmlx.a

bonus : all

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libs/libft bonus
	$(MAKE) -C ./libs/get_next_line all
	$(MAKE) -C ./libs/mlx all
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(FUNCS) -framework OpenGL \
		-framework Appkit

$(OBJDIR) :
	@mkdir objs

$(OBJDIR)%.o : $(SRCDIR)%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJDIR)
	$(MAKE) -C ./libs/libft clean
	$(MAKE) -C ./libs/get_next_line clean
	$(MAKE) -C ./libs/mlx clean

fclean : clean
	$(MAKE) -C ./libs/libft fclean
	$(MAKE) -C ./libs/get_next_line fclean
	rm -rf ./libs/mlx/libmlx.a
	rm -rf $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
