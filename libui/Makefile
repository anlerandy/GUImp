# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 15:11:25 by alerandy          #+#    #+#              #
#    Updated: 2019/06/29 10:39:04 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libui.a
CFLAGS = -Wall -Werror -Wextra -g3
CC = clang
COMPILE=$(CC) $(CFLAGS)

# Get all dependances
include includes.dep

# Deal with Cross-Platform
ifeq ($(shell uname -s), Darwin)
    linksdl = -Wl,-rpath,./shared/lib
else
    linksdl = -Wl,-rpath,./shared/lib
endif

# Intisialize the main files
SDL2 = SDL2-2.0.9
SDL2LINK = https://www.libsdl.org/release/$(SDL2).tar.gz
SDL2CONF = ${shell pwd}/SDL/sdl2-config --prefix=${shell pwd}/SDL
FREETP = freetype-2.10.0
FREELINK = http://ftp.igh.cnrs.fr/pub/nongnu/freetype/${FREETP}.tar.gz
SDLTTF = SDL2_ttf-2.0.15
SDLTLINK = https://www.libsdl.org/projects/SDL_ttf/release/$(SDLTTF).tar.gz
INCLUDES += ./includes ./includes/privates ./shared/include/SDL2 ../libft/includes
LIBS = -L../libft -lft -L./shared/lib -lSDL2 -L./shared/lib/.libs -lSDL2_ttf
SRCS += ui_init_univers.c ui_quit_univers.c
INCLUDES:=$(addprefix -I, $(INCLUDES))

# Updating the VPATH
VPATH =.:obj:$(shell find src -type d | tr '\n' ':'):.depends

# Insert .o files
OBJS = $(SRCS:%.c=%.o)
OPATH = obj/
PATH_OBJ = $(addprefix $(OPATH), $(OBJS))

DPATH = .depends/
DPDS = $(addprefix $(DPATH), $(SRCS:%.c=%.d))

