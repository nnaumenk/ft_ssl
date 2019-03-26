# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 21:34:09 by nnaumenk          #+#    #+#              #
#    Updated: 2019/03/26 18:39:43 by nnaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ssl

HEADER		=	ft_ssl.h

CFILES		=	ft_ssl_md5/md5/md5_1.c									\
				ft_ssl_md5/md5/md5_2.c									\
				ft_ssl_md5/sha1/sha1_1.c								\
				ft_ssl_md5/sha1/sha1_2.c								\
				ft_ssl_md5/sha256/sha256_1.c							\
				ft_ssl_md5/sha256/sha256_2.c							\
				ft_ssl_md5/sha512/sha512_1.c							\
				ft_ssl_md5/sha512/sha512_2.c							\
				ft_ssl_md5/whirlpool/whirlpool_1.c						\
				ft_ssl_md5/whirlpool/whirlpool_2.c						\
				ft_ssl_md5/md5_make_output.c							\
				ft_ssl_md5/md5_flags.c									\
				ft_ssl_md5/message_digest_alg.c							\
																		\
				ft_ssl_des/pbkdf/hmac.c									\
				ft_ssl_des/pbkdf/pbkdf2.c								\
				ft_ssl_des/pbkdf/evp.c									\
				ft_ssl_des/base64/base64_encode.c						\
				ft_ssl_des/base64/base64_decode.c						\
				ft_ssl_des/base64/base64_flags.c						\
				ft_ssl_des/des/des_encrypt.c							\
				ft_ssl_des/des/des_decrypt.c							\
				ft_ssl_des/des/des_1.c									\
				ft_ssl_des/des/des_2.c									\
				ft_ssl_des/des/des_3.c									\
				ft_ssl_des/des/des3_algors.c							\
				ft_ssl_des/des/des3_algors_2.c							\
				ft_ssl_des/des/des_algors.c								\
				ft_ssl_des/des/des_algors_2.c							\
				ft_ssl_des/des/des_flags.c								\
				ft_ssl_des/des/des_flags_2.c							\
				ft_ssl_des/des/des_flags_decrypt.c						\
				ft_ssl_des/des/des_flags_encrypt.c						\
				ft_ssl_des/check_flags_1.c								\
				ft_ssl_des/check_flags_2.c								\
				ft_ssl_des/cipher_alg.c									\
				ft_ssl_des/cipher_alg_2.c								\
				ft_ssl_des/cipher_alg_3.c								\
																		\
				ft_ssl_rsa/asn1_decode/asn1_decode_private_key.c		\
				ft_ssl_rsa/asn1_decode/asn1_decode_public_key.c			\
				ft_ssl_rsa/asn1_decode/ft_asn1_check_size.c				\
				ft_ssl_rsa/asn1_decode/ft_asn1_get_size.c				\
				ft_ssl_rsa/asn1_decode/ft_asn1_get_value.c				\
																		\
				ft_ssl_rsa/asn1_encode/asn1_encode_private_key.c		\
				ft_ssl_rsa/asn1_encode/asn1_encode_public_key.c			\
				ft_ssl_rsa/asn1_encode/ft_asn1_get_byte_number.c		\
				ft_ssl_rsa/asn1_encode/ft_asn1_set_size.c				\
				ft_ssl_rsa/asn1_encode/ft_asn1_set_value.c				\
				ft_ssl_rsa/asn1_encode/ft_asn1_set_version.c			\
																		\
				ft_ssl_rsa/bigint/ft_bigint_dup.c						\
				ft_ssl_rsa/bigint/ft_bigint_dup_value.c					\
				ft_ssl_rsa/bigint/ft_bigint_del.c						\
				ft_ssl_rsa/bigint/ft_bigint_print.c						\
				ft_ssl_rsa/bigint/ft_bigint_isnull.c					\
				ft_ssl_rsa/bigint/ft_bigint_isvalue.c					\
				ft_ssl_rsa/bigint/ft_bigint_smaller.c					\
				ft_ssl_rsa/bigint/ft_bigint_bigger.c					\
				ft_ssl_rsa/bigint/ft_bigint_equ_bigger.c				\
				ft_ssl_rsa/bigint/ft_bigint_equal.c						\
				ft_ssl_rsa/bigint/ft_bigint_add.c						\
				ft_ssl_rsa/bigint/ft_bigint_sub.c						\
				ft_ssl_rsa/bigint/ft_bigint_increment.c					\
				ft_ssl_rsa/bigint/ft_bigint_decrement.c					\
				ft_ssl_rsa/bigint/ft_bigint_mul.c						\
				ft_ssl_rsa/bigint/ft_bigint_div.c						\
				ft_ssl_rsa/bigint/ft_bigint_div_safe.c					\
				ft_ssl_rsa/bigint/ft_bigint_shl.c						\
				ft_ssl_rsa/bigint/ft_bigint_shl_overflow.c				\
				ft_ssl_rsa/bigint/ft_bigint_shr.c						\
				ft_ssl_rsa/bigint/ft_bigint_normalize.c					\
																		\
				ft_ssl_rsa/flag_manager/flag_rand.c						\
				ft_ssl_rsa/flag_manager/flag_check_2.c					\
				ft_ssl_rsa/flag_manager/flag_check.c					\
				ft_ssl_rsa/flag_manager/flag_des.c						\
				ft_ssl_rsa/flag_manager/flag_in.c						\
				ft_ssl_rsa/flag_manager/flag_inform.c					\
				ft_ssl_rsa/flag_manager/flag_modulus.c					\
				ft_ssl_rsa/flag_manager/flag_noout.c					\
				ft_ssl_rsa/flag_manager/flag_out.c						\
				ft_ssl_rsa/flag_manager/flag_outform.c					\
				ft_ssl_rsa/flag_manager/flag_passin.c					\
				ft_ssl_rsa/flag_manager/flag_passout.c					\
				ft_ssl_rsa/flag_manager/flag_pubin.c					\
				ft_ssl_rsa/flag_manager/flag_pubout.c					\
				ft_ssl_rsa/flag_manager/flag_text.c						\
				ft_ssl_rsa/flag_manager/flag_inkey.c					\
				ft_ssl_rsa/flag_manager/flag_encrypt.c					\
				ft_ssl_rsa/flag_manager/flag_decrypt.c					\
				ft_ssl_rsa/flag_manager/flag_hexdump.c					\
				ft_ssl_rsa/flag_manager/flag_exp_3_value.c				\
				ft_ssl_rsa/flag_manager/flag_exp_f4_value.c				\
																		\
				ft_ssl_rsa/informat/ft_der_inform_private_key.c			\
				ft_ssl_rsa/informat/ft_der_inform_public_key.c			\
				ft_ssl_rsa/informat/ft_pem_des_inform_private_key.c		\
				ft_ssl_rsa/informat/ft_pem_inform_private_key.c			\
				ft_ssl_rsa/informat/ft_pem_inform_public_key.c			\
																		\
				ft_ssl_rsa/outformat/ft_der_outform_private_key.c		\
				ft_ssl_rsa/outformat/ft_der_outform_public_key.c		\
				ft_ssl_rsa/outformat/ft_pem_des_outform_private_key.c	\
				ft_ssl_rsa/outformat/ft_pem_outform_private_key.c		\
				ft_ssl_rsa/outformat/ft_pem_outform_public_key.c		\
																		\
				ft_ssl_rsa/rsa/rsa.c									\
				ft_ssl_rsa/rsa/rsa_flags.c								\
																		\
				ft_ssl_rsa/genrsa/ft_make_exponent.c					\
				ft_ssl_rsa/genrsa/ft_make_primes.c						\
				ft_ssl_rsa/genrsa/ft_make_private_exponent.c			\
				ft_ssl_rsa/genrsa/ft_make_public_exponent.c				\
				ft_ssl_rsa/genrsa/genrsa.c								\
				ft_ssl_rsa/genrsa/genrsa_flags.c						\
																		\
				ft_ssl_rsa/rsautl/ft_rsa_make_decrypt.c					\
				ft_ssl_rsa/rsautl/ft_rsa_make_encrypt.c					\
				ft_ssl_rsa/rsautl/rsautl.c								\
				ft_ssl_rsa/rsautl/rsautl_flags.c						\
																		\
				ft_ssl_rsa/ft_find_prime_number.c						\
				ft_ssl_rsa/ft_is_composit_by_initial_sieve.c			\
				ft_ssl_rsa/ft_is_composit_by_miller_rabin.c				\
				ft_ssl_rsa/ft_mod_inverse.c								\
				ft_ssl_rsa/ft_euclid_gcd.c								\
				ft_ssl_rsa/ft_is_coprime.c								\
				ft_ssl_rsa/ft_pow_mod.c									\
				ft_ssl_rsa/ft_ssl_is_primary.c							\
				ft_ssl_rsa/ft_rsa_free_data.c							\
				ft_ssl_rsa/ft_normalize_input_rsa_values.c				\
				ft_ssl_rsa/ft_denormalize_input_rsa_values.c			\
																		\
				hex_ascii.c												\
				read.c													\
				main.c													\

OFILES		=	$(CFILES:.c=.o)

CC			=	gcc

FLAGS		= 	-O2# -Wall -Wextra -Werror

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