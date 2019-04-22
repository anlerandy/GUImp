# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:59:51 by alerandy          #+#    #+#              #
#    Updated: 2019/04/22 13:08:22 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = guimp
CFLAGS = -Wall -Werror -Wextra
CC = gcc
COMPILE=$(CC) -g3 $(CFLAGS)

# Get all dependances
include includes.dep

# Intisialize the main files
SDL2 = SDL2-2.0.9
INCLUDES += ./includes ./libui/$(SDL2)/include ./libui/libft/includes \
			./libui/includes
LIBS = -L./libui -lui -L./libui/libft -lft -L./libui/SDL/build/.libs -lSDL2 \
	   -Wl,-rpath,./libui/SDL/build/.libs

SRCS += main.c
INCLUDES:=$(addprefix -I, $(INCLUDES))

# Updating the VPATH
VPATH =.:obj:$(shell find src -type d | tr '\n' ':'):SDL/build/.libs

# Insert .o files
OBJS = $(SRCS:%.c=%.o)
OPATH = obj/
PATH_OBJ = $(addprefix $(OPATH), $(OBJS))

T = $(words $(PATH_OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

all: libs $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@printf "\r\033[K""\r\033[K""\033[32m[GUI] \033[0m""Compiling""\n"
	@$(COMPILE) $(PATH_OBJ) -o $(NAME) $(INCLUDES) $(LIBS)
	@sh updateLinker.sh
	@printf "\033[1A\r\033[K""\r\033[K""\033[32m[GUI] \033[0m""Ready""\n"

%.o: %.c $(HEADERS)
	@mkdir -p $(OPATH)
	@printf "%-60b\r" "\033[32m[GUI] $(ECHO)\033[0 mCompiling $@"
	@$(COMPILE) $(INCLUDES) -c $< -o $(OPATH)$@

libs:
	@make -s -C libui

clean:
	@rm -rf $(NAME)
	@make -s -C libui fclean

fclean: clean
	@rm -rf obj

re: fclean all

hardclean: fclean
	@make -s -C libui hardclean

hardre: hardclean all

.PHONY: re libs fclean hardre hardclean clean all

