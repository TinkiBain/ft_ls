# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/05 14:55:54 by dwisoky           #+#    #+#              #
#    Updated: 2019/09/06 20:23:33 by dwisoky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror
SRCS = ft_ls.c ls_error.c parsing_flag.c create_file.c check_sort.c print.c print_one_file.c space.c lflag.c standart_out.c term_size.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ft_ls.h

all:	$(NAME)

$(NAME):	$(OBJS)
			@echo "\x1b[32;01mCompilation...\x1b[32;01m"
			@make --directory ./libft
			@gcc $(FLAGS) $(OBJS) -o $(NAME) -L ./libft -lft
			@echo "\x1b[32;01mYour ./ft_ls is ready\x1b[0m"

$(OBJS):	%.o: %.c
			@gcc $(FLAGS) -c -g $< -I $(INCLUDES) -o $@
clean:
			@echo "\033[34mDeliting o-files\033[0m"
			@/bin/rm -f $(OBJS)
			@make clean --directory ./libft

fclean:	clean
			@echo "\033[34mDeliting binary\033[0m"
			@/bin/rm -f $(NAME)
			@make fclean --directory ./libft

re:	fclean all

