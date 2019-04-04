# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:59:51 by alerandy          #+#    #+#              #
#    Updated: 2019/04/04 11:50:27 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = theGUImp
CFLAGS = -Wall -Werror -Wextra
#CC = $(HOME)/.brew/Cellar/gcc/8.1.0/bin/gcc-8
CC = gcc
COMPILE=$(CC) -g3 $(SANITIZE) $(CFLAGS) #-O3

# Get all dependances
include includes.dep

# Deal with Cross-Platform
ifeq ($(shell uname -s), Darwin)
    libgl = -framework Appkit
else
    libgl =
endif

# Intisialize the main files
SDL2 = SDL2-2.0.9
SDLflags = -Wl,-rpath,/SDL/build/ -Wl,--enable-new-dtags #$(shell ./SDL/sdl2-config --cflags --libs | xargs)
INCLUDES += ./includes $(SDL2)/include libft/includes
LIBS = $(libgl) -L./libft -lft -L./SDL/build/.libs -lSDL2
SRCS += main.c 
INCLUDES:=$(addprefix -I, $(INCLUDES))
FRAMWEWORK = $(SDLflags)

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
	@echo 'Downloading SDL2'
	@curl https://www.libsdl.org/release/SDL2-2.0.9.tar.gz > SDL2.tar.gz
	@tar -xf SDL2.tar.gz
	@rm -rf SDL2.tar.gz
	@printf '\033[K\033[1A\033[K\033[1A\033[K\033[1A\033[K\033[1A'
	@mkdir SDL && cd SDL && sh ../$(SDL2)/configure && sh ../$(SDL2)/autogen.sh
	@make -C SDL -j
	@rm -rf SDL/build/.libs/libSDL2-2.0.so.0 SDL/build/.libs/libSDL2-2.0.so.0.9.0
	@echo 'SDL2 Ready      '

$(NAME): $(OBJS) $(HEADERS)
	@printf "\033[1A\r\033[K""\r\033[K""\033[32m[GUI] \033[0m""Compilation""\n"
	@$(COMPILE) $(INCLUDES) $(LIBS) $(PATH_OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	@mkdir -p $(OPATH)
	@printf "%-60b\r" "$(ECHO) $(_CYAN) Compiling $@ $(_END)"
	@$(COMPILE) $(INCLUDES) -c $< -o $(OPATH)$@

libs:
	@make -C libft -j

clean:
	@rm -rf $(NAME)
	@make -C libft clean

fclean: clean
	@rm -rf obj
	@rm -rf $(SDL2)
	@rm -rf SDL
	@rm -rf libft/libft.a

re: fclean all