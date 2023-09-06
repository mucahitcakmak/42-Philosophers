NAME = philo
CFLAGS = -Wall -Wextra -Werror

SRCS = philosophers.c

all: $(NAME)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)