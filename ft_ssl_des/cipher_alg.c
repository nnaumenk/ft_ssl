/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 23:36:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 13:33:48 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

void	ft_base64(void *v_data)
{
	t_des	*data;

	data = v_data;
	if (data->flag.decrypt)
		data->text = ft_b64_decode(data->text, &(data->len));
	else
		data->text = ft_b64_encode(data->text, &(data->len));
}

void	ft_des_ecb(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 1;
	data->key_len = 8;
	data->des_alg_fun = ft_des_ecb_enc_dec;
	if (data->flag.decrypt)
	{
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
		data->make_keys_fun = ft_des_decrypt_keys;
	}
	else
	{
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
		data->make_keys_fun = ft_des_encrypt_keys;
	}
}

void	ft_des_cbc(void *v_data)
{
	t_des	*data;

	data = v_data;
	data->padding = 1;
	data->key_len = 8;
	if (data->flag.decrypt)
	{
		data->des_alg_fun = ft_des_cbc_dec;
		data->encrypt_decrypt_fun = ft_des_decrypt_process_flags;
		data->make_keys_fun = ft_des_decrypt_keys;
	}
	else
	{
		data->des_alg_fun = ft_des_cbc_enc;
		data->encrypt_decrypt_fun = ft_des_encrypt_process_flags;
		data->make_keys_fun = ft_des_encrypt_keys;
	}
}
