/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:18:24 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 19:43:12 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "whirlpool.h"

char	*ft_whirlpool_make_alignment(char *text, size_t *len)
{
	char			*new;
	char			*pointer;
	size_t			old_len;
	size_t			new_len;
	size_t			null_len;

	old_len = *len;
	new_len = ((old_len + 32) / 64) * 64 + 32 + 32;
	new = (char *)malloc(new_len);
	ft_memcpy((void *)new, (void *)text, old_len);
	pointer = new + old_len;
	*pointer++ = 0x80;
	null_len = new_len - old_len - 32 - 1;
	ft_bzero((void *)pointer, null_len);
	pointer += null_len;
	ft_whirlpool_add_len(pointer, old_len);
	*len = new_len;
	return (new);
}

void	ft_whirlpool_add_len(char *text, size_t len)
{
	int		low_bits[16];
	int		high_bits[16];
	int		bits;

	len *= 8;
	bits = 16;
	while (bits--)
	{
		low_bits[bits] = len % 256;
		len /= 256;
	}
	bits = 16;
	while (bits--)
	{
		high_bits[bits] = len % 256;
		len /= 256;
	}
	bits = -1;
	while (++bits < 16)
		*text++ = high_bits[bits];
	bits = -1;
	while (++bits < 16)
		*text++ = low_bits[bits];
}

void	ft_whirlpool_round_function(uint8_t *message, uint8_t *key)
{
	uint8_t		*pointer;
	int			rounds;
	uint8_t		bkey[64];

	ft_memcpy(bkey, key, 64);
	ft_xor_mem(message, bkey, 64);
	pointer = g_wp_s_box;
	rounds = 10;
	while (rounds--)
	{
		ft_whirlpool_sub_bytes(bkey);
		ft_whirlpool_shift_columns(bkey);
		ft_whirlpool_mix_rows(bkey);
		ft_xor_mem(bkey, pointer, 8);
		ft_whirlpool_sub_bytes(message);
		ft_whirlpool_shift_columns(message);
		ft_whirlpool_mix_rows(message);
		ft_xor_mem(message, bkey, 64);
		pointer += 8;
	}
}

void	ft_whirlpool_algor(uint8_t *hash, char *text, size_t len)
{
	size_t			blocks;
	uint8_t			block[64];

	blocks = len / 64;
	while (blocks--)
	{
		ft_memcpy(block, text, 64);
		ft_whirlpool_round_function(block, hash);
		ft_xor_mem(block, text, 64);
		ft_xor_mem(hash, block, 64);
		text += 64;
	}
}
