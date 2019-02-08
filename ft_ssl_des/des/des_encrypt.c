/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_encrypt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:00:40 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 15:06:48 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

char	*ft_des_add_padding(char *str, size_t *len, int padding)
{
	char	*new;
	size_t	new_len;
	char	added_len;

	added_len = 8 - *len % 8;
	if (padding)
	{
		new_len = *len + added_len;
		new = (char *)malloc(new_len);
		ft_memcpy(new, str, *len);
		ft_memset(&new[*len], added_len, added_len);
		*len = new_len;
	}
	else if (added_len == 8)
		return (str);
	else
	{
		new_len = *len + added_len;
		new = (char *)malloc(new_len);
		ft_memcpy(new, str, *len);
		ft_bzero(&new[*len], added_len);
	}
	ft_strdel(&str);
	return (new);
}

void	ft_des_encrypt_keys(uint8_t *keys16_48, uint8_t *key8)
{
	const uint8_t	table[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
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
			ft_des_make_left_shift(key56, 28);
			ft_des_make_left_shift(&key56[28], 28);
		}
		ft_des_make_key48(keys16_48, key56);
		keys16_48 = &keys16_48[48];
	}
}

void	ft_des3_encrypt_keys(uint8_t *keys16_48, uint8_t *key8)
{
	ft_des_encrypt_keys(keys16_48, key8);
	ft_des_decrypt_keys(keys16_48 + 768, key8 + 8);
	ft_des_encrypt_keys(keys16_48 + 1536, key8 + 16);
}

void	ft_des_encrypt_process_flag_a(t_des *data)
{
	char	*new;

	if (data->flag.a)
	{
		if (data->is_salt_to_output)
		{
			data->len += 16;
			new = (char *)malloc(data->len);
			ft_memcpy(new, "Salted__", 8);
			ft_memcpy(new + 8, data->flag.salt8, 8);
			ft_memcpy(new + 16, data->text, data->len - 16);
			ft_strdel(&data->text);
			data->text = new;
		}
		data->text = ft_b64_encode(data->text, &data->len);
	}
}

void	ft_des_encrypt_make_output(t_des *data)
{
	size_t		blocks;

	data->text = ft_des_add_padding(data->text, &data->len, data->padding);
	data->data.block8 = (uint8_t *)data->text;
	data->data.vector8 = (uint8_t *)data->flag.vector8;
	data->data.keys = (uint8_t *)data->flag.keys16_48;
	blocks = (data->len + 7) / 8;
	while (blocks--)
	{
		(data->des_alg_fun)(&data->data);
		data->data.block8 += 8;
	}
	ft_des_encrypt_process_flag_a(data);
	write(data->flag.fd_output, data->text, data->len);
}
