SRCS = 	ft_display_file.c

OBJS = 	${SRCS:%.c=%.o}

NAME = 	ft_display_file

CC 	= 	gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	 rm -rf ${OBJS}

fclean: clean
	 ${RM} ${NAME}