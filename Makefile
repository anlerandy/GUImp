# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:59:51 by alerandy          #+#    #+#              #
#    Updated: 2019/04/03 21:47:04 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRESS BAR | Original author Cpirlot
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
	@printf '\033[K\033[1A\033[K\033[1A\033[K\033[1A\033[K\033[1A\r'
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