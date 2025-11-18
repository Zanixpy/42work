CC      = cc
CFLAGS  = -Wall -Wextra -Werror

NAME    = libftprintf.a
LIBFT_DIR = libft
LIBFT   = $(LIBFT_DIR)/libft.a

SRCS    = ft_printf.c ft_convert_type.c ft_convert_type_utils.c
OBJS    = $(SRCS:.c=.o)
HEADER  = libftprintf.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re