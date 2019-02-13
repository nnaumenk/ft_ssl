/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:54:52 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 20:32:54 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "sha256.h"

void		ft_sha256_start_values(uint32_t *global)
{
	global[0] = 0x6A09E667;
	global[1] = 0xBB67AE85;
	global[2] = 0x3C6EF372;
	global[3] = 0xA54FF53A;
	global[4] = 0x510E527F;
	global[5] = 0x9B05688C;
	global[6] = 0x1F83D9AB;
	global[7] = 0x5BE0CD19;
}

void		ft_sha256_round(uint32_t *buf, uint32_t *w)
{
	const uint32_t		sha256[] = { SHA256_K_VALUES };
	uint32_t			temp1;
	uint32_t			temp2;
	int					i;

	i = -1;
	while (++i < 64)
	{
		temp1 = buf[7] + w[i] + sha256[i];
		temp1 += SIGMA1(buf[4]) + CH(buf[4], buf[5], buf[6]);
		temp2 = SIGMA0(buf[0]) + MA(buf[0], buf[1], buf[2]);
		buf[7] = buf[6];
		buf[6] = buf[5];
		buf[5] = buf[4];
		buf[4] = buf[3] + temp1;
		buf[3] = buf[2];
		buf[2] = buf[1];
		buf[1] = buf[0];
		buf[0] = temp1 + temp2;
	}
}

void		ft_sha256_make_w_arr(uint32_t *w, char *block)
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
	while (++i < 64)
		w[i] = w[i - 16] + DELTA0(w[i - 15]) + w[i - 7] + DELTA1(w[i - 2]);
}

void		ft_sha256_algor(uint32_t *hash, char *text, size_t len)
{
	uint32_t	w[64];
	uint32_t	buf[8];
	size_t		blocks;
	int			words;

	blocks = len / 64;
	while (blocks--)
	{
		ft_sha256_make_w_arr(w, text);
		ft_memcpy(buf, hash, 32);
		ft_sha256_round(buf, w);
		words = 8;
		while (words--)
			hash[words] += buf[words];
		text += 64;
	}
	words = 8;
	while (words--)
	{
		ft_memrev(hash, 4);
		hash++;
	}
}
