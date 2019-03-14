# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 12:25:41 by nnaumenk          #+#    #+#              #
#    Updated: 2019/02/26 18:49:17 by nnaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

HEADER	=	libft.h

CFILES	=	ft_free_matrix.c				\
			ft_bzero.c						\
			ft_memjoin.c					\
			ft_memjoin_del.c				\
			ft_mem_joiner.c					\
			ft_malloc_str.c					\
			ft_memalloc.c					\
			ft_memcpy.c						\
			ft_memdel.c						\
			ft_memset.c						\
			ft_memrev.c						\
			ft_memswap.c					\
			ft_memdup.c						\
			ft_xor_mem.c					\
			ft_xor_mem_value.c				\
			ft_memequ.c						\
			ft_search_pos_int.c				\
			ft_str_parse.c					\
			ft_strchr.c						\
			ft_strcpy.c						\
			ft_strncpy.c					\
			ft_strdel.c						\
			ft_strdup.c						\
			ft_strjoin.c					\
			ft_strlen.c						\
			ft_strnew.c						\
			ft_strequ.c						\
			ft_strtrim.c					\
			ft_strsplit.c					\
			ft_print_fd.c					\
			ft_generate_random.c			\
			ft_generate_urandom.c			\
			ft_get_random_in_range.c		\
			ft_mem_to_bits.c				\
			ft_bits_to_mem.c				\
			get_next_line.c					\
											\
			ft_printf/ft_printf.c			\
			ft_printf/ft_str_bonus.c		\
			ft_printf/ft_attribute.c		\
			ft_printf/ft_join.c				\
			ft_printf/ft_str.c				\
			ft_printf/ft_str_2.c			\
			ft_printf/ft_str_3.c			\
			ft_printf/ft_float.c			\
			ft_printf/ft_float_2.c			\
			ft_printf/ft_float_check.c		\
			ft_printf/ft_float_round.c		\
			ft_printf/ft_atoa.c				\
			ft_printf/ft_atoa_2.c			\
			ft_printf/ft_etoa.c				\
			ft_printf/ft_gtoa.c				\
			ft_printf/ft_gtoa_precision.c	\
			ft_printf/ft_ftoa.c				\
			ft_printf/ft_itoa.c				\
			ft_printf/ft_lib_additional.c	\
			ft_printf/ft_lib_additional_2.c	\
			ft_printf/ft_specificator.c		\
			ft_printf/ft_width.c			\
			ft_printf/ft_mod.c				\
			ft_printf/ft_str_flags.c		\
			ft_printf/ft_str_flag_comma.c	\
			ft_printf/ft_unicode.c			\
			ft_printf/ft_str_mul_div.c		\

OFILES	=	$(CFILES:.c=.o)

FLAGS	= 	-O2 #-Wall -Wextra -Werror

CC		=	gcc

all: 		$(NAME)
			
$(NAME): 	$(OFILES)
			@echo "\033[32mCreating $(NAME) ...\033[0m"
			@ar rcs $(NAME) $(OFILES)
			@echo "\033[32m$(NAME) was succesfully created!\033[0m\n"

%.o: %.c $(HEADER)
			@$(CC) -c $(FLAGS) $< -o $@

clean:
			@echo "\033[31mRemoving .o files of $(NAME) ...\033[0m"
			@/bin/rm -f $(OFILES)
			@echo "\033[31mSuccesfully removed!\033[0m\n"

fclean: 	clean
			@echo "\033[31mRemoving $(NAME) ...\033[0m"
			@/bin/rm -f $(NAME)
			@echo "\033[31mSuccesfully removed!\033[0m\n"

re:			fclean all

.SILENT: