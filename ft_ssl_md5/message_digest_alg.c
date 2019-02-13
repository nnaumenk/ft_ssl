/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_digest_alg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 12:01:43 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

void	ft_md5(void *v_data)
{
	char		*text;
	size_t		len;
	uint32_t	hash[4];

	text = ((t_md5_data *)v_data)->text;
	len = ((t_md5_data *)v_data)->len;
	text = ft_md5_make_alignment(text, &len);
	ft_md5_start_values(hash);
	ft_md5_algor(hash, text, len);
	ft_strdel(&text);
	((t_md5_data*)v_data)->hash_len = 16;
	ft_memcpy((((t_md5_data*)v_data)->hash), hash, 16);
}

void	ft_sha1(void *v_data)
{
	char		*text;
	size_t		len;
	uint32_t	hash[5];

	text = ((t_md5_data *)v_data)->text;
	len = ((t_md5_data *)v_data)->len;
	text = ft_sha1_make_alignment(text, &len);
	ft_sha1_start_values(hash);
	ft_sha1_algor(hash, text, len);
	ft_strdel(&text);
	((t_md5_data*)v_data)->hash_len = 20;
	ft_memcpy((((t_md5_data*)v_data)->hash), hash, 20);
}

void	ft_sha256(void *v_data)
{
	char		*text;
	size_t		len;
	uint32_t	hash[8];

	text = ((t_md5_data *)v_data)->text;
	len = ((t_md5_data *)v_data)->len;
	text = ft_sha256_make_alignment(text, &len);
	ft_sha256_start_values(hash);
	ft_sha256_algor(hash, text, len);
	ft_strdel(&text);
	((t_md5_data*)v_data)->hash_len = 32;
	ft_memcpy((((t_md5_data*)v_data)->hash), hash, 32);
}

void	ft_sha512(void *v_data)
{
	char		*text;
	size_t		len;
	uint64_t	hash[8];

	text = ((t_md5_data *)v_data)->text;
	len = ((t_md5_data *)v_data)->len;
	text = ft_sha512_make_alignment(text, &len);
	ft_sha512_start_values(hash);
	ft_sha512_algor(hash, text, len);
	ft_strdel(&text);
	((t_md5_data*)v_data)->hash_len = 64;
	ft_memcpy((((t_md5_data*)v_data)->hash), hash, 64);
}

void	ft_whirlpool(void *v_data)
{
	uint8_t		hash[64];
	char		*text;
	size_t		len;

	text = ((t_md5_data *)v_data)->text;
	len = ((t_md5_data *)v_data)->len;
	text = ft_whirlpool_make_alignment(text, &len);
	ft_bzero((void*)hash, 64);
	ft_whirlpool_algor(hash, text, len);
	ft_strdel(&text);
	((t_md5_data*)v_data)->hash_len = 64;
	ft_memcpy((((t_md5_data*)v_data)->hash), hash, 64);
}
