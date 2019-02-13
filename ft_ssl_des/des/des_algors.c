/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_algors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:27:01 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 14:46:14 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

void	ft_des_ecb_enc_dec(t_des_data *data)
{
	ft_des_algor(data->block8, data->keys);
}

void	ft_des_cbc_enc(t_des_data *data)
{
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
	ft_des_algor(data->block8, data->keys);
	ft_memcpy(data->vector8, data->block8, 8);
}

void	ft_des_cbc_dec(t_des_data *data)
{
	uint8_t		buf[8];

	ft_memcpy(buf, data->block8, 8);
	ft_des_algor(data->block8, data->keys);
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
	ft_memcpy(data->vector8, buf, 8);
}

void	ft_des_pcbc_enc(t_des_data *data)
{
	uint8_t		buf[8];

	ft_memcpy(buf, data->block8, 8);
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
	ft_des_algor(data->block8, (uint8_t *)data->keys);
	ft_memcpy(data->vector8, data->block8, 8);
	ft_xor_mem(data->vector8, buf, 8);
}

void	ft_des_pcbc_dec(t_des_data *data)
{
	uint8_t		buf[8];

	ft_memcpy(buf, data->block8, 8);
	ft_des_algor(data->block8, (uint8_t *)data->keys);
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
	ft_memcpy(data->vector8, data->block8, 8);
	ft_xor_mem(data->vector8, buf, 8);
}
