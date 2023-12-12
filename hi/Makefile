NAME = shell

SRC = 	 _getenv.c _strtok.c shellSimplement.c ssFunctions1.c ssFunctions2.c ssFunctions3.c \
		 token.c _split.c _bzero.c _calloc.c _memset.c _strlen.c _strjoin.c

OBJS =  $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
CC = gcc -g3

%.o: %.c 
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
		 $(CC) $(CFLAGS) $(OBJS)  -o $(NAME) 

leaks: 
	valgrind --leak-check=full --trace-children=yes \
	--show-leak-kinds=all --track-origins=yes ./$(NAME)

all: $(NAME)

clean: 
		@echo "$-------- CLEAN $(DEFAULT)"
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
		@echo "$-------- $(NAME) Removed!$(DEFAULT)"

re: fclean	all

.PHONY: all clean fclean re