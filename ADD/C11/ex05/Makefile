SRCS = 	do_op.c op.c ft_atoi.c

OBJS = 	${SRCS:%.c=%.o}

NAME = 	do-op

CC 	= 	gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -I.

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	 rm -rf ${OBJS}

fclean: clean
	 ${RM} ${NAME}