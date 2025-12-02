CC = cc 
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c
OBJS = $(SRCS:.c=.o)
NAME = so_long


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean
