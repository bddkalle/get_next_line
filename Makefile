# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 16:08:21 by fschnorr          #+#    #+#              #
#    Updated: 2024/11/20 16:30:04 by fschnorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

INCLUDE = -I include
SRC = $(addprefix src/, get_next_line.c \
                        get_next_line_utils.c)
OBJS := $(SRC:.c=.o)

CC = cc
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "ran ar for gnl"

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "ran fclean for gnl"

re: fclean all