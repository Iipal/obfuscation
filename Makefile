# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/30 00:36:52 by tmaluh            #+#    #+#              #
#    Updated: 2019/01/01 16:10:55 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = obfuscation

CC = gcc -march=native
CFLAGS = -g -Wall -Wextra -Werror

SRC = srcs/obfuscation.c srcs/obf_reader.c srcs/obf_cut_whitespaces.c \
srcs/obf_concat_file.c srcs/obf_free.c
OBJ = $(SRC:.c=.o)

DEL = rm -rf

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
RED=\033[31m

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo -n '+'

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "> $(GREEN)Compiled.$(WHITE)"

obf:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(RED)deleted$(WHITE):" $(NAME)

re: fclean all

.PHONY: all fclean clean re
