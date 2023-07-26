SRCS =	ft_hexdump.c data.c result.c display_number_octets.c print.c ft_str.c stdin.c

OBJS = 	${SRCS:%.c=%.o}

NAME = 	ft_hexdump

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