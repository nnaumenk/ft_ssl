/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:28:05 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 02:05:34 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

#define HASH_FUNCTION(x)	ft_sha256(x)
#define HASH_LEN			32

static void	ft_hash_function(t_md5_data *data, char *text, size_t len)
{
	data->text = text;
	data->len = len;
	HASH_FUNCTION((void *)data);
}

static char	*ft_hmac_make_key(char *key, size_t key_len)
{
	t_md5_data	data;
	char		*key64;

	key64 = ft_strnew(64);
	ft_bzero(key64, 64);
	if (key_len <= 64)
		ft_memcpy((void *)key64, (void *)key, key_len);
	else
	{
		ft_hash_function(&data, key, key_len);
		ft_memcpy((void *)key64, (void *)data.hash, HASH_LEN);
	}
	return (key64);
}

char		*ft_hmac(char *key, char *msg, size_t key_len, size_t msg_len)
{
	t_md5_data	data;
	char		*key64;
	char		*s_i;
	char		*s_o;

	key64 = ft_hmac_make_key(key, key_len);
	s_i = (char*)malloc(64);
	ft_memcpy(s_i, key64, 64);
	ft_xor_mem_value(s_i, 0x36, 64);
	s_o = (char*)malloc(64);
	ft_memcpy(s_o, key64, 64);
	ft_xor_mem_value(s_o, 0x5c, 64);
	s_i = ft_memjoin_del((void *)s_i, (void *)msg, 64, msg_len);
	ft_hash_function(&data, s_i, msg_len + 64);
	s_o = ft_memjoin_del((void *)s_o, (void *)data.hash, 64, HASH_LEN);
	ft_hash_function(&data, s_o, 64 + HASH_LEN);
	ft_memcpy((void *)key64, (void *)data.hash, HASH_LEN);
	ft_strdel(&s_o);
	ft_strdel(&s_i);
	return (key64);
}
