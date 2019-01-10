# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/30 00:36:52 by tmaluh            #+#    #+#              #
#    Updated: 2019/01/10 15:31:08 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = obf

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LMAKE = make -C libft
	DEL = rm -rf
else
	LMAKE = mingw32-make -C libft
	DEL = del
endif
ifeq ($(UNAME_S),Linux)
	LMAKE = make -C libft
	DEL = rm -rf
endif

CC = gcc -march=native
CFLAGS = -g -Wall -Wextra -Werror

SRC = srcs/main.c srcs/obf_file_reader.c srcs/obf_file_cut_wss.c \
srcs/obf_file_obfsct.c srcs/obf_file_free.c srcs/obf_file_save.c \
srcs/obf_flags_todo.c srcs/obf_file_ccrot.c srcs/obf_flags_parser.c
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

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

obf_del:
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