T = $(words $(PATH_OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

all: $(SDL2) $(SDLTTF) $(NAME)

$(SDL2):
	printf "\r\033[K""\033[32m[SDL2] \033[0m""Downloading""\n"
	curl $(SDL2LINK) > SDL2.tar.gz
	tar -xf SDL2.tar.gz
	rm -rf SDL2.tar.gz
	printf '\033[K\033[1A\033[K\033[1A\033[K\033[1A\033[K\033[1A'
	printf "\r\033[K""\r\033[K""\033[32m[SDL2] \033[0m""Configuring""\n"
	mkdir SDL && cd SDL && sh ../$(SDL2)/configure --prefix=${shell pwd}/shared > /dev/null 2> /dev/null
	printf "\033[1A\r\033[K""\r\033[K""\033[32m[SDL2] \033[0m""Installing""\n"
	make -C SDL > /dev/null 2> /dev/null
	mkdir -p shared shared/include
	cp -rfa ./SDL/build/.libs/ ./shared/lib/ \
	&& cp -rf ./$(SDL2)/include/ ./shared/include/SDL2/
	printf "\033[1A\r\033[K""\r\033[K""\033[32m[SDL2] \033[0m""Ready""\n"

$(FREETP):
	printf "\r\033[K""\033[32m[FREETYPE] \033[0m""Downloading""\n"
	curl -0 $(FREELINK) -o freetype2.tar.gz
	tar -xf freetype2.tar.gz
	rm -rf freetype2.tar.gz
	printf '\033[K\033[1A\033[K\033[1A\033[K\033[1A\033[K\033[1A'
	printf "\r\033[K""\r\033[K""\033[32m[FREETYPE] \033[0m""Configuring""\n"
	mkdir -p freetype2 && cd freetype2 && ../$(FREETP)/configure --prefix=${shell pwd}/shared > /dev/null 2> /dev/null
	printf "\033[1A\r\033[K""\r\033[K""\033[32m[FREETYPE] \033[0m""Installing""\n"
	make -C freetype2 -j > /dev/null 2> /dev/null
	mkdir -p shared shared/include
	cp -rf ./freetype2/.libs/ ./shared/lib/ \
	&& cp -fR ./$(FREETP)/include/ ./shared/include/freetype2/
	printf "\033[1A\r\033[K""\r\033[K""\033[32m[FREETYPE] \033[0m""Ready""\n"

$(SDLTTF): $(SDL2) $(FREETP)
	printf "\r\033[K""\033[32m[SDLTTF] \033[0m""Downloading""\n"
	curl $(SDLTLINK) > SDLTTF.tar.gz
	tar -xf SDLTTF.tar.gz
	rm -rf SDLTTF.tar.gz
	printf '\033[K\033[1A\033[K\033[1A\033[K\033[1A\033[K\033[1A'
	printf "\r\033[K""\r\033[K""\033[32m[SDLTTF] \033[0m""Configuring""\n"
	mkdir -p SDLTTF && cd SDLTTF \
	&& export LD_LIBRARY_PATH="${shell pwd}/shared/lib" \
	&& SDL2_CONFIG="${SDL2CONF}" \
	FT2_CONFIG="$(shell pwd)/freetype2/" \
	FT2_CFLAGS="-I$(shell pwd)/shared/include/freetype2" \
	FT2_LIBS="-L$(shell pwd)/shared/lib/ -lfreetype" \
	PKG_CONFIG_PATH=${shell pwd}/SDL/:$(shell pwd)/freetype2/ \
	sh ../$(SDLTTF)/configure --prefix=${shell pwd}/shared > /dev/null 2> /dev/null
	printf "\033[1A\r\033[K""\r\033[K""\033[32m[SDLTTF] \033[0m""Installing""\n"
	make -C SDLTTF -j > /dev/null 2> /dev/null
	mkdir -p shared shared/include
	cp -rf ./SDLTTF/.libs/ ./shared/lib/ \
	&& cp -rf ./$(SDLTTF)/SDL_ttf.h ./shared/include/SDL2/SDL_ttf.h
	printf "\033[1A\r\033[K""\r\033[K""\033[32m[SDLTTF] \033[0m""Ready""\n"

$(NAME): $(OBJS)
	ar rc $(NAME) $(PATH_OBJ)
	ranlib $(NAME)
	printf "\r\033[K""\r\033[K""\033[32m[LIBUI]\033[0m Ready\n"

%.o: %.c
	mkdir -p $(OPATH)
	printf "%-60b\r" "\033[32m[LIBUI] $(ECHO)\033[0m Compiling $@"
	$(COMPILE) $(INCLUDES) -c $< -o $(OPATH)$@

$(DPATH)%.d: %.c $(SDL2)
	mkdir -p $(DPATH)
	$(COMPILE) $(INCLUDES) -MT $(@:$(DPATH)%.d=%.o) -MM $^ > $@ 2> /dev/null

clean:
	rm -rf obj
	echo "\033[1;30m[LIBUI]\033[0m\033[0;37m Binaries cleaned\033[0m"

fclean: clean dclean
	rm -rf $(NAME)
	echo "\033[0;31m[LIBUI]\033[0m Deleted"

hardclean: fclean
	rm -rf $(SDL2) SDL
	echo "\033[0;31m[SDL2]\033[0m Deleted"
	rm -rf $(SDLTTF) SDLTTF
	echo "\033[0;31m[SDLTTF]\033[0m Deleted"
	rm -rf $(FREETP) freetype2
	echo "\033[0;31m[FREETYPE]\033[0m Deleted"
	rm -rf shared

hardre: hardclean all

dclean:
	rm -rf .depends

re: fclean all

norm:
	printf "\033[32mC files:\033[0m\n"
	norminette $(shell find src -regex ".\{1,200\}\.c" | xargs) > .norm.tmp
	grep "Error" -B 1 .norm.tmp || echo "\033[1;32mNo error found\033[0m\n"
	rm .norm.tmp
	printf "\033[32mH files:\033[0m\n"
	norminette $(shell find includes -regex ".\{1,200\}\.h" | xargs) > .norm.tmp
	grep "Error" -B 1 .norm.tmp || echo "\033[1;32mNo error found\033[0m\n"
	rm .norm.tmp

norm-raw:
	printf "\033[32mC files:\033[0m\n"
	norminette $(shell find src -regex ".\{1,200\}\.c" | xargs)
	printf "\033[32mH files:\033[0m\n"
	norminette $(shell find includes -regex ".\{1,200\}\.h" | xargs)

.PHONY: re fclean hardre hardclean clean all
.SILENT: $(SDL2) all $(NAME) clean fclean re hardclean hardre $(OBJS) norm $(DPDS) dclean norm-raw

-include $(DPDS)
