CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/main.c \
		src/unit_test.c \
		src/error/error_handler.c \
		src/free/free.c \
		src/parsing/init.c \
		src/parsing/validator.c \
		src/utils/utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I include

NAME = philo

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(SRCS) -I. -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean