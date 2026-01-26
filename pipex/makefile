CC = cc 
CFLAGS = -Wall -Werror -Wextra

SRCS = pipex.c pipex_utils.c args_validation.c files_utils.c cmds_utils.c functs_utils.c buffer_file_utils.c free.c
OBJS = $(SRCS:.c=.o)
NAME = pipex
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
