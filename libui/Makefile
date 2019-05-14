# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 15:11:25 by alerandy          #+#    #+#              #
#    Updated: 2019/05/14 15:33:05 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libui.a
CFLAGS = -Wall -Werror -Wextra -g3
CC = gcc
COMPILE=$(CC) $(CFLAGS)

# Get all dependances
include includes.dep

# Deal with Cross-Platform
ifeq ($(shell uname -s), Darwin)
    linksdl = -Wl,-rpath,./SDL/build/.libs
else
    linksdl = -Wl,-rpath,./SDL/build/.libs
endif

# Intisialize the main files
SDLINK = https://www.libsdl.org/release/SDL2-2.0.9.tar.gz
SDL2 = SDL2-2.0.9
INCLUDES += ./includes ./includes/privates/ $(SDL2)/include ../libft/includes
LIBS = -L../libft -lft -L./SDL/build/.libs -lSDL2 $(linksdl)
SRCS += ui_init_univers.c ui_quit_univers.c
INCLUDES:=$(addprefix -I, $(INCLUDES))

# Updating the VPATH
VPATH =.:obj:$(shell find src -type d | tr '\n' ':')

# Insert .o files
OBJS = $(SRCS:%.c=%.o)
OPATH = obj/
PATH_OBJ = $(addprefix $(OPATH), $(OBJS))

T = $(words $(PATH_OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

all: $(SDL2) $(NAME)

$(SDL2):
	@printf "\r\033[K""\033[32m[SDL2] \033[0m""Downloading""\n"
	@curl $(SDLINK) > SDL2.tar.gz
	@tar -xf SDL2.tar.gz
	@rm -rf SDL2.tar.gz
	@printf '\033[K\033[1A\033[K\033[1A\033[K\033[1A\033[K\033[1A'
	@printf "\r\033[K""\r\033[K""\033[32m[SDL2] \033[0m""Installing""\n"
	@mkdir SDL && cd SDL && sh ../$(SDL2)/configure > /dev/null 2> /dev/null
	@make -C SDL -j > /dev/null 2> /dev/null
	@printf "\033[1A\r\033[K""\r\033[K""\033[32m[SDL2] \033[0m""Ready""\n"

$(NAME): $(OBJS) $(HEADERS)
	@ar rc $(NAME) $(PATH_OBJ)
	@ranlib $(NAME)
	@printf "\r\033[K""\r\033[K""\033[32m[LIBUI]\033[0m Ready\n"

%.o: %.c $(HEADERS)
	@mkdir -p $(OPATH)
	@printf "%-60b\r" "\033[32m[LIBUI] $(ECHO)\033[0m Compiling $@"
	@$(COMPILE) $(INCLUDES) -c $< -o $(OPATH)$@

clean:
	@rm -rf obj
	@echo "\033[1;30m[LIBUI]\033[0m\033[0;37m Binaries cleaned\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;31m[LIBUI]\033[0m Deleted"

hardclean: fclean
	@rm -rf $(SDL2)
	@rm -rf SDL
	@echo "\033[0;31m[SDL2]\033[0m Deleted"

hardre: hardclean
	@make all

re: fclean all

.PHONY: re fclean hardre hardclean clean all
