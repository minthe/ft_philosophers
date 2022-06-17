NAME	= philo

CC		= gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=thread -g

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
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all