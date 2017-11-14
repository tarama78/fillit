# **************************************************************************** #
#																			   #
#														  :::	   ::::::::    #
#	 Makefile											:+:		 :+:	:+:    #
#													  +:+ +:+		  +:+	   #
#	 By: tnicolas <marvin@42.fr>					+#+  +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2017/11/13 12:36:15 by tnicolas		   #+#	  #+#			   #
#	 Updated: 2017/11/13 21:38:00 by tnicolas		  ###	########.fr		   #
#																			   #
# **************************************************************************** #

NB_GENE = 5

NAME = fillit

FILES = main.c \
		verif.c \
		verif_annexe.c

HFILES = serge.h

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

NORMAL = "\x1B[0m"
RED = "\x1B[31m"
GREEN = "\x1B[32m"
YELLOW = "\x1B[33m"
BLUE = "\x1B[34m"
MAGENTA = "\x1B[35m"
CYAN = "\x1B[36m"
WHITE = "\x1B[37m"

all:
	@echo $(CYAN)
	make -C $(LIBFT_DIR)
	@echo $(WHITE)
	make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(INC) $(LIBFT_LIB) $(CFLAGS)

$(OBJ_DIR)%.o:	$(SRCS_DIR)%.c $(HFILES)
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

cleanlib:
	@echo $(CYAN)
	make -C $(LIBFT_DIR) clean
	@echo $(WHITE)

clean: cleanlib
	rm -rf $(OBJ)

fcleanlib: cleanlib
	@echo $(CYAN)
	make -C $(LIBFT_DIR) fclean
	@echo $(WHITE)

fclean:	clean fcleanlib
	rm -f $(NAME)

relib: fcleanlib
	@echo $(CYAN)
	make -C $(LIBFT_DIR)
	@echo $(WHITE)

re: fclean all

open:
	@vim +12 *.[ch] Makefile `find ~ -iname ".vimrc" \
	   -o -iname ".vim/vim_help_file"`

exec:
	@clear
	@./gene $(NB_GENE)
	@echo "----- file -----"
	@cat map.fillit
	@echo "----- file -----"
	@make
	@./fillit map.fillit

norm:
	@norminette $(SRCS) $(HFILES)

normlib:
	make -C $(LIBFT_DIR) norm
	make norm

.PHONY: all clean clean_swp fclean re open exec norm normlib
