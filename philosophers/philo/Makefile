CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c args_validation.c args_validation_utils.c
OBJS = $(SRCS:.c=.o)
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