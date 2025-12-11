CC = cc 
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c load_textures.c hooks.c create_map.c map_characters_check.c \
	   map_path_check.c map_size_check.c map_unit_check.c build_window.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

LIBFT_DIR = libft
LIBFT   = $(LIBFT_DIR)/libft.a

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -g3 -Llibft -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -lft -o $(NAME)

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
