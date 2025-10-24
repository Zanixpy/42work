CC = cc 
CFLAGS = -Wall -Werror -Wextra
SRCS = $(filter-out %_bonus.c, $(wildcard ft_*.c))
BONUS_SRCS = $(wildcard ft_*_bonus.c)
OBJS = get_next_line_utils.o
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
NAME = getl.a
HEADERS = get_next_line.h

all: $(NAME)

$(NAME): $(OBJS) 
	ar -rcs $@ $(OBJS)

bonus: $(BONUS_OBJS)
	ar -rcs $(NAME) $(BONUS_OBJS) 

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
