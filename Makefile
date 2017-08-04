NAME = filler
CC = gcc

SRC = check_coord.c ft_answers_creation.c filler.c ft_piece_field_creating.c get_next_line.c
OBJ = $(SRC:.c=.o)
CFLAGS = -c -Wall -Wextra -Werror
HEADER = filler.h

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) -L./libft -lft -o $(NAME)
	@echo "\033[0;32mFiller is compiled\033[0m"

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) $<

clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)

re: fclean all
