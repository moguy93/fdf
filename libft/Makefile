# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moguy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 16:01:44 by moguy             #+#    #+#              #
#    Updated: 2019/01/20 00:58:30 by moguy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRCS =	ft_isprint.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_power.c \
		ft_putnbrd.c \
		ft_strcat.c \
		ft_strjoin.c \
		ft_strnstr.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_abs.c \
		ft_memalloc.c \
		ft_putchar_fd.c \
		ft_strclr.c \
		ft_strlen.c \
		ft_strsplit.c \
		ft_atoi.c \
		ft_memccpy.c \
		ft_putendl.c \
		ft_strcmp.c \
		ft_strmap.c \
		ft_strstr.c \
		ft_bzero.c \
		ft_memchr.c \
		ft_putendl_fd.c \
		ft_strcpy.c \
		ft_strmapi.c \
		ft_strsub.c \
		ft_count_words.c \
		ft_memcmp.c \
		ft_putnbr.c \
		ft_strdel.c \
		ft_strncat.c \
		ft_strtrim.c \
		ft_isascii.c \
		ft_memcpy.c \
		ft_putnbr_fd.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_memdel.c \
		ft_putstr.c \
		ft_strequ.c \
		ft_strncpy.c \
		ft_toupper.c \
		ft_isalpha.c \
		ft_memmove.c \
		ft_putstr_fd.c \
		ft_striter.c \
		ft_strnequ.c \
		ft_isdigit.c \
		ft_memset.c \
		ft_realloc.c \
		ft_striteri.c \
		ft_is_white_space.c\
		ft_strnew.c\
		ft_del.c \
		ft_convert_degree.c \
		get_next_line.c

OBJ = $(SRCS:.c=.o)

all : $(NAME) libft.h

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
