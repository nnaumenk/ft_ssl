/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 00:55:44 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 02:05:29 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

#define HASH_FUNCTION(x)	ft_sha256(x)
#define HASH_LEN			32

static void	ft_hash_function(char **text, size_t *len)
{
	t_md5_data data;

	data.text = *text;
	data.len = *len;
	HASH_FUNCTION((void *)&data);
	ft_strdel(text);
	*len = HASH_LEN;
	*text = (char *)malloc(HASH_LEN);
	ft_memcpy(*text, data.hash, HASH_LEN);
}

static void	ft_concat_str(char **hash, size_t *hash_len, char *pass, char *salt)
{
	char			*str;
	size_t			len;
	static size_t	pass_len;

	if (pass_len == 0)
		pass_len = ft_strlen(pass);
	len = *hash_len + pass_len + 8;
	str = (char *)malloc(len);
	ft_memcpy(str, *hash, *hash_len);
	ft_memcpy(str + *hash_len, pass, pass_len);
	ft_memcpy(str + *hash_len + pass_len, salt, 8);
	ft_strdel(hash);
	*hash_len = len;
	*hash = str;
}

char		*ft_evp(char *pass, uint8_t *salt, size_t len)
{
	size_t	blocks;
	size_t	block_len;
	char	*block;
	char	*result_block;
	char	*pointer;

	block_len = 0;
	block = ft_strnew(0);
	blocks = (len + HASH_LEN - 1) / HASH_LEN;
	result_block = (char *)malloc(blocks * HASH_LEN);
	pointer = result_block;
	while (blocks--)
	{
		ft_concat_str(&block, &block_len, pass, (char *)salt);
		ft_hash_function(&block, &block_len);
		ft_memcpy(pointer, block, HASH_LEN);
		pointer += HASH_LEN;
	}
	ft_strdel(&block);
	return (result_block);
}
