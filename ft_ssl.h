/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:12:53 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:00:58 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define USE(x) (void)(x);

# define IS_DOWN_HEX(x) (x >= 'a' && x <= 'f' ? 1 : 0)
# define IS_UP_HEX(x) (x >= 'A' && x <= 'F' ? 1 : 0)
# define IS_NUMBER(x) (x >= '0' && x <= '9' ? 1 : 0)

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>/////ubrat
# include <math.h>///ubrat

# include "ft_ssl_md5/ft_ssl_md5.h"
# include "ft_ssl_des/ft_ssl_des.h"
# include "ft_ssl_rsa/ft_ssl_rsa.h"	
# include "main_struct.h"

int		ft_asn1_check_size(char **ptr, char tag, size_t *len);
int		ft_asn1_get_value(t_bigint *a, char tag, char **ptr, size_t *len);
int		ft_asn1_get_size(size_t *size, char **ptr, size_t *len);
int		ft_asn1_decode_public_key(t_rsa *rsa);
int		ft_asn1_decode_private_key(t_rsa *rsa);	

int		ft_asn1_get_byte_number(size_t len);
void	ft_asn1_set_version(char **ptr);
void	ft_asn1_set_value(t_bigint a, char tag, char **ptr);
void	ft_asn1_set_size(size_t size, char tag, char **ptr);
int		ft_asn1_encode_public_key(t_rsa *rsa);
int		ft_asn1_encode_private_key(t_rsa *rsa);

int		ft_pem_inform_private_key(t_rsa *rsa);
int		ft_pem_inform_public_key(t_rsa *rsa);
int		ft_pem_des_inform_private_key(t_rsa *rsa);
int		ft_der_inform_private_key(t_rsa *rsa);
int		ft_der_inform_public_key(t_rsa *rsa);

int		ft_der_outform_private_key(t_rsa *rsa);
int		ft_der_outform_public_key(t_rsa *rsa);
int		ft_pem_des_outform_private_key(t_rsa *rsa);
int		ft_pem_outform_private_key(t_rsa *rsa);
int		ft_pem_outform_public_key(t_rsa *rsa);

void	ft_find_prime_number(t_bigint *prime, t_bigint *public_exp);
int		ft_is_composit_by_initial_sieve(short *mod_array_2048);
int		ft_is_composit_by_miller_rabin(t_bigint *prime, unsigned probability);
int		ft_mod_inverse(t_bigint *inverse, t_bigint *a, t_bigint *mod);
int		ft_ssl_is_primary(__uint64_t number, float probability);
void	ft_euclid_gcd(t_bigint *gcd, t_bigint *a, t_bigint *b);
int		ft_is_coprime(t_bigint *a, t_bigint *b);
void	ft_rsa_free_data(t_rsa_data *data);
void	ft_normalize_input_rsa_values(t_rsa *rsa);

int		ft_make_genrsa_data(t_rsa *rsa);

size_t	ft_pow_mod_int(size_t num, size_t pow, size_t mod);
void	ft_pow_mod(t_bigint *r, t_bigint *num, t_bigint *pow, t_bigint *mod);

