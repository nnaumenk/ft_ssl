/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_rsa.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:27:41 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 16:37:45 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_RSA_H
# define FT_SSL_RSA_H

typedef struct		s_rsa_flag
{
	int				rand;
	char			*inform;
	char			*outform;
	char			*i;
	char			*in;
	int				fd_input;
	char			*passin;
	char			*o;
	char			*out;
	int				fd_output;
	char			*passout;
	int				des;
	int				text;
	int				noout;
	int				modulus;
	int				check;
	int				pubin;
	int				pubout;
	char			*inkey;
	int				encrypt;
	int				decrypt;
	int				hexdump;
}					t_rsa_flag;

typedef struct		s_rsa_data
{
	unsigned char	*modulus;
	size_t			modulus_len;
	unsigned char	*public_exponent;
	size_t			public_exponent_len;
	unsigned char	*private_exponent;
	size_t			private_exponent_len;
	unsigned char	*prime1;
	size_t			prime1_len;
	unsigned char	*prime2;
	size_t			prime2_len;
	unsigned char	*exponent1;
	size_t			exponent1_len;
	unsigned char	*exponent2;
	size_t			exponent2_len;
	unsigned char	*coefficient;
	size_t			coefficient_len;
}					t_rsa_data;

typedef struct		s_rsa
{
	char			*text;
	size_t			len;
	t_rsa_flag		flag;
	t_rsa_data		data;
}					t_rsa;

typedef struct		s_rsa_option
{
	char			*option_name;
	int				(*option_function)(int *, int, char **, t_rsa_flag *);
}					t_rsa_option;

#endif