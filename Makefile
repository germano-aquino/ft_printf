# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 19:19:45 by grenato-          #+#    #+#              #
#    Updated: 2021/11/24 22:37:25 by grenato-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# define the C compiler
CC = clang

# define any compile-time flags
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

# name of the project
NAME = libftprintf.a

INCLUDE = include

SRC_DIR = src

LIBFT_DIR = libft

LIBFT = libft/libft.a

C_SOURCE = ${SRC_DIR}/print_address.c\
			${SRC_DIR}/print_number.c\
			${SRC_DIR}/print_words.c\
			ft_printf.c

OBJ = $(C_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ${LIBFT_DIR}
	cp ${LIBFT} ${NAME}
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C ${LIBFT_DIR} clean

fclean: clean
	rm -rf ${NAME}
	$(MAKE) -C ${LIBFT_DIR} fclean

re: fclean all