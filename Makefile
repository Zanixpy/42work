CC = cc 
CFLAGS = -Wall -Werror -Wextra
SRCS = $(wildcard ft_*.c)
OBJS = $(SRCS:.c=.o)
NAME = libft.a
HEADERS = libft.h

all: $(NAME)

$(NAME): $(OBJS) 
	ar -rcs $@ $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	

.PHONY: $(NAME) all clean fclean re 