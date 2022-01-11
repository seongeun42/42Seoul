CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft.a
SRCS = part1/ft_memset.c\
	part1/ft_bzero.c\
	part1/ft_memcpy.c\
	part1/ft_memccpy.c\
	part1/ft_memmove.c\
	part1/ft_memchr.c\
	part1/ft_memcmp.c\
	part1/ft_strlen.c\
	part1/ft_strlcpy.c\
	part1/ft_strlcat.c\
	part1/ft_strchr.c\
	part1/ft_strrchr.c\
	part1/ft_strnstr.c\
	part1/ft_strncmp.c\
	part1/ft_atoi.c\
	part1/ft_isalpha.c\
	part1/ft_isalnum.c\
	part1/ft_isdigit.c\
	part1/ft_isascii.c\
	part1/ft_isprint.c\
	part1/ft_toupper.c\
	part1/ft_tolower.c\
	part1/ft_calloc.c\
	part1/ft_strdup.c\
	part2/ft_substr.c\
	part2/ft_strjoin.c\
	part2/ft_strtrim.c\
	part2/ft_split.c\
	part2/ft_itoa.c\
	part2/ft_strmapi.c\
	part2/ft_putchar_fd.c\
	part2/ft_putstr_fd.c\
	part2/ft_putendl_fd.c\
	part2/ft_putnbr_fd.c
BSRCS = bonus/ft_lstnew.c\
	bonus/ft_lstadd_front.c\
	bonus/ft_lstsize.c\
	bonus/ft_lstlast.c\
	bonus/ft_lstadd_back.c\
	bonus/ft_lstdelone.c\
	bonus/ft_lstiter.c\
	bonus/ft_lstclear.c\
	bonus/ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ $< -I.

$(NAME) : $(OBJS)
	@ar -cr $@ $^
	@printf "${FG_LBLUE}libft.a make success!\n${NO_COLOR}"

bonus : $(BOBJS)
	@ar -cr $(NAME) $^
	@printf "${FG_LBLUE}libft bonus make success!\n${NO_COLOR}"

clean :
	@rm -f $(OBJS) $(BOBJS)
	@printf "${FG_GREEN}libft clean!\n${NO_COLOR}"

fclean : clean
	@rm -f $(NAME)
	@printf "${FG_GREEN}libft fclean!\n${NO_COLOR}"

re : fclean all
