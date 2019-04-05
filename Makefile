# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:59:51 by alerandy          #+#    #+#              #
#    Updated: 2019/04/05 08:51:46 by alerandy         ###   ########.fr        #
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
INCLUDES += ./includes $(SDL2)/include libft/includes
LIBS = -L./libft -lft -L./SDL/build/.libs -lSDL2 -Wl,-rpath,./SDL/build/.libs
SRCS += main.c 
INCLUDES:=$(addprefix -I, $(INCLUDES))

# Updating the VPATH
VPATH =.:obj:$(shell find src -type d | tr '\n' ':'):SDL/build/.libs

# Insert .o files
OBJS = $(SRCS:%.c=%.o)
OPATH = obj/
PATH_OBJ = $(addprefix $(OPATH), $(OBJS))

# PROGRESS BAR | Original author Cpirlot
T = $(words $(PATH_OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

all: libs $(SDL2) $(NAME)

$(SDL2):
	@printf "\033[1A\r\033[K""\r\033[K""\033[32m[SDL2] \033[0m""Downloading""\n"
	@curl https://www.libsdl.org/release/SDL2-2.0.9.tar.gz > SDL2.tar.gz
	@tar -xf SDL2.tar.gz
	@rm -rf SDL2.tar.gz
	@printf '\033[K\033[1A\033[K\033[1A\033[K\033[1A\033[K\033[1A'
	@printf "\r\033[K""\r\033[K""\033[32m[SDL2] \033[0m""Installing""\n"
	@mkdir SDL && cd SDL && sh ../$(SDL2)/configure > /dev/null 2> /dev/null
	@make -C SDL -j > /dev/null 2> /dev/null
	@printf "\033[1A\r\033[K""\r\033[K""\033[32m[SDL2] \033[0m""Ready""\n"

$(NAME): $(OBJS) $(HEADERS)
	@printf "\r\033[K""\r\033[K""\033[32m[GUI] \033[0m""Compilation""\n"
	@$(COMPILE) $(INCLUDES) $(PATH_OBJ) -o $(NAME) $(LIBS)
	@printf "\033[1A\r\033[K""\r\033[K""\033[32m[GUI] \033[0m""Ready""\n"

%.o: %.c $(HEADERS)
	@mkdir -p $(OPATH)
	@printf "%-60b\r" "$(ECHO) Compiling $@"
	@$(COMPILE) $(INCLUDES) -c $< -o $(OPATH)$@

libs:
	@make -C libft -j

clean:
	@rm -rf $(NAME)
	@make -C libft clean

fclean: clean
	@rm -rf obj
	@rm -rf libft/libft.a

hardre:
	@rm -rf $(SDL2)
	@rm -rf SDL
	@make re

re: fclean all
