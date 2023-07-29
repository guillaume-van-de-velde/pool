SRCS_MAIN		=	main.c error.c free.c set.c

SRCS_PARSING	=	check_args.c check_file.c fill_chars.c \
					ft_split.c parsing.c read_file.c

SRCS_RESOLVE	=	resolve.c

SRCS_DIR		=	${addprefix main/, ${SRCS_MAIN}} \
					${addprefix parsing/, ${SRCS_PARSING}} \
					${addprefix resolve/, ${SRCS_RESOLVE}}

SRCS			=	${addprefix srcs/, ${SRCS_DIR}}

OBJ_DIR			=	${addprefix binaries/, ${SRCS_DIR}}

OBJS			= 	${OBJ_DIR:%.c=%.o}

HEADERS_BSQ		=	bsq.h parsing.h resolve.h

HEADERS			=	${addprefix includes/, ${HEADERS_BSQ}}

NAME			= 	bsq

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

MAKEFLAGS		+=	--no-print-directory


binaries/%.o	:	srcs/%.c ${HEADERS} Makefile | binaries
			@mkdir -p $(@D)
			${CC} ${CFLAGS} -c $< -o $@ -Iincludes/

${NAME}			:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all				:	${NAME}

binaries 		:
			@mkdir -p binaries/

clean			:
			rm -rf -p binaries

fclean			:	clean
			${RM} ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re