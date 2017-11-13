# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 12:36:15 by tnicolas          #+#    #+#              #
#    Updated: 2017/11/13 12:45:26 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main.c

LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

INC_DIR = . \
		  $(LIBFT_DIR)includes
OBJ_DIR = ./
SRCS_DIR = ./

SRCS := $(addprefix $(SRC_DIR), $(FILES))
INC := $(addprefix -I , $(INC_DIR))
OBJ := $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all :
	make -C $(LIBFT_DIR)
	make $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(INC) $(LIBFT_LIB) $(CFLAGS)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

clean: cleanlib
	rm -rf $(OBJ)

cleanlib:
	make -C $(LIBFT_DIR) clean

fclean:	clean fcleanlib
	rm -f $(NAME)

fcleanlib: cleanlib
	make -C $(LIBFT_DIR) fclean

re: fclean all

relib: fcleanlib $(LIBFT_LIB)


open:
	@vim +12 *.[ch] Makefile `find ~ -iname ".vimrc" \
	   -o -iname ".vim/vim_help_file"`

exec:
	@clear
	@make all
	@./$(NAME)

norm:
	@norminette $(SRCS) $(INC_DIR)/*

normlib:
	make -C $(LIBFT_DIR) norm
	make norm

normok:
	@make norm | grep -v "Norme:"

initsubmod:
	git submodule init
	git submodule update

.PHONY: all clean clean_swp fclean re open exec norm normlib normok initsubmod
