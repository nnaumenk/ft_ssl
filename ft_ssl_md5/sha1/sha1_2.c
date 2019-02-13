/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:54:52 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 20:32:58 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "sha1.h"

void		ft_sha1_start_values(uint32_t *global)
{
	global[0] = 0x67452301;
	global[1] = 0xEFCDAB89;
	global[2] = 0x98BADCFE;
	global[3] = 0x10325476;
	global[4] = 0xC3D2E1F0;
}

void		ft_sha1_round_help(uint32_t *buf, uint32_t temp, uint32_t w)
{
	temp += buf[4] + w;
	buf[4] = buf[3];
	buf[3] = buf[2];
	buf[2] = ROL(buf[1], 30);
	buf[1] = buf[0];
	buf[0] = temp;
}

void		ft_sha1_round(uint32_t *buf, uint32_t *w)
{
	const uint32_t		sha1[] = { SHA1_K_VALUES };
	uint32_t			temp;
	int					i;

	i = 0;
	while (i < 20)
	{
		temp = ROL(buf[0], 5) + CH(buf[1], buf[2], buf[3]) + sha1[0];
		ft_sha1_round_help(buf, temp, w[i++]);
	}
	while (i < 40)
	{
		temp = ROL(buf[0], 5) + PARITY(buf[1], buf[2], buf[3]) + sha1[1];
		ft_sha1_round_help(buf, temp, w[i++]);
	}
	while (i < 60)
	{
		temp = ROL(buf[0], 5) + MA(buf[1], buf[2], buf[3]) + sha1[2];
		ft_sha1_round_help(buf, temp, w[i++]);
	}
	while (i < 80)
	{
		temp = ROL(buf[0], 5) + PARITY(buf[1], buf[2], buf[3]) + sha1[3];
		ft_sha1_round_help(buf, temp, w[i++]);
	}
}

void		ft_sha1_make_w_arr(uint32_t *w, char *block)
{
	uint32_t	*pointer;
	int			i;

	pointer = (uint32_t *)block;
	i = 16;
	while (i--)
	{
		ft_memrev(pointer, 4);
		pointer++;
	}
	ft_memcpy(w, block, 64);
	i = 15;
	while (++i < 80)
		w[i] = ROL((w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]), 1);
}

void		ft_sha1_algor(uint32_t *hash, char *text, size_t len)
{
	uint32_t	w[80];
	uint32_t	buf[5];
	size_t		blocks;
	int			words;

	blocks = len / 64;
	while (blocks--)
	{
		ft_sha1_make_w_arr(w, text);
		ft_memcpy(buf, hash, 20);
		ft_sha1_round(buf, w);
		words = 5;
		while (words--)
			hash[words] += buf[words];
		text += 64;
	}
	words = 5;
	while (words--)
	{
		ft_memrev(hash, 4);
		hash++;
	}
}
