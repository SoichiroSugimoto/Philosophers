NAME	= philo

SRCS	=	srcs/AAAAA.c \
			srcs/actions.c \
			srcs/args_error_handle.c \
			srcs/create_thread.c \
			srcs/init_gval.c \
			srcs/philo.c \
			srcs/terminator.c \
			srcs/utils.c

OBJS	= $(SRCS:.c=.o)

HEADER	= ./srcs/*.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
