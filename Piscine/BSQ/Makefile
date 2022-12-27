SRCS = srcs/bsq.c srcs/file_reader.c srcs/map.c srcs/map_reader.c srcs/square.c srcs/string.c srcs/check_chars.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = bsq
CC 	= gcc
RM 	= rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} -I ${INCS}

all: ${NAME}

clean:
	 ${RM} ${OBJS}

fclean: clean
	 ${RM} ${NAME}

re: fclean all
