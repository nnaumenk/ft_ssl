/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:27:41 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 00:42:27 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_DES_H
# define FT_SSL_DES_H

# include "../ft_ssl.h"

typedef struct		s_des_flags
{
	int				a;
	int				decrypt;
	int				fd_input;
	char			*name_input;
	int				fd_output;
	char			*name_output;
	char			*password;
	char			*vector;
	char			*key;
	char			*salt;
	uint8_t			salt8[8];
	uint8_t			key8[24];
	uint8_t			keys16_48[3][16][48];
	uint8_t			vector8[8];
	int				pbkdf2;
}					t_des_flags;

typedef struct		s_des_data
{
	uint8_t			*block8;
	uint8_t			*keys;
	uint8_t			*vector8;
}					t_des_data;

typedef struct		s_des
{
	int				(*encrypt_decrypt_fun)(struct s_des *);
	void			(*des_alg_fun)(t_des_data *);
	void			(*make_keys_fun)(uint8_t *, uint8_t *);
	char			*text;
	size_t			len;
	int				key_len;
	int				padding;
	int				is_salt_to_output;
	t_des_flags		flag;
	t_des_data		data;
}					t_des;

typedef struct		s_des_options
{
	char			*name;
	int				(*function)(int *, int, char **, t_des *);
}					t_des_options;

#endif
