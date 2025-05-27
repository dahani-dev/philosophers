NAME = philo

SRCS = main.c \
	   helper-functions/custom_error.c \
	   helper-functions/ft_atoi.c \
	   helper-functions/init_shared_data.c \
	   helper-functions/init_philosophers.c \
	   helper-functions/routine.c \
	   helper-functions/safe_print.c \
	   helper-functions/get_time_ms.c \
	   helper-functions/monitor_routine.c \
	   helper-functions/safe_usleep.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g -O1
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re