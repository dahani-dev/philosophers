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
	   helper-functions/create_threads_and_join.c \
	   helper-functions/destroy_all_mutex.c \
	   helper-functions/death_checker.c \
	   helper-functions/unlock_forks.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
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
.SECONDARY: ${OBJS}