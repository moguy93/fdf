# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moguy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 02:01:28 by moguy             #+#    #+#              #
#    Updated: 2019/02/16 00:16:27 by moguy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF = \033[0m
GRA = \033[1m
SOU = \033[4m
BLI = \033[5m
BLA = \033[30m
RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
PUR = \033[35m
CYA = \033[36m
WHI = \033[37m
ORG = \033[1;31m

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

NAME = fdf

SRCS_NAME = ft_error.c \
	   		ft_convert_color.c \
	   		ft_main.c \
	   		ft_line.c \
	   		ft_check.c \
	   		ft_get_map.c \
	   		ft_aff_map.c \
	   		ft_color_line.c \
	   		ft_color.c \
	   		ft_rotate.c \
	   		ft_text.c \
	   		ft_deal2.c \
	   		ft_deal.c

SRCS_PATH = srcs/

HDR_NAME = fdf.h

HDR_PATH = includes/

MLX_NAME = libmlx.a

MLX_DIR = /usr/local/lib/

LIB_NAME = libft.a

LIB_PATH = libft/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

HDR = $(addprefix $(HDR_PATH), $(HDR_NAME))

MLX = $(addprefix $(MLX_DIR), $(MLX_NAME))

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIB) $(OBJ) $(HDR)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -framework OpenGL -framework \
				AppKit $(LIB) $(MLX) 
			@echo "$(ORG)Make FDF$(DEF) : $(GRE)Done!$(DEF)"

$(LIB) :
			@make -C $(LIB_PATH)
			@echo "$(ORG)Make libft$(DEF) : $(GRE)Done!$(DEF)"

%.o : %.c $(HDR)
			$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean : $(SRCS)
			@make -C libft/ clean
			@rm -rf $(OBJ)
			@echo "$(ORG)FDF clean$(DEF) : $(GRE)Done!$(DEF)"

fclean : clean
			@make -C libft/ fclean
			@rm -rf $(NAME)
			@echo "$(ORG)FDF fclean$(DEF) : $(GRE)Done!$(DEF)"

re : fclean all
