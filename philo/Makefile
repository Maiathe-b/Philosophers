NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
SRCS := ft_atoi.c parsing_utils.c parsing.c philo_init.c philo.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re