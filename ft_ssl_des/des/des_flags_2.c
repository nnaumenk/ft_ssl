/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_flags_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 00:04:12 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 02:05:01 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

int		ft_des_process_vector_if_key(t_des *data)
{
	if (data->flag.vector == NULL)
	{
		if (data->des_alg_fun != ft_des_ecb_enc_dec &&
		data->des_alg_fun != ft_des3_ecb_enc_dec)
		{
			ft_print("vector undefined\n");
			return (1);
		}
	}
	else if (ft_hex_to_ascii(data->flag.vector8, data->flag.vector, 8))
	{
		ft_print("invalid hex vector value\n");
		return (1);
	}
	return (0);
}

void	ft_des_choose_pbkdf(t_des *data)
{
	if (data->flag.pbkdf2)
	{
		data->flag.key = ft_pbkdf2(data->flag.password, data->flag.salt8,
		2048, data->key_len + 8);
	}
	else
	{
		data->flag.key = ft_evp(data->flag.password, data->flag.salt8,
		data->key_len + 8);
	}
}

void	ft_des_process_vector_if_password(t_des *data)
{
	ft_memcpy(data->flag.vector8, data->flag.key + data->key_len, 8);
}

void	ft_des_process_key_if_password(t_des *data)
{
	ft_memcpy(data->flag.key8, data->flag.key, data->key_len);
	ft_strdel(&data->flag.key);
}

int		ft_des_process_key_n_vector_if_password(t_des *data)
{
	ft_des_choose_pbkdf(data);
	if (data->flag.vector == NULL)
	{
		if (data->des_alg_fun != ft_des_ecb_enc_dec)
			if (data->des_alg_fun != ft_des3_ecb_enc_dec)
				ft_des_process_vector_if_password(data);
	}
	else if (ft_strlen(data->flag.vector) > 32)
	{
		ft_print("hex string is too long\n");
		ft_print("invalid hex vector value\n");
		return (1);
	}
	else if (ft_hex_to_ascii(data->flag.vector8, data->flag.vector, 8))
	{
		ft_print("invalid hex vector value\n");
		return (1);
	}
	ft_des_process_key_if_password(data);
	return (0);
}
