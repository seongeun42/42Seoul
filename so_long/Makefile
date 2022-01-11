# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 22:46:42 by seongele          #+#    #+#              #
#    Updated: 2021/06/28 22:46:53 by seongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS =-Lmlx_opengl -lmlx -framework OpenGL -framework Appkit
NAME = so_long
TARGET = NAME
MINI_DIR = ./mlx_opengl
MINI_NAME = libmlx.a
LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
SRCS =  src/so_long.c\
		src/so_long_utils.c\
		src/map_parse1.c\
		src/map_parse2.c\
		src/draw_map.c\
		src/get_next_line.c\
		src/get_next_line_utils.c
BSRCS = bonus/so_long_bonus.c\
		bonus/so_long_utils_bonus.c\
		bonus/map_parse1_bonus.c\
		bonus/map_parse2_bonus.c\
		bonus/draw_map_bonus.c\
		bonus/get_next_line.c\
		bonus/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
HEADER = -I./mlx/ -I./header/

FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

ifdef WITH_BONUS
	OBJ_FILE = $(BOBJS)
else
	OBJ_FILE = $(OBJS)
endif

all : $(NAME)
	
%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)

$(NAME) : $(LIBFT_NAME) $(MINI_NAME) $(OBJ_FILE)
	@$(CC) $(CFLAG) -L. -lft -o $@ $(OBJ_FILE) $(LIBS)
	@printf "${FG_LBLUE}so_long make successs!\n${NO_COLOR}"

bonus :
	@printf "${FG_LBLUE}so_long bonus make....\n${NO_COLOR}"
	@make WITH_BONUS=1 all

$(MINI_NAME) :
	@make -C $(MINI_DIR)
	@mv $(MINI_DIR)/$(MINI_NAME) .

$(LIBFT_NAME) :
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/$(LIBFT_NAME) .

clean :
	@rm -f $(OBJS) $(BOBJS)
	@make clean -C $(MINI_DIR)
	@make clean -C $(LIBFT_DIR)
	@printf "${FG_GREEN}so_long clean!\n${NO_COLOR}"

fclean : clean
	@rm -f $(NAME) $(MINI_NAME) $(LIBFT_NAME)
	@printf "${FG_GREEN}so_long fclean!\n${NO_COLOR}"

re : fclean all

.PHONY: all clean fclean re bonus
