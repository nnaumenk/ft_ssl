/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:27:01 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 22:51:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

void	ft_des_feistel(uint8_t *block32, uint8_t *key48)
{
	const uint8_t	table[8][64] = {S_TABLE};
	const uint8_t	block_table[] = {BLOCK48_TABLE};
	uint8_t			block48[48];
	int				i;

	i = -1;
	while (++i < 48)
		block48[i] = block32[block_table[i] - 1];
	ft_xor_mem((void *)block48, (void *)key48, 48);
	i = -1;
	while (++i < 8)
		ft_des_s_table(&block32[i * 4], &block48[i * 6], (uint8_t *)table[i]);
	ft_des_feistel_make_p_permutation(block32);
}

void	ft_des_main_algor(uint8_t *block64, uint8_t *keys16_48)
{
	uint8_t			block_left[32];
	uint8_t			block_right[32];
	uint8_t			block_buf[32];
	int				counter;

	ft_memcpy((void *)block_left, (void *)block64, 32);
	ft_memcpy((void *)block_right, (void *)&block64[32], 32);
	counter = -1;
	while (++counter < 16)
	{
		ft_memcpy((void *)block_buf, (void *)block_right, 32);
		ft_des_feistel(block_right, keys16_48);
		keys16_48 = &keys16_48[48];
		ft_xor_mem((void *)block_right, (void *)block_left, 32);
		ft_memcpy((void *)block_left, (void *)block_buf, 32);
	}
	ft_memcpy((void *)block64, (void *)block_right, 32);
	ft_memcpy((void *)&block64[32], (void *)block_left, 32);
}

void	ft_des_algor(uint8_t *block8, uint8_t *keys16_48)
{
	uint8_t		block64[64];

	ft_mem_to_bits(block64, block8, 8);
	ft_des_make_block_ip_permutation(block64);
	ft_des_main_algor(block64, keys16_48);
	ft_des_make_ip_rev_permutation(block64);
	ft_bits_to_mem(block8, block64, 8);
}
