# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 16:21:42 by alerandy          #+#    #+#              #
#    Updated: 2019/04/26 16:57:08 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bmp_parser
include ./make.dep

SRCS += main_test.c
INCLUDES += ../../../libft/includes/
INCLUDES:=$(addprefix -I, $(INCLUDES))
LIBS = -L../../../libft/ -lft

all:
	@gcc $(INCLUDES) $(SRCS) -o $(NAME) $(LIBS)
