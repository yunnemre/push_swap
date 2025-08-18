CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf

SRCS    = main.c \
		  parse_args.c \
		  stack_manager.c \

OBJS    = $(SRCS:.c=.o)

NAME    = push_swap
LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
