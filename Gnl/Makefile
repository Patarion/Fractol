# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:04:24 by jgagnon           #+#    #+#              #
#    Updated: 2022/01/10 15:04:26 by jgagnon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

FLAGS = -Wall -Werror -Wextra

SRCS_FILES = 	get_next_line.c\
				get_next_line_utils.c

OBJS_FILES = $(SRCS_FILES:.c=.o)

NORM = norminette

RM = rm -f

all:	$(NAME)

$(NAME) :		$(OBJS_FILES)
						ar rcs $(NAME) $(OBJS_FILES)
						@echo "____GNL créé avec succès____"

clean :
		rm -rf $(OBJS_FILES)
		@echo "____Les objets des fonctions sont supprimés____"

fclean : clean
	rm -f $(NAME)
	@echo "_____Les textes anciens sont brûlés____"

re : fclean all
