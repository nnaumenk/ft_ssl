/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_alg_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 23:36:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 13:32:48 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

void	ft_des_ofb(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 0;
	data->key_len = 8;
	data->des_alg_fun = ft_des_ofb_enc_dec;
	data->make_keys_fun = ft_des_encrypt_keys;
	if (data->flag.decrypt)
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
	else
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
}

void	ft_des_pcbc(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 1;
	data->key_len = 8;
	if (data->flag.decrypt)
	{
		data->des_alg_fun = ft_des_pcbc_dec;
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
		data->make_keys_fun = ft_des_decrypt_keys;
	}
	else
	{
		data->des_alg_fun = ft_des_pcbc_enc;
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
		data->make_keys_fun = ft_des_encrypt_keys;
	}
}

void	ft_des_cfb(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 0;
	data->key_len = 8;
	data->make_keys_fun = ft_des_encrypt_keys;
	if (data->flag.decrypt)
	{
		data->des_alg_fun = ft_des_cfb_dec;
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
	}
	else
	{
		data->des_alg_fun = ft_des_cfb_enc;
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
	}
}
