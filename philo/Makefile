NAME	= philo

CC		= gcc

FLAGS = -Werror -Wall -Wextra -g  # -fsanitize=thread

RM		= rm -f

SOURCE	=	main.c \
			philo.c \
			utils.c \
			time.c \
			threads.c \
			mutex.c \

OBJECTS	= $(SOURCE:.c=.o)

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