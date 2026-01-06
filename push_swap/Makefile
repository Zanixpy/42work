CC = cc 
CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c check_args.c check_args_utils.c create_stack.c \
	   stack_utils.c stack_utils_2.c stack_operations.c stack_operations_2.c \
	   stack_operations_3.c stack_sort_algorithm.c stack_sort_algorithm_utils.c \
	   calculates_steps.c operator_exec.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT_DIR = libft
LIBFT   = $(LIBFT_DIR)/libft.a

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -I. -Llibft -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all re fclean clean
