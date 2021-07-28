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
NAME = pipex
LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
SRCS =  src/pipex.c\
		src/pipex_utils.c\
		src/ft_split_modify.c
BSRCS = bonus/main_bonus.c\
		bonus/pipex_bonus.c\
		bonus/pipex_utils_bonus.c\
		bonus/ft_split_modify_bonus.c\
		bonus/get_next_line_bonus.c\
		bonus/get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
HEADER = -I./header/

ifdef WITH_BONUS
	OBJ_FILE = $(BOBJS)
else
	OBJ_FILE = $(OBJS)
endif

all : $(NAME)
	
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)

$(NAME) : $(LIBFT_NAME) $(OBJ_FILE)
	$(CC) $(CFLAG) -L. -lft -o $@ $(OBJ_FILE)

bonus :
	rm -f $(NAME)
	make WITH_BONUS=1 all

$(LIBFT_NAME) :
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/$(LIBFT_NAME) .

clean :
	rm -f $(OBJS) $(BOBJS)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME) $(LIBFT_NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: all clean fclean re bonus
