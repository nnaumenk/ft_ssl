/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_rsa.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:27:41 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:04:47 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_RSA_H
# define FT_SSL_RSA_H

# include "bigint/ft_bigint.h"

typedef struct		s_rsa_flag
{
	int				rand_fd;
	int				inform;
	int				outform;
	char			*in;
	char			*passin;
	char			*out;
	char			*passout;
	int				des;
	char			vector[8];
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
	int				exp_value_3;
	size_t			numbits;
}					t_rsa_flag;

typedef struct		s_rsa_data
{
	t_bigint		modulus;
	t_bigint		public_exponent;
	t_bigint		private_exponent;
	t_bigint		prime1;
	t_bigint		prime2;
	t_bigint		exponent1;
	t_bigint		exponent2;
	t_bigint		coefficient;
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
