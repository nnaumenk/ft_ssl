/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des3_algors_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 23:21:39 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 13:06:16 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

void	ft_des3_ofb_enc_dec(t_des_data *data)
{
	ft_des_algor(data->vector8, data->keys);
	ft_des_algor(data->vector8, data->keys + 768);
	ft_des_algor(data->vector8, data->keys + 1536);
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
}

void	ft_des3_cfb_enc(t_des_data *data)
{
	ft_des_algor(data->vector8, data->keys);
	ft_des_algor(data->vector8, data->keys + 768);
	ft_des_algor(data->vector8, data->keys + 1536);
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
	ft_memcpy(data->vector8, data->block8, 8);
}

void	ft_des3_cfb_dec(t_des_data *data)
{
	uint8_t		buf[8];

	ft_des_algor(data->vector8, data->keys);
	ft_des_algor(data->vector8, data->keys + 768);
	ft_des_algor(data->vector8, data->keys + 1536);
	ft_memcpy(buf, data->block8, 8);
	ft_xor_mem((void *)data->block8, (void *)data->vector8, 8);
	ft_memcpy(data->vector8, buf, 8);
}
