# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 12:38:11 by alerandy          #+#    #+#              #
#    Updated: 2020/09/10 13:59:08 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME = ft_putchar.c ft_putstr.c ft_putcharerr.c ft_putstrerr.c ft_memset.c \
		   ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_strlen.c \
		   ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		   ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
		   ft_strstr.c ft_strncmp.c ft_strcmp.c ft_atoi.c ft_isalnum.c \
		   ft_isdigit.c ft_isalpha.c ft_isprint.c ft_isascii.c ft_tolower.c \
		   ft_toupper.c ft_memmove.c ft_isspace.c ft_memalloc.c ft_strclr.c \
		   ft_strdel.c ft_strnew.c ft_memdel.c ft_striter.c ft_strsub.c \
		   ft_strnequ.c ft_strmapi.c ft_strmap.c ft_striteri.c ft_strequ.c \
		   ft_strjoin.c ft_strtrim.c ft_putnbr.c ft_putendl.c ft_putnbr_fd.c \
		   ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strsplit.c \
		   ft_itoa.c ft_lstnew.c ft_lstmap.c ft_lstiter.c ft_lstdelone.c \
		   ft_lstdel.c ft_lstadd.c ft_hidenp.c ft_strcapitalize.c ft_strndup.c \
		   ft_isupper.c get_next_line.c ft_memdup.c ft_get_folder.c \
		   ft_free_folder.c \
		   ft_putnstr.c ft_putnendl.c ft_swap_integer.c ft_sortarray.c\
		   rb_apply_by_level.c rb_apply_infix.c rb_apply_prefix.c \
		   rb_apply_suffix.c rb_clear_tree.c rb_fix_black_node.c rb_insert.c \
		   rb_level_count.c rb_parenting.c rb_remove.c rb_rotation.c \
		   rb_search_infix.c rb_search_all.c rb_validate_tree.c \
		   vec_add.c vec_rot.c vec_init.c vec_mult_mat.c vec_mult.c vec_norm.c \
		   vec_print.c vec_free.c vec_scale.c vec_spe_mat.c vec_sub.c
NAME = libft.a
NAMESO = $(NAME:%.a=%.so)
FLAG = -Wall -Wextra -Werror -O2 -funroll-loops -g3
OBJ_NAME = $(SRC_NAME:.c=.o)
CC = clang $(FLAG)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

DPATH = .depends/
DPDS = $(addprefix $(DPATH), $(SRC_NAME:%.c=%.d))

# Updating the VPATH
VPATH = .:objects:$(shell find srcs -type d | tr '\n' ':'):./srcs

# PROGRESS BAR | Original author Cpirlot
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\r\033[K""\r\033[K""\033[32m[LIBFT]\033[0m Ready\n"

so : $(OBJ)
	@$(CC) -shared -o libft.so $(OBJ)

$(OBJ_PATH)%.o: %.c
	@printf "%-60b\r" "\033[32m[LIBFT] $(ECHO)\033[0m Compiling $@"
	@mkdir -p $(OBJ_PATH)
	@$(CC) -fpic -I./includes -o $@ -c $<

$(DPATH)%.d: %.c
	@mkdir -p $(DPATH)
	@$(CC) -fpic -I./includes -MT $(@:$(DPATH)%.d=$(OBJ_PATH)%.o) -MM $^ > $@

clean :
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;30m[LIBFT]\033[0m\033[0;37m Binaries cleaned\033[0m"

fclean : clean dclean
	@rm -f $(NAME)
	@rm -f $(NAMESO)
	@echo "\033[0;31m[LIBFT]\033[0m Deleted"

dclean:
	@rm -rf .depends

re : fclean $(NAME)

norm:
	@printf "\033[32mC files:\033[0m\n"
	@norminette $(shell find srcs -regex ".\{1,200\}\.c" | xargs) > .norm.tmp
	@grep "Error" -B 1 .norm.tmp || echo "\033[1;32mNo error found\033[0m\n"
	@rm .norm.tmp
	@printf "\033[32mH files:\033[0m\n"
	@norminette $(shell find includes -regex ".\{1,200\}\.h" | xargs) > .norm.tmp
	@grep "Error" -B 1 .norm.tmp || echo "\033[1;32mNo error found\033[0m\n"
	@rm .norm.tmp

norm-raw:
	@printf "\033[32mC files:\033[0m\n"
	@norminette $(shell find srcs -regex ".\{1,200\}\.c" | xargs)
	@printf "\033[32mH files:\033[0m\n"
	@norminette $(shell find includes -regex ".\{1,200\}\.h" | xargs)

.PHONY: re fclean clean all so

-include $(DPDS)
