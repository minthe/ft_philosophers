SOURCE =	main.c \

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra -fsanitize=thread -g

NAME = philo

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all