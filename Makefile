# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:59:51 by alerandy          #+#    #+#              #
#    Updated: 2019/04/04 09:33:37 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Get all dependances
include includes.dep

# Intisialize the main files
SDL2 = SDL2-2.0.9
SDLflags = $(shell ./SDL/sdl2-config --cflags --libs | xargs)
INCLUDES += ./ 
SRCS += src/main.c 
INCLUDES := $(addprefix -I, $(INCLUDES))
FRAMWEWORK = $(SDLflags)

# Deal with Cross-Platform
ifeq ($(shell uname -s), Darwin)
    libgl = -framework OpenGL -framework GLUT
else
    libgl = -lGL -lglut -framework
endif

# Insert les .o dans un seul dossier obj/
OBJS = $(SRCS:%.c=%.o)
OPATH = obj/
PATH_OBJ = $(addprefix $(OPATH), $(OBJS))

# PROGRESS BAR | Original author Cpirlot
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

$(SDL2):
	@echo 'Downloading SDL2'
	@curl https://www.libsdl.org/release/SDL2-2.0.9.tar.gz > SDL2.tar.gz
	@tar -xf SDL2.tar.gz
	@rm -rf SDL2.tar.gz
	@printf '\033[K\033[1A\033[K\033[1A\033[K\033[1A\033[K\033[1A'
	@mkdir SDL && cd SDL && sh ../$(SDL2)/autogen.sh && sh ../$(SDL2)/configure
	@make -C SDL -j
	@echo 'SDL2 Ready      '

libs:
	@make -C libft -j

all: $(SDL2) libs

clean:
	@rm -rf $(NAME)
	@make -C libft clean

fclean: clean
	@rm -rf obj
	@rm -rf $(SDL2)
	@rm -rf libft/libft.a

re: fclean all