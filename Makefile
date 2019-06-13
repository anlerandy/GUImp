# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:59:51 by alerandy          #+#    #+#              #
#    Updated: 2019/06/13 19:05:38 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = guimp
CFLAGS = -Wall -Werror -Wextra
CC = clang
COMPILE= $(CC) -g3 $(CFLAGS)

# Get all dependances
include includes.dep

# Intisialize the main files
SDL2 = SDL2-2.0.9
SDLTTF = SDL2_ttf-2.0.15
INCLUDES += ./includes ./libui/shared/include/SDL2 ./libft/includes \
			./libui/includes ./libui/includes/privates
LIBS = -L./libui -lui -L./libft -lft -L./libui/shared/lib -lSDL2 -lSDL2_ttf

SRCS += main.c
INCLUDES:=$(addprefix -I, $(INCLUDES))

# Updating the VPATH
VPATH =.:obj:$(shell find src -type d | tr '\n' ':'):shared/lib

# Insert .o files
OBJS = $(SRCS:%.c=%.o)
OPATH = obj/
PATH_OBJ = $(addprefix $(OPATH), $(OBJS))

DPATH = .depends/
DPDS = $(addprefix $(DPATH), $(SRCS:%.c=%.d))

# Conditions
LIBUI = libui/libui.a
LIBFT = libft/libft.a

T = $(words $(PATH_OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

all: libs $(NAME)

$(NAME): $(LIBFT) $(LIBUI) $(OBJS)
	printf "\r\033[K""\r\033[K""\033[32m[GUI] \033[0m""Compiling""\n"
	$(COMPILE) $(PATH_OBJ) -o $(NAME) $(INCLUDES) $(LIBS)
	sh addIcon.sh
	printf "\033[1A\r\033[K""\r\033[K""\033[32m[GUI] \033[0m""Ready""\n"

%.o: %.c
	mkdir -p $(OPATH)
	printf "%-60b\r" "\033[32m[GUI] $(ECHO)\033[0 mCompiling $@"
	$(COMPILE) $(INCLUDES) -c $< -o $(OPATH)$@

$(DPATH)%.d: %.c
	mkdir -p $(DPATH)
	$(COMPILE) $(INCLUDES) -MT $(@:$(DPATH)%.d=%.o) -MM $^ > $@

libs:
	make -s -C libft -j3
	make -s -C libui

clean:
	rm -rf obj
	make -s -C libft fclean
	make -s -C libui fclean

fclean: clean dclean
	rm -rf $(NAME)

dclean:
	rm -rf .depends

re: fclean all

hardclean: fclean
	make -s -C libui hardclean

hardre: hardclean all

norm:
	printf "\033[32mC files:\033[0m\n"
	norminette $(shell find src -regex ".\{1,200\}\.c" | xargs)
	printf "\033[32mH files:\033[0m\n"
	norminette $(shell find includes -regex ".\{1,200\}\.h" | xargs)

normft:
	printf "\033[32m[LIBFT]\033[0m Norm:\n"
	make -s -C libft norm

normui:
	printf "\n\n\033[32m[LIBUI]\033[0m Norm:\n"
	make -s -C libui norm

normall:
	clear
	make -s normft
	make -s normui
	printf "\n\n\033[32m[GUIMP]\033[0m Norm:\n"
	make -s norm

.PHONY: re libs fclean hardre hardclean clean all
.SILENT: all libs clean fclean re hardclean hardre $(OBJS) $(NAME) norm normft normui normall $(DPDS) dclean

-include $(DPDS)
