# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 16:02:10 by ppiques           #+#    #+#              #
#    Updated: 2021/11/09 17:13:47 by ppiques          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

OBJS	= ${SRC:.c=.o}

INCLUDES= includes/

SRC	= pipex.c $(addprefix srcs/, *.c) $(addprefix libft/, ft_split.c ft_memset.c \
ft_strjoin.c ft_strlen.c ft_strncpy.c ft_strcmp.c \
ft_split.c ft_putstr_fd.c)

%.o: %.c
	 ${CC} ${CFLAGS} -I$(INCLUDES) -c $< -o $@

all:	 ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

${NAME}: ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY:		all re clean fclean
