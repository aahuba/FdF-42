NAME = fdf

LIB_SRC = ./sources/s_libft
LIB_INC = ./includes/i_libft
LIB = ./libft.a

INC_DIR = ./includes/i_fdf
INCS = -I $(LIB_INC) -I $(INC_DIR)
SRC_DIR = ./sources/s_fdf
SRC_BASE = main.c \
			window.c \
			key.c \
			read_map.c \
			draw.c

OBJ_DIR = ./objects

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_BASE:.c=.o))

CFLAGS = -Wall -Werror -Wextra

all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	gcc -g $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $@ $<

$(LIB):
	make -f Makelibft
	
obj:
	mkdir -p objects

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	gcc $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	make -f Makelibft clean

fclean: clean
	rm -f $(NAME)
	make -f Makelibft fclean

re: fclean all

.PHONY: clean all re fclean