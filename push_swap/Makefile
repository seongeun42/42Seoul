# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 22:47:13 by seongele          #+#    #+#              #
#    Updated: 2021/06/28 22:47:22 by seongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAMEB = checker
SRCS1 = src/push_swap.c\
		src/operation.c\
		src/sort_a.c\
		src/sort_b.c
SRCS2 = src/sort_utils.c\
		src/parse_utils1.c\
		src/parse_utils2.c\
		src/ft_split.c
SRCSB = bonus/checker.c\
		bonus/get_next_line.c\
		bonus/get_next_line_utils.c\
		bonus/operation.c\
		$(SRCS2)
OBJS = $(SRCS1:.c=.o) $(SRCS2:.c=.o)
OBJSB = $(SRCSB:.c=.o)
HEADER = -I./header/

FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

ifdef WITH_BONUS
	TARGET = $(NAMEB)
else
	TARGET = $(NAME)
endif

all : $(TARGET)

bonus :
	make WITH_BONUS=1 all
	
%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "${FG_LBLUE}push_swap make success!\n${NO_COLOR}"

$(NAMEB) : $(OBJSB)
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "${FG_LBLUE}checker make success!\n${NO_COLOR}"

clean :
	@rm -rf $(OBJS) $(OBJSB)
	@printf "${FG_GREEN}push swap clean!\n${NO_COLOR}"

fclean : clean
	@rm -rf $(NAME) $(NAMEB)
	@printf "${FG_GREEN}push swap fclean!\n${NO_COLOR}"

re : fclean all

.PHONY: all clean fclean re bonus
