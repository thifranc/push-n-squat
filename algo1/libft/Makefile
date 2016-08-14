# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thifranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:24:34 by thifranc          #+#    #+#              #
#    Updated: 2016/06/07 13:00:42 by thifranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC = atoi itoa ptrf\
			memalloc bzero memccpy memchr memset\
			memmove memcmp memcpy memdel\
			putnb_base putendl putendl_fd\
			putnbr putnbr_fd putstr putstr_fd\
			putchar putchar_fd write_fd\
			strcat striter strncpy strtrim\
			strchr striteri strnequ\
			strlcat strclr strjoin strnew\
			strcmp strlen strnstr\
			strcpy strmap strrchr\
			strdel strmapi strsplit\
			strdup strncat strstr\
			strequ strncmp strsub\
			tolower isalnum toupper isalpha\
			isascii isdigit isprint\
			lstadd lstnew lstdelone lstiter lstmap lstdel\
			get_char\
			max min power lower\
			base_10 higher\
			print_n_char nblen nb_len_base\
			tabnew\
			strdup_del strjoin_del deltab\
			gnl swap realloc\
			exiting abs get_rank

SRC:= $(addprefix ft_, $(SRC))
SRC:= $(addsuffix .c, $(SRC))
OBJ = $(SRC:%.c=%.o)
all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	make clean

clean :
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)
re : fclean all