int		ft_rsa_check_flag_rand(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_inform(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_outform(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_i(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_in(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_passin(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_o(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_out(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_passout(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_des(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_text(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_noout(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_modulus(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_check(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_pubin(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_pubout(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_inkey(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_encrypt(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_decrypt(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_flag_hexdump(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_exp_3_value(int *i, int ac, char **av, t_rsa_flag *flag);
int		ft_rsa_check_exp_f4_value(int *i, int ac, char **av, t_rsa_flag *flag);



int		ft_rsa_make_flag_in(t_rsa *rsa);
int		ft_rsa_make_flag_out(t_rsa *rsa);
int		ft_rsa_make_flag_rand(int *fd, char *file);
int		ft_rsa_make_flag_pubin(t_rsa *rsa);
int		ft_rsa_make_flag_pubout(t_rsa *rsa);
int		ft_rsa_make_flag_text(t_rsa *rsa);
int		ft_rsa_make_flag_modulus(t_rsa *rsa);
int		ft_rsa_make_flag_check(t_rsa *rsa);
int		ft_rsa_make_flag_des(t_rsa *rsa);
int		ft_rsa_make_flag_inform(t_rsa *rsa);
int		ft_rsa_make_flag_outform(t_rsa *rsa);
int		ft_rsa_make_flag_passin(t_rsa *rsa);
int		ft_rsa_make_flag_passout(t_rsa *rsa);



void	ft_rsa_flags(void *my, int ac, char **av);
void	ft_genrsa_flags(void *my, int ac, char **av);
void	ft_rsautl_flags(void *my, int ac, char **av);	

void	ft_md5_output(t_alg *my, t_md5_flags *flags, char *file);
void	ft_md5_output_flag_p(t_alg *my);
void	ft_md5_output_noflags(t_alg *my);
void	ft_md5_output_flag_s(t_alg *my, t_md5_flags *flags, char *text);

int		ft_md5_check_flag(int *i, int ac, char **av, t_md5_flags *flags);
void	ft_md5_search_files(t_alg *my, t_md5_flags *flags, int ac, char **av);
void	ft_md5_search_flags(t_alg *my, t_md5_flags *flags, int ac, char **av);
void	ft_md5_flags(void *my, int ac, char **av);

void	ft_md5_add_len(char *text, size_t len);
char	*ft_md5_make_alignment(char *text, size_t *len);
void	ft_md5_start_values(uint32_t *hash);
void	ft_md5_round1(uint32_t *h, uint32_t *p);
void	ft_md5_round2(uint32_t *h, uint32_t *p);
void	ft_md5_round3(uint32_t *h, uint32_t *p);
void	ft_md5_round4(uint32_t *h, uint32_t *p);
void	ft_md5_algor(uint32_t *hash, char *text, size_t len);

void	ft_sha1_add_len(char *text, size_t len);
char	*ft_sha1_make_alignment(char *text, size_t *len);
void	ft_sha1_make_w_arr(uint32_t *w, char *block);
void	ft_sha1_start_values(uint32_t *global);
void	ft_sha1_round_help(uint32_t *buf, uint32_t temp, uint32_t w);
void	ft_sha1_round(uint32_t *buf, uint32_t *w);
void	ft_sha1_algor(uint32_t *hash, char *str, size_t len);

void	ft_sha256_add_len(char *text, size_t len);
char	*ft_sha256_make_alignment(char *text, size_t *len);
void	ft_sha256_make_w_arr(uint32_t *w, char *block);
void	ft_sha256_start_values(uint32_t *global);
void	ft_sha256_round(uint32_t *buf, uint32_t *w);
void	ft_sha256_algor(uint32_t *hash, char *str, size_t len);

char	*ft_sha512_make_alignment(char *text, size_t *len);
void	ft_sha512_add_len(char *text, size_t len);
void	ft_sha512_start_values(uint64_t *hash);
void	ft_sha512_make_w_arr(uint64_t *w, char *block);
void	ft_sha512_round(uint64_t *buf, uint64_t *w);
void	ft_sha512_algor(uint64_t *hash, char *text, size_t len);

char	*ft_whirlpool_make_alignment(char *text, size_t *len);
void	ft_whirlpool_add_len(char *text, size_t len);
void	ft_whirlpool_round_function(uint8_t *message, uint8_t *key);
void	ft_whirlpool_algor(uint8_t *hash, char *text, size_t len);
void	ft_whirlpool_sub_bytes(uint8_t *matrix);
void	ft_whirlpool_shift_columns(uint8_t *matrix);
uint8_t	ft_whirlpool_mul(uint8_t a, uint8_t b);
void	ft_whirlpool_mix_rows(uint8_t *matrix);

char	*ft_evp(char *pass, uint8_t *salt, size_t len);
char	*ft_hmac(char *key, char *msg, size_t key_len, size_t msg_len);
char	*ft_pbkdf2(char *pass, uint8_t *salt, size_t iter, size_t len);

int		ft_b64_process_flags(t_alg *my, t_des *flags);
void	ft_b64_search_flags(t_alg *my, t_des *data, int argc, char **argv);
void	ft_b64_flags(void *my, int argc, char **argv);

void	ft_b64_from_base(char *buf, size_t *len);
void	ft_b64_decode_line(char *str, char *line, size_t *len, size_t blocks);
void	*ft_memchr(void *mem, char elem, size_t num);
char	*ft_b64_decode_algor(char *buf, size_t *len);

char	*ft_b64_decode(char *buf, size_t *len);
void	ft_b64_to_base(char *str, size_t len);
char	*ft_b64_encode_append(char *new_str, size_t j, size_t new_len);
char	*ft_b64_encode_algor(unsigned char *buf, size_t len, size_t new_len);
char	*ft_b64_encode(char *buf, size_t *len);

int		ft_check_flag_i(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_o(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_e(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_d(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_a(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_k(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_v(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_p(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_s(int *i, int ac, char **av, t_des *data);
int		ft_check_flag_pbkdf2(int *i, int ac, char **av, t_des *data);

int		ft_des_read_password(t_des *data);
int		ft_des_read_password_verify(t_des *data);
int		ft_des_decrypt_process_salt(t_des *data);
int		ft_des_decrypt_if_password(t_des *data);
int		ft_des_decrypt_if_key(t_des *data);
int		ft_des_decrypt_process_flags(t_des *data);
int		ft_des_encrypt_process_salt(t_des *data);
int		ft_des_encrypt_if_password(t_des *data);
int		ft_des_encrypt_if_key(t_des *data);
int		ft_des_encrypt_process_flags(t_des *data);
int		ft_des_process_vector_if_key(t_des *data);
void	ft_des_choose_pbkdf(t_des *data);
void	ft_des_process_vector_if_password(t_des *data);
void	ft_des_process_key_if_password(t_des *data);
int		ft_des_process_key_n_vector_if_password(t_des *data);
void	ft_delete_flags(t_des *data);
void	ft_des_search_flags(t_alg *my, t_des *data, int ac, char **av);
void	ft_des_flags(void *my, int ac, char **av);

char	*ft_des_add_padding(char *str, size_t *len, int padding);
void	ft_des_encrypt_keys(uint8_t *keys16_48, uint8_t *key8);
void	ft_des3_encrypt_keys(uint8_t *keys16_48, uint8_t *key8);
void	ft_des_process_flag_a(t_des *data);
void	ft_des_encrypt_make_output(t_des *data);

void	ft_des_decrypt_keys(uint8_t *keys16_48, uint8_t *key8);
void	ft_des3_decrypt_keys(uint8_t *keys16_48, uint8_t *key8);
int		ft_des_check_padding(uint8_t *last_block, size_t *len, int pad_flag);
void	ft_des_decrypt_make_output(t_des *data);

void	ft_des_make_left_shift(uint8_t *arr, uint8_t len);
void	ft_des_make_right_shift(uint8_t *arr, uint8_t len);
void	ft_des_make_key56(uint8_t *key56, uint8_t *key64);
void	ft_des_make_key48(uint8_t *key48, uint8_t *key56);
void	ft_des_make_block_ip_permutation(uint8_t *block64);
void	ft_des_make_ip_rev_permutation(uint8_t *block64);
void	ft_des_s_table(uint8_t *block4, uint8_t *block6, uint8_t *s_table);
void	ft_des_feistel_make_p_permutation(uint8_t *block32);
void	ft_des_feistel(uint8_t *block32, uint8_t *key48);
void	ft_des_main_algor(uint8_t *block64, uint8_t *keys16_48);
void	ft_des_algor(uint8_t *block8, uint8_t *keys16_48);

void	ft_des_ecb_enc_dec(t_des_data *data);
void	ft_des_cbc_enc(t_des_data *data);
void	ft_des_cbc_dec(t_des_data *data);
void	ft_des_pcbc_enc(t_des_data *data);
void	ft_des_pcbc_dec(t_des_data *data);
void	ft_des_ofb_enc_dec(t_des_data *data);
void	ft_des_cfb_enc(t_des_data *data);
void	ft_des_cfb_dec(t_des_data *data);
void	ft_des3_ecb_enc_dec(t_des_data *data);
void	ft_des3_cbc_enc(t_des_data *data);
void	ft_des3_cbc_dec(t_des_data *data);
void	ft_des3_pcbc_enc(t_des_data *data);
void	ft_des3_pcbc_dec(t_des_data *data);
void	ft_des3_ofb_enc_dec(t_des_data *data);
void	ft_des3_cfb_enc(t_des_data *data);
void	ft_des3_cfb_dec(t_des_data *data);

void	ft_md5(void *v_data);
void	ft_sha1(void *v_data);
void	ft_sha256(void *v_data);
void	ft_sha512(void *v_data);
void	ft_whirlpool(void *v_data);
void	ft_base64(void *v_data);
void	ft_des_ecb(void *v_data);
void	ft_des_cbc(void *v_data);
void	ft_des_ofb(void *v_data);
void	ft_des_pcbc(void *v_data);
void	ft_des_cfb(void *v_data);
void	ft_des3_ecb(void *v_data);
void	ft_des3_cbc(void *v_data);
void	ft_des3_ofb(void *v_data);
void	ft_des3_pcbc(void *v_data);
void	ft_des3_cfb(void *v_data);
void	ft_rsa(void *v_data);
void	ft_genrsa(void *v_data);
void	ft_rsautl(void *v_data);

void	ft_ascii_to_hex(char *hex, char *str, size_t len);
int		ft_hex_to_dec(uint8_t hex);
int		ft_hex_to_ascii(uint8_t *bytes, char *hex, size_t len);

void	ft_close_fd(int fd);
char	*ft_read_from(int fd, size_t *len);
int		ft_make_input_fd(char *file);
int		ft_make_output_fd(char *file);

int		ft_choose_first_param(t_alg *my, char *str);
char	*ft_strtrim_comma(char *str);
void	ft_split_argument_line(t_alg *my, char *line);
void	ft_parse_from_console(t_alg *my);
int		main(int ac, char **av);

#endif
