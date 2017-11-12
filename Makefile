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

all: $(NAME)
	make -C $(LIBFT_DIR)
	gcc $(OBJ) -o $(NAME) $(INC) $(LIBFT_LIB)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) -c $(INC) $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ)

clean_swp:
	find . -name "*~" -o -name "#*#" -o -name ".*.swp" -delete -print

fclean: clean clean_swp
	rm -f $(NAME)

re: fclean
	make -C $(LIBFT_DIR) re
	make all



all :
	make -C $(LIBFT_DIR)
	make $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJ) -o $(NAME) $(INC_DIR) $(LIBFT_LIB) $(CFLAGS)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

#$(OBJ_DIR) :
#	mkdir -p $(OBJ_DIR)
#	mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ $(INC_DIR)

clean: cleanlib
	rm -rf $(OBJ_DIR)

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME)

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)


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

.PHONY: all clean clean_swp fclean re open exec norm normlib normok
