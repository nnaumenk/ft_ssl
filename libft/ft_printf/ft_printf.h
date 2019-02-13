/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:23:55 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/08 15:28:41 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 4096

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"

typedef	struct	s_list
{
	char		str_full[BUFF_SIZE];
	char		*s;
	va_list		ptr;
	va_list		argptr_offset;
	int			argptr_counter;
	int			len;
	int			len_block;
	int			len_full;
	char		flag_minus;
	char		flag_plus;
	char		flag_space;
	char		flag_hash;
	char		flag_zero;
	char		flag_comma;
	char		flag_dolar;
	char		flag_asterisk;
	char		flag_float;
	int			width_field;
	int			precision_field;
	int			len_field;
	char		type_field;
	int			buf;
	int			dot;
	int			i;
	int			unicode_check;
}				t_list;

char			*ft_atoa_to_hex_str(char *str, t_list *my);
int				ft_atoa_to_hex_counter(double num, int pr);
char			*ft_atoa_to_hex(double num, t_list *my, int symbol, char *base);
int				ft_atoa_pow(long double *n, double m);
char			*ft_atoa(long double n, t_list *my);

char			*ft_atoa_add_prefix(char *str, t_list *my, int sign);
int				ft_atoa_help(long double *n, t_list *my);

int				ft_str_attr_check_2(char *str_attr);
int				ft_str_attr_check(char *str_attr);
void			ft_add_attribute(t_list *my, int i, int attr_len);
void			ft_attribute_search(t_list *my);

char			*ft_etoa_precision_minus(char *str, t_list *my,
				int first_num_ind);
char			*ft_etoa_precision_plus(char *str, t_list *my, int dot_index);
char			*ft_etoa_help(char *str, t_list *my);
char			*ft_etoa(double n, t_list *my);

int				ft_exponent(char *str);
unsigned long	ft_mantisa(char *str, int *exponent);
char			*ft_float(char *str_ptr, t_list *my);

int				ft_float_minus(long double *n);
char			*ft_float_add_minus(char *str, t_list *my);
char			*ft_float_binary(unsigned long *ptr);
int				ft_float_dot(t_list *my);
char			*ft_float_add_exponent(char *str, t_list *my,
				int count, char type);

char			*ft_float_infinite_zero(char *str, t_list *my);
char			*ft_float_check(char *str, t_list *my);

char			*ft_round_float_2(char *str, t_list *my);
char			*ft_round_float(char *str, t_list *my);

char			*ft_ftoa_precision2(char *new, char *str, t_list *my, int af);
char			*ft_ftoa_precision(char *str, t_list *my);
char			*ft_ftoa(double n, t_list *my);

char			*ft_gtoa_flag_hash(char *str, t_list *my);
char			*ft_gtoa(double n, t_list *my);

char			*ft_gtoa_precision_3(char *str, t_list *my);
char			*ft_gtoa_precision_2(char *str, t_list *my, int bef, int aft);
char			*ft_gtoa_precision_exponent(char *str, t_list *my);
char			*ft_gtoa_precision_exponent_2(char *str, t_list *my,
				int first_num);
char			*ft_gtoa_precision(char *str, t_list *my);

char			*ft_itoa_base_int(char *str_base, t_list *my,
				long n, int base);
char			*ft_itoa_base_unint(char *str_base, t_list *my,
				unsigned long n, int base);
char			*ft_itoa_base_unint_x(char *str_base, t_list *my,
				unsigned long n, int base);
char			*ft_itoa_base_unint_o(char *str_base, t_list *my,
				unsigned long n, int base);
char			*ft_itoa_pointer(char *str_base, t_list *my,
				unsigned long n, int base);

char			*ft_str_join_free(char *s1, char *s2, int len1, int len2);
char			*ft_str_join_char_free(char *s1, int len, char c);
void			ft_my_strcat(t_list *my, char *s1, int len);
void			ft_expand(char **form, t_list *my);

int				ft_numcount_base_sign(long n, int base);
int				ft_numcount_base_unsign(unsigned long n, int base);
int				ft_char_index(char *str, char c);
int				ft_nochar_index(char *str, char c1, char c2);

int				ft_str_chr_all(char *str, char c);
int				ft_lenchr(char *s, int *start, char c);
int				ft_len_chr_str(char *s, int start, char *sub);
int				ft_minus(int *pow);

long			ft_atoi(char **str);
long			ft_mod_int(t_list *my);
unsigned long	ft_mod_unint(t_list *my);
long double		ft_mod_float(t_list *my);
void			ft_reset_flags(t_list *my);

void			ft_va_next(t_list *my);
char			*ft_expr_to_str2(t_list *my);
char			*ft_expr_to_str(t_list *my, char *b1, char *b2);
void			ft_expr_out(t_list *my);
int				ft_printf(const char *format, ...);

void			ft_search_s4(char **form, t_list *my);
void			ft_search_s3(char **form, t_list *my);
void			ft_search_s2_help(char	**form, t_list *my);
void			ft_search_s2(char **form, t_list *my);
void			ft_search_s1(char **form, t_list *my);

void			ft_specificator(char **form, t_list *my);
char			*ft_chardup(char c);

char			*ft_strchardup(int len, char c);
int				ft_strcount(char *str, int *spec);
char			*ft_my_strnew(int size);
char			*ft_my_strdup(char *s, t_list *my);
char			*ft_my_strdup_precision(char *s, t_list *my);

char			*ft_cut_after(char *str, int *len);
char			*ft_set_precision_long_min(t_list *my);
char			*ft_join_char(char *str_full, int len, char c);
char			*ft_itoa_base_u(char *str_base, int *len,
				unsigned long n, int base);
char			*ft_str_rev(char *str, t_list *my);

void			ft_set_counter(t_list *my);
char			*ft_date_iso(t_list *my);
char			*ft_notprintable_str(char *str, int len, int i);
char			*ft_notprintable(char *str, t_list *my);

char			*ft_flag_hash_x(char *str, t_list *my);
char			*ft_flag_hash_o(char *str, t_list *my);
char			*ft_flag_plus(char *str, t_list *my);
char			*ft_flag_space(char *str, t_list *my);

char			*ft_flag_comma_decimal(char *str, t_list *my);
char			*ft_flag_comma_float(char *str, t_list *my);
char			*ft_flag_comma_pointer(char	*str, t_list *my);
char			*ft_flag_comma(char *str, t_list *my);

char			*ft_cut(char *str, int *len);
char			*ft_str_mul_two(char *s, int *len);
char			*ft_pow_two(int pow, t_list *my);
int				ft_dot(int *dot, char s_i, char *s);
char			*ft_str_div_two(char *s, int *len);

char			*ft_set_precision_wstr(wchar_t *str, int len, t_list *my);
char			*ft_wstrdup_wstr(wchar_t *str, int len, t_list *my);
char			*ft_wstrdup(wchar_t *str, t_list *my);
char			*ft_wchardup2(char *str, wchar_t c, t_list *my);
char			*ft_wchardup(wchar_t c, t_list *my);

int				ft_flag_dolar(t_list my);
char			*ft_width_zero(char *str, t_list *my);
char			*ft_width_space(char *str, t_list *my);
char			*ft_width_minus_space(char *str, t_list *my);
char			*ft_field_width_main(char *str, t_list *my);

#endif
