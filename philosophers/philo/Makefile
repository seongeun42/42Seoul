# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 22:46:42 by seongele          #+#    #+#              #
#    Updated: 2021/12/01 22:27:18 by seongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRCS = src/philo.c\
		src/utils.c\
		src/action.c\
		src/setting.c
OBJS = $(SRCS:.c=.o)
HEADER = -I./header/ -Ipthread

FG_GREEN   = \e[32m
FG_LBLUE   = \e[94m
NO_COLOR   = \e[0m

all : $(NAME)
	
%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)
	@printf "philo is making...\n"

$(NAME) : $(OBJS)
	@$(CC) $(CFLAG) -o $@ $(OBJS)
	@printf "${FG_LBLUE}philo make success!\n${NO_COLOR}"

clean :
	@rm -f $(OBJS)
	@printf "${FG_GREEN}clean!\n${NO_COLOR}"

fclean : clean
	@rm -f $(NAME)
	@printf "${FG_GREEN}fclean!\n${NO_COLOR}"

re : fclean all

.PHONY: all clean fclean re
