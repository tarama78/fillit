# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 12:36:15 by tnicolas          #+#    #+#              #
#    Updated: 2017/11/13 15:14:28 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main.c

LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

INC_DIR = . \
		  $(LIBFT_DIR)
OBJ_DIR = ./
SRCS_DIR = ./

SRCS := $(addprefix $(SRC_DIR), $(FILES))
INC := $(addprefix -I , $(INC_DIR))
OBJ := $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:
	make -C $(LIBFT_DIR)
	make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(INC) $(LIBFT_LIB) $(CFLAGS)

$(OBJ_DIR)%.o:	$(SRCS_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

cleanlib:
	make -C $(LIBFT_DIR) clean

clean: cleanlib
	rm -rf $(OBJ)

fcleanlib: cleanlib
	make -C $(LIBFT_DIR) fclean

fclean:	clean fcleanlib
	rm -f $(NAME)

relib: fcleanlib
	make -C $(LIBFT_DIR)

re: fclean all

open:
	@vim +12 *.[ch] Makefile `find ~ -iname ".vimrc" \
	   -o -iname ".vim/vim_help_file"`

exec:
	@clear
	@make all
	@./$(NAME)

norm:
	@norminette $(SRCS)

normlib:
	make -C $(LIBFT_DIR) norm
	make norm

normok:
	seksek = `make norm | grep -v "Norme:"`
	if [ $seksek" = "" ];then
		echo "ok"
	else
		echo "error norm"
	fi

.PHONY: all clean clean_swp fclean re open exec norm normlib normok initsubmod
