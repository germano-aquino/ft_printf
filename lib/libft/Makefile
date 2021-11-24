# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 11:25:54 by grenato-          #+#    #+#              #
#    Updated: 2021/11/22 23:06:32 by grenato-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Rules that must have in makefile
# $(NAME), all, clean, fclean and re.

# define the C compiler
CC = clang

# define any compile-time flags
CFLAGS = -Wall -Wextra -Werror -I $(H_SOURCE)

# name of the project
NAME = libft.a

# .c bonus files
B_SOURCE =	ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c

# .c mandatory files
C_SOURCE =	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c

# .h file
H_SOURCE = ../../include/libft.h

# mandatory object files
OBJ = $(C_SOURCE:.c=.o)

# bonus object files
B_OBJ = $(B_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(B_OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

bonus: $(B_OBJ)
	ar rcs $(NAME) $(OBJ) $(B_OBJ)
