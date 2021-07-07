CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c format_parse.c specifier1.c specifier2.c
OBJS = $(SRCS:.c=.o)
HEADER = -I .

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $< $(HEADER)

$(NAME) : $(OBJS)
	ar -cr $@ $^

bonus : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
