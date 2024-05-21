# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:17:47 by mpellegr          #+#    #+#              #
#    Updated: 2024/05/21 09:33:09 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_printf.c ft_printchar.c ft_printstr.c ft_printint.c ft_printuint.c ft_printptr.c ft_printhexa.c

OBJECTS = $(SOURCES:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

LIBFT = libft

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re bonus
