CLIENT = client
SERVER = server
SRCS= client.c server.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC= cc
CC_FLAGS= -Wall -Wextra -Werror

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

$(CLIENT):
	$(CC)  $(CC_FLAGS) client.c -L$(LIBFT_DIR) -lft -o $(CLIENT)

$(SERVER):
	$(CC)  $(CC_FLAGS) server.c -L$(LIBFT_DIR) -lft -o $(SERVER)

.PHONY: all clean fclean re