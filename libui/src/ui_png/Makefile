# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 16:21:42 by alerandy          #+#    #+#              #
#    Updated: 2019/06/30 17:51:30 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = png_parser
include ./make.dep

SRCS += main_test.c ../ui_bmp/ui_pixtohex.c
INCLUDES += ../../../libft/includes/ ../../includes/ ../../includes/privates ../../SDL2-2.0.9/include/
INCLUDES:=$(addprefix -I, $(INCLUDES))
LIBS =  -lz -L../../../libft/ -lft

all:
	@gcc -g3 $(INCLUDES) $(SRCS) -o $(NAME) $(LIBS)

norm:
	norminette ./*.c
