# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 16:21:42 by alerandy          #+#    #+#              #
#    Updated: 2019/05/08 23:51:43 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = png_parser
include ./make.dep

SRCS += main_test.c
INCLUDES += ../../../libft/includes/ ../../includes/ ../../SDL2-2.0.9/include/
INCLUDES:=$(addprefix -I, $(INCLUDES))
LIBS = -L../../../libft/ -lft

all:
	@gcc -g3 $(INCLUDES) $(SRCS) -o $(NAME) $(LIBS)
