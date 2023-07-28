SRCS = 	main.c parsing.c resolve.c check_args.c \
		check_dict_lines.c create_dict.c dict.c error.c \
		ft_split.c len.c utils.c print_result.c

OBJS = 	${SRCS:%.c=%.o}

NAME = 	rush-02

CC 	=	cc

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