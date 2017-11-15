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
		verif_annexe.c \
		fillit.c \
		algo.c

HFILES = serge.h \
		 structure.h

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
	@printf $(GREEN)"LIBFT:\n--------------------\n"$(WHITE)
	@make -C $(LIBFT_DIR)
	@printf $(GREEN)"--------------------\n\n"$(WHITE)
	@printf $(GREEN)"FILLIT:\n--------------------\n"$(WHITE)
	@make $(NAME)
	@printf $(GREEN)"--------------------\n"$(WHITE)

$(NAME): $(OBJ)
	@printf $(CYAN)"-> create fillit\n"$(WHITE)
	@$(CC) $(OBJ) -o $(NAME) $(INC) $(LIBFT_LIB) $(CFLAGS)

$(OBJ_DIR)%.o:	$(SRCS_DIR)%.c $(HFILES)
	@printf $(YELLOW)"-> $<\n"$(WHITE)
	@$(CC) $(FLAGS) -c $< -o $@ $(INC)

cleanlib:
	@printf $(GREEN)"LIBFT:\n--------------------\n"$(WHITE)
	@make -C $(LIBFT_DIR) clean
	@printf $(GREEN)"--------------------\n\n"$(WHITE)

clean: cleanlib
	@printf $(GREEN)"FILLIT:\n--------------------\n"$(WHITE)
	@printf $(RED)"-x remove .o files\n"$(WHITE)
	@printf $(GREEN)"--------------------\n\n"$(WHITE)
	@rm -rf $(OBJ)

fcleanlib:
	@printf $(GREEN)"LIBFT:\n--------------------\n"$(WHITE)
	@make -C $(LIBFT_DIR) clean_name
	@printf $(GREEN)"--------------------\n\n"$(WHITE)

fclean:	clean fcleanlib
	@printf $(GREEN)"FILLIT:\n--------------------\n"$(WHITE)
	@printf $(RED)"-x remove $(NAME)\n"$(WHITE)
	@printf $(GREEN)"--------------------\n\n"$(WHITE)
	@rm -f $(NAME)

relib: fcleanlib
	@printf $(GREEN)"LIBFT:\n--------------------\n"$(WHITE)
	@make -C $(LIBFT_DIR)
	@printf $(GREEN)"--------------------\n\n"$(WHITE)

re: fclean all

open:
	@vim +12 *.[ch] Makefile `find ~ -iname ".vimrc" \
	   -o -iname ".vim/vim_help_file"`

exec:
	@clear
	@make
	@./gene $(NB_GENE)
	@printf $(MAGENTA)"FILE:\n--------------------\n"$(WHITE)
	@cat map.fillit
	@printf $(MAGENTA)"--------------------\n\n"$(WHITE)
	@printf $(MAGENTA)"FILLIT:\n--------------------\n"$(WHITE)
	@./fillit map.fillit
	@printf $(MAGENTA)"--------------------\n\n"$(WHITE)

norm:
	@printf $(BLUE)"NORME FILLIT\n"$(WHITE)
	@norminette $(SRCS) $(HFILES)

normlib:
	@make -C $(LIBFT_DIR) norm
	@make norm

.PHONY: all clean clean_swp fclean re open exec norm normlib
