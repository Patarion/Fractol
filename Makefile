CC = gcc

NAME = Fract-ol
SRC = Event.c Mandelbrot.c Color.c Main.c Julia.c
OBJS = $(SRC:.c=.o)
NORM = norminette
CFLAGS = -Wall -Werror -Wextra -o2
RM = rm -f

LIBFT_DIR = Libft/
SRCS_DIR = srcs/
OBJS_DIR = objs/

LIBFT = $(MAKE) --silent -C $(LIBFT_DIR)

all:	$(NAME)

$(OBJS_DIR)%.o:%.c
	@${CC} ${CFLAGS} -I${LIBFT_DIR} -o $@ -c $<

$(NAME): $(OBJS)
				${LIBFT}
				${CC} ${OBJS} -L${LIBFT_DIR} -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} -lm
				@echo "_____Fract-ol créé avec succès______"

clean:
				rm -rf $(OBJS)
				@echo "_____Les objet ont été supprimés______"

fclean:	clean
		rm -f $(NAME)
		@echo "_______Les textes anciens ont été brûlés______"

re: fclean all
