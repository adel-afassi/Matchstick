##
## Makefile for  in /home/adel/delivery/CPE_2016_matchstick/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Sat Feb 25 20:57:43 2017 John Doe
## Last update Sun Feb 26 18:47:16 2017 John Doe
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -g3 -I include

NAME	=	matchstick

SRCS	=	functions/my_function.c	\
		functions/my_function_bis.c	\
		gnl/get_next_line.c		\
		sources/main.c		\
		sources/stick_map.c		\
		sources/print_map.c		\
		sources/check_fonction.c	\
		sources/input_error.c	\
		sources/error_handling.c	\
		sources/human_player_bis.c	\
		sources/matchstick.c	\
		sources/ia_player.c		\
		sources/victory.c		\
		sources/human_player.c

OBJS	=	$(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
