NAME = libft.a

SRCS = ft_putnbr_fd.c ft_atoi.c \
	   ft_isalpha.c ft_calloc.c\
	   ft_isalnum.c ft_bzero.c \
	   ft_isascii.c ft_memccpy.c \
	   ft_isdigit.c ft_memchr.c \
	   ft_isprint.c ft_memcmp.c \
	   ft_itoa.c ft_memcpy.c \
	   ft_split.c ft_memmove.c \
	   ft_substr.c ft_memset.c \
	   ft_tolower.c ft_memcpy.c \
	   ft_toupper.c ft_strdup.c \
	   ft_putchar_fd.c ft_strjoin.c \
	   ft_putendl_fd.c ft_strlcat.c \
	   ft_putnbr_fd.c ft_strlcpy.c \
	   ft_putstr_fd.c ft_strlen.c \
	   ft_strchr.c ft_strmapi.c \
	   ft_strncmp.c ft_strtrim.c \
	   ft_strnstr.c ft_strrchr.c\
	   ft_lstnew.c	ft_lstadd_front.c\
	   ft_lstsize.c ft_lstlast.c\
	   ft_lstadd_back.c ft_lstdelone.c\
	   ft_lstclear.c	ft_lstiter.c ft_lstmap.c \
	   ft_getnumber.c ft_issign.c \
	   ft_first_sym.c ft_isblankline.c \
	   ft_first_occurence.c ft_strcmp.c \
	   ft_skip_occurence.c ft_isinstr.c \
	   ft_swap.c ft_swapf.c
	   

SRCSB =

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB: .c=.o}

INCLUDE = libft.h

CC = gcc

CFLAGS = -Wextra -Wall -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDE}

all:	${NAME}

$(NAME):	${OBJS} ${INCLUDE} 
			ar rc ${NAME} ${OBJS}
			
bonus:		${OBJS} ${OBJSB} ${INCLUDE}
			ar rc ${NAME} ${OBJS} ${OBJSB}
clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all
