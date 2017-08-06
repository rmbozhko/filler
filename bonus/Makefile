NAME = visual
CC = gcc

SRC = bonus.c bonus_helper.c
OBJ = $(SRC:.c=.o)
CFLAGS = -c -Wall -Wextra -Werror
HEADER = bonus.h

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ../libft
	@$(CC) $(OBJ) -L../libft -lft -lcurses ../get_next_line.o -o $(NAME)
	@echo "\033[0;32mFiller bonus part is compiled\033[0m"

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) $<

clean:
	@make clean -C ../libft
	@rm -rf $(OBJ) get_next_line.o

fclean: clean
	@make fclean -C ../libft
	@rm -rf $(NAME)

re: fclean all
