NAME	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra -c

LIB_SRC	=	../../sources/s_libft
LIB_BASE = 	ft_atoi.c \
			ft_bzero.c \
			ft_countwords.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isupper.c \
			ft_putendl_fd.c	\
			ft_striter.c \
			ft_strnstr.c \
			ft_itoa.c \
			ft_putnbr.c	\
			ft_striteri.c \
			ft_strrchr.c \
			ft_memalloc.c \
			ft_putnbr_fd.c \
			ft_strjoin.c \
			ft_strsplit.c \
			ft_memccpy.c \
			ft_putstr.c	\
			ft_strlcat.c \
			ft_strstr.c \
			ft_memchr.c	\
			ft_putstr_fd.c	\
			ft_strlen.c	\
			ft_strsub.c \
			ft_memcmp.c	\
			ft_strcat.c	\
			ft_strmap.c	\
			ft_strtrim.c \
			ft_memcpy.c	\
			ft_strchr.c	\
			ft_strmapi.c \
			ft_tolower.c \
			ft_memdel.c \
			ft_strclr.c \
			ft_strncat.c \
			ft_toupper.c \
			ft_memmove.c \
			ft_strcmp.c	\
			ft_strncmp.c \
			ft_memset.c	\
			ft_strcpy.c	\
			ft_strncpy.c \
			ft_isdigit.c \
			ft_putchar.c \
			ft_strdel.c	\
			ft_strndup.c \
			ft_islower.c \
			ft_putchar_fd.c	\
			ft_strdup.c	\
			ft_strnequ.c \
			ft_isprint.c \
			ft_putendl.c \
			ft_strequ.c	\
			ft_strnew.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstaddend.c \
			ft_get_next_line.c \
			ft_free.c \
			ft_lstsize.c \
			ft_max.c \
			ft_sqrt.c \
			ft_strclen.c \
			ft_strctrim.c \
			ft_strjoinfree.c

INCLUDES	=	../../includes

OBJS = $(addprefix $(LIB_SRC)/, $(LIB_BASE:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@ar rcs $@ $^
		@ranlib $@

$(LIB_SRC)/%.o: $(LIB_SRC)/%.c
	@gcc $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	@rm -f $(OBJS)

fclean:	clean
		@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re