# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 16:08:21 by fschnorr          #+#    #+#              #
#    Updated: 2024/11/26 14:10:50 by fschnorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

INCLUDE = -I include
SRC = $(addprefix src/, $(addsuffix .c,		\
						get_next_line		\
                        get_next_line_utils	\
											))
OBJS := $(SRC:.c=.o)

CC = cc
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@echo -n "run ar for gnl..."
	@ar rcs $(NAME) $(OBJS)
	@echo "done"

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@echo -n "run fclean for gnl..."
	@rm -f $(NAME)
	@echo "done"

re: fclean all