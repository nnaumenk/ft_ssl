/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_alg_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 23:36:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 13:33:08 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

void	ft_des3_ecb(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 1;
	data->key_len = 24;
	data->des_alg_fun = ft_des3_ecb_enc_dec;
	if (data->flag.decrypt)
	{
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
		data->make_keys_fun = ft_des3_decrypt_keys;
	}
	else
	{
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
		data->make_keys_fun = ft_des3_encrypt_keys;
	}
}

void	ft_des3_cbc(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 1;
	data->key_len = 24;
	if (data->flag.decrypt)
	{
		data->des_alg_fun = ft_des3_cbc_dec;
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
		data->make_keys_fun = ft_des3_decrypt_keys;
	}
	else
	{
		data->des_alg_fun = ft_des3_cbc_enc;
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
		data->make_keys_fun = ft_des3_encrypt_keys;
	}
}

void	ft_des3_ofb(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 0;
	data->key_len = 24;
	data->des_alg_fun = ft_des3_ofb_enc_dec;
	data->make_keys_fun = ft_des3_encrypt_keys;
	if (data->flag.decrypt)
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
	else
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
}

void	ft_des3_pcbc(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 1;
	data->key_len = 24;
	if (data->flag.decrypt)
	{
		data->des_alg_fun = ft_des3_pcbc_dec;
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
		data->make_keys_fun = ft_des3_decrypt_keys;
	}
	else
	{
		data->des_alg_fun = ft_des3_pcbc_enc;
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
		data->make_keys_fun = ft_des3_encrypt_keys;
	}
}

void	ft_des3_cfb(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 0;
	data->key_len = 24;
	data->make_keys_fun = ft_des3_encrypt_keys;
	if (data->flag.decrypt)
	{
		data->des_alg_fun = ft_des3_cfb_dec;
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
	}
	else
	{
		data->des_alg_fun = ft_des3_cfb_enc;
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
	}
}
