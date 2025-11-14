CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
