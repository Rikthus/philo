NAME	:=	philo

CSAN	:=	-fsanitize=thread -g3

CC	:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror $(CSAN)

DIR_SRCS	:=	sources
DIR_OBJS	:=	.objs
DIR_INCS	:=	includes

LST_SRCS	:=	main.c \
				parsing.c \
				init.c \
				init_data.c \
				monitoring.c \
				th_handler.c \
				event_ctrl.c \
				events.c \
				cleaner.c \
				utils.c

LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	philo.h

SRCS	:=	$(addprefix $(DIR_SRCS)/,$(LST_SRCS))
OBJS	:=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS))
INCS	:=	$(addprefix $(DIR_INCS)/,$(LST_INCS))

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c $(INCS) Makefile | $(DIR_OBJS)
					$(CC) $(CFLAGS) -I $(DIR_INCS) -c $< -o $@

$(DIR_OBJS)	:
				mkdir -p $(DIR_OBJS)

clean	:
			rm -rf $(DIR_OBJS)

fclean	:	clean
			rm -rf $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
