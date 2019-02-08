/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_decrypt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:27:01 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/10/11 20:14:40 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

void	ft_des_make_block_ip_permutation(uint8_t *block64)
{
	const int	table[64] = {IP_TABLE};
	uint8_t		buffer[64];
	uint8_t		i;

	ft_memcpy((void *)buffer, (void *)block64, 64);
	i = -1;
	while (++i < 64)
		block64[i] = buffer[table[i] - 1];
}

void	ft_des_make_ip_rev_permutation(uint8_t *block64)
{
	const int	table[64] = {IP_REV_TABLE};
	uint8_t		buffer[64];
	int			i;

	ft_memcpy((void *)buffer, (void *)block64, 64);
	i = 64;
	while (i--)
		block64[i] = buffer[table[i] - 1];
}

void	ft_des_s_table(uint8_t *block4, uint8_t *block6, uint8_t *s_table)
{
	uint8_t			a;
	uint8_t			b;
	uint8_t			i;
	uint8_t			hex;

	a = *block6++ * 2;
	b = *block6++ * 8;
	b += *block6++ * 4;
	b += *block6++ * 2;
	b += *block6++;
	a += *block6++;
	hex = s_table[a * 16 + b];
	i = 4;
	while (i--)
	{
		block4[i] = hex % 2;
		hex /= 2;
	}
}

void	ft_des_feistel_make_p_permutation(uint8_t *block32)
{
	const int	table[] = {P_TABLE};
	uint8_t		buffer[32];
	int			i;

	ft_memcpy((void *)buffer, (void *)block32, 32);
	i = -1;
	while (++i < 32)
		block32[i] = buffer[table[i] - 1];
}
