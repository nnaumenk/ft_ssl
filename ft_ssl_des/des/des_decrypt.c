/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_decrypt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:27:01 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 15:06:41 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

void	ft_des_decrypt_keys(uint8_t *keys16_48, uint8_t *key8)
{
	const uint8_t	table[] = {0, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	uint8_t			key64[64];
	uint8_t			key56[56];
	uint8_t			shift;
	uint8_t			counter;

	ft_mem_to_bits(key64, key8, 8);
	ft_des_make_key56(key56, key64);
	counter = -1;
	while (++counter < 16)
	{
		shift = table[counter];
		while (shift--)
		{
			ft_des_make_right_shift(key56, 28);
			ft_des_make_right_shift(&key56[28], 28);
		}
		ft_des_make_key48(keys16_48, key56);
		keys16_48 = &keys16_48[48];
	}
}

void	ft_des3_decrypt_keys(uint8_t *keys16_48, uint8_t *key8)
{
	ft_des_decrypt_keys(keys16_48, key8 + 16);
	ft_des_encrypt_keys(keys16_48 + 768, key8 + 8);
	ft_des_decrypt_keys(keys16_48 + 1536, key8);
}

void	ft_des_check_padding(uint8_t *last_block, size_t *len, int pad_flag)
{
	int			counter;
	int			padded_number;
	uint8_t		*pointer;

	if (pad_flag == 0)
		return ;
	padded_number = last_block[7];
	if (padded_number < 1 || padded_number > 8)
	{
		*len = (*len - 1) / 8 * 8;
		ft_print("Bad decrypt\n");
		return ;
	}
	pointer = &last_block[7];
	counter = padded_number;
	while (counter--)
	{
		if (*pointer-- != padded_number)
		{
			*len = (*len - 1) / 8 * 8;
			ft_print("Bad decrypt\n");
			return ;
		}
	}
	*len -= padded_number;
}

void	ft_des_decrypt_make_output(t_des *data)
{
	size_t		blocks;

	data->text = ft_des_add_padding(data->text, &data->len, 0);
	data->data.block8 = (uint8_t *)data->text;
	data->data.vector8 = (uint8_t *)data->flag.vector8;
	data->data.keys = (uint8_t *)data->flag.keys16_48;
	blocks = (data->len + 7) / 8;
	while (blocks--)
	{
		(data->des_alg_fun)(&data->data);
		data->data.block8 += 8;
	}
	ft_des_check_padding(data->data.block8 - 8, &data->len, data->padding);
	write(data->flag.fd_output, data->text, data->len);
}
