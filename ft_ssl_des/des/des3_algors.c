/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des3_algors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 23:11:22 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 13:06:17 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

void	ft_des3_ecb_enc_dec(t_des_data *data)
{
	ft_des_algor(data->block8, data->keys);
	ft_des_algor(data->block8, data->keys + 768);
	ft_des_algor(data->block8, data->keys + 1536);
}

void	ft_des3_cbc_enc(t_des_data *data)
{
	ft_xor_mem(data->block8, data->vector8, 8);
	ft_des_algor(data->block8, data->keys);
	ft_des_algor(data->block8, data->keys + 768);
	ft_des_algor(data->block8, data->keys + 1536);
	ft_memcpy(data->vector8, data->block8, 8);
}

void	ft_des3_cbc_dec(t_des_data *data)
{
	uint8_t		buf[8];

	ft_memcpy(buf, data->block8, 8);
	ft_des_algor(data->block8, data->keys);
	ft_des_algor(data->block8, data->keys + 768);
	ft_des_algor(data->block8, data->keys + 1536);
	ft_xor_mem(data->block8, data->vector8, 8);
	ft_memcpy(data->vector8, buf, 8);
}

void	ft_des3_pcbc_enc(t_des_data *data)
{
	uint8_t		buf[8];

	ft_memcpy(buf, data->block8, 8);
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
	ft_des_algor(data->block8, data->keys);
	ft_des_algor(data->block8, data->keys + 768);
	ft_des_algor(data->block8, data->keys + 1536);
	ft_memcpy(data->vector8, data->block8, 8);
	ft_xor_mem(data->vector8, buf, 8);
}

void	ft_des3_pcbc_dec(t_des_data *data)
{
	uint8_t		buf[8];

	ft_memcpy(buf, data->block8, 8);
	ft_des_algor(data->block8, data->keys);
	ft_des_algor(data->block8, data->keys + 768);
	ft_des_algor(data->block8, data->keys + 1536);
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
	ft_memcpy(data->vector8, data->block8, 8);
	ft_xor_mem(data->vector8, buf, 8);
}
