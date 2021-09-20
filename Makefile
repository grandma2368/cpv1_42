# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cduverge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 16:28:27 by cduverge          #+#    #+#              #
#    Updated: 2021/01/18 10:35:12 by cduverge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean re fclean all

NAME = computor

SRC =	main.c parsing.c resolve.c usefull.c bonus.c

OBJ = $(SRC:.c=.o)

HEADERS = ./computorv1.h

LIB = libft

CC = gcc

VERT = \033[32m
CYAN = \033[36m
JAUNE = \033[33m
ROUGE = \033[31m
BLANC = \033[37m

OKJAUNE = $(CYAN) ====> $(JAUNE)[OK]$(BLANC)
KOROUGE = $(CYAN) ====> $(ROUGE)[KO]$(BLANC)

%.o: %.c
	@$(CC) -c -I libft/ $< -o $@ -I./

$(NAME): $(OBJ) $(SRC) | lib_rule
	@$(CC) -I libft/  $(OBJ) -I $(HEADERS) libft/libft.a -o $(NAME) && echo "- $(VERT)Objects Creation$(OKJAUNE)" || (echo "- $(VERT)Objects Creation$(KOROUGE)" && false)

lib_rule:
	@$(MAKE) -C $(LIB) 1>/dev/null

all: $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "- $(VERT)Deleted objects$(OKJAUNE)"
	@$(MAKE) clean -C $(LIB)

fclean: clean
	@rm -rf $(NAME)
	@echo "- $(VERT)Deleted exe$(OKJAUNE)"
	@$(MAKE) fclean -C $(LIB)

re: fclean all