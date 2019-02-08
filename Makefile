# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 21:34:09 by nnaumenk          #+#    #+#              #
#    Updated: 2019/02/05 20:06:37 by nnaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ssl

HEADER		=	ft_ssl.h

CFILES		=	ft_ssl_md5/md5/md5_1.c					\
				ft_ssl_md5/md5/md5_2.c					\
				ft_ssl_md5/sha1/sha1_1.c				\
				ft_ssl_md5/sha1/sha1_2.c				\
				ft_ssl_md5/sha256/sha256_1.c			\
				ft_ssl_md5/sha256/sha256_2.c			\
				ft_ssl_md5/sha512/sha512_1.c			\
				ft_ssl_md5/sha512/sha512_2.c			\
				ft_ssl_md5/whirlpool/whirlpool_1.c		\
				ft_ssl_md5/whirlpool/whirlpool_2.c		\
				ft_ssl_md5/md5_make_output.c			\
				ft_ssl_md5/md5_flags.c					\
				ft_ssl_md5/message_digest_alg.c			\
														\
				ft_ssl_des/pbkdf/hmac.c					\
				ft_ssl_des/pbkdf/pbkdf2.c				\
				ft_ssl_des/pbkdf/evp.c					\
				ft_ssl_des/base64/base64_encode.c		\
				ft_ssl_des/base64/base64_decode.c		\
				ft_ssl_des/base64/base64_flags.c		\
				ft_ssl_des/des/des_encrypt.c			\
				ft_ssl_des/des/des_decrypt.c			\
				ft_ssl_des/des/des_1.c					\
				ft_ssl_des/des/des_2.c					\
				ft_ssl_des/des/des_3.c					\
				ft_ssl_des/des/des3_algors.c			\
				ft_ssl_des/des/des3_algors_2.c			\
				ft_ssl_des/des/des_algors.c				\
				ft_ssl_des/des/des_algors_2.c			\
				ft_ssl_des/des/des_flags.c				\
				ft_ssl_des/des/des_flags_2.c			\
				ft_ssl_des/des/des_flags_decrypt.c		\
				ft_ssl_des/des/des_flags_encrypt.c		\
				ft_ssl_des/check_flags_1.c				\
				ft_ssl_des/check_flags_2.c				\
				ft_ssl_des/cipher_alg.c					\
				ft_ssl_des/cipher_alg_2.c				\
				ft_ssl_des/cipher_alg_3.c				\
														\
				ft_ssl_rsa/arithmetic/ft_memadd.c		\
				ft_ssl_rsa/arithmetic/ft_memsub.c		\
				ft_ssl_rsa/arithmetic/ft_mem_increment.c\
				ft_ssl_rsa/arithmetic/ft_mem_decrement.c\
				ft_ssl_rsa/arithmetic/ft_memmul.c		\
				ft_ssl_rsa/arithmetic/ft_memdiv.c		\
				ft_ssl_rsa/arithmetic/ft_memmul_by_2.c	\
				ft_ssl_rsa/arithmetic/ft_memdiv_by_2.c	\
														\
				ft_ssl_rsa/asn1/asn1_encode.c			\
				ft_ssl_rsa/asn1/asn1_decode.c			\
														\
				ft_ssl_rsa/flag_manager/flag_rand.c		\
				ft_ssl_rsa/flag_manager/flag_check.c	\
				ft_ssl_rsa/flag_manager/flag_des.c		\
				ft_ssl_rsa/flag_manager/flag_i.c		\
				ft_ssl_rsa/flag_manager/flag_in.c		\
				ft_ssl_rsa/flag_manager/flag_inform.c	\
				ft_ssl_rsa/flag_manager/flag_modulus.c	\
				ft_ssl_rsa/flag_manager/flag_noout.c	\
				ft_ssl_rsa/flag_manager/flag_o.c		\
				ft_ssl_rsa/flag_manager/flag_out.c		\
				ft_ssl_rsa/flag_manager/flag_outform.c	\
				ft_ssl_rsa/flag_manager/flag_passin.c	\
				ft_ssl_rsa/flag_manager/flag_passout.c	\
				ft_ssl_rsa/flag_manager/flag_pubin.c	\
				ft_ssl_rsa/flag_manager/flag_pubout.c	\
				ft_ssl_rsa/flag_manager/flag_text.c		\
				ft_ssl_rsa/flag_manager/flag_inkey.c	\
				ft_ssl_rsa/flag_manager/flag_encrypt.c	\
				ft_ssl_rsa/flag_manager/flag_decrypt.c	\
				ft_ssl_rsa/flag_manager/flag_hexdump.c	\
														\
				ft_ssl_rsa/rsa/rsa.c					\
				ft_ssl_rsa/rsa/rsa_flags.c				\
														\
				ft_ssl_rsa/genrsa/genrsa_flags.c		\
														\
				ft_ssl_rsa/rsautl/rsautl_flags.c		\
														\
				ft_ssl_rsa/print_big_int.c				\
				ft_ssl_rsa/standart_alg.c				\
														\
				hex_ascii.c								\
				read.c									\
				main.c									\

OFILES		=	$(CFILES:.c=.o)

CC			=	gcc

FLAGS		= 	-O2 -Wall -Wextra -Werror

LIBFT		=	libft/libft.a

all: 		
			make -C libft
			make $(NAME)

$(NAME): 	$(OFILES)
			@echo "\033[32mCreating $(NAME) ...\033[0m"
			@$(CC) $(OFILES) -o $(NAME) $(LIBFT)
			@echo "\033[32m$(NAME) was succesfully created!\033[0m\n"

%.o: 		%.c $(HEADER) $(LIBFT)
			@$(CC) -c $(FLAGS) $< -o $@

clean:
			@echo "\033[31mRemoving .o files of $(NAME) ...\033[0m"
			@/bin/rm -f $(OFILES)
			@echo "\033[31mSuccesfully removed!\033[0m\n"
			@make clean -C libft

fclean: 	clean
			@echo "\033[31mRemoving $(NAME) ...\033[0m"
			@/bin/rm -f $(NAME)
			@echo "\033[31mSuccesfully removed!\033[0m\n"
			@make fclean -C libft

re:			fclean all

.SILENT: