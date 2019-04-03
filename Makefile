# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:59:51 by alerandy          #+#    #+#              #
#    Updated: 2019/04/03 21:30:17 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRESS BAR | Made by Cpirlot
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

SDL2 = SDL2-2.0.9

$(SDL2):
	@echo 'Downloading SDL2'
	@curl https://www.libsdl.org/release/SDL2-2.0.9.tar.gz > SDL2.tar.gz
	@tar -xf SDL2.tar.gz
	@rm -rf SDL2.tar.gz
	@printf '\033[2K\033[1A\033[2K\033[1A\033[2K\033[1A\033[2K\033[1A'
	@echo 'SDL2 Ready'

all: $(SDL2)

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf obj
	@rm -rf $(SDL2)

re: fclean all