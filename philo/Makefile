NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror -g -pthread
SRCS := ft_atoi.c monitor.c mutex_init.c philo_loop.c parsing.c philo_init.c philo.c utils.c
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