#!/bin/sh
gcc -Wall -Wextra -Werror -fsanitize=address -g ../ft_printf.c ../ft_printf_utils1.c ../ft_printf_utils2.c ../specifier1.c ../specifier2.c ../format_parse.c main.c -I ../
