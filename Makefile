NAME = fillit

FILES = main.c

LIBFT_DIR = libft
LIBFT_LIB = -L $(LIBFT_DIR) -lft

INC_DIR = . \
		  $(LIBFT_DIR)/includes

SRCS := $(addprefix ./, $(FILES))
INC := $(addprefix -I , $(INC_DIR))
OBJ := $(addprefix ./, $(FILES:.c=.o))

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

re: fclean all

open:
	@vim +12 *.[ch] Makefile `find ~ -iname ".vimrc" \
	   -o -iname ".vim/vim_help_file"`

exec: all
	@clear
	@./$(NAME)

norm:
	@norminette $(SRCS) $(INC_DIR)/*

normlib:
	make -C $(LIBFT_DIR) norm
	make norm

normok:
	@make norm | grep -v "Norme:"

.PHONY: all clean clean_swp fclean re open exec norm normlib normok
