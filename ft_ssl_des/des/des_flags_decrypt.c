/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_flags_decrypt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 23:09:32 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 01:42:06 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

int		ft_des_read_password(t_des *data)
{
	data->flag.password = getpass("Enter des decryption password:");
	if (data->flag.password[0] == 0)
	{
		ft_print("bad password read\n");
		return (1);
	}
	return (0);
}

int		ft_des_decrypt_process_salt(t_des *data)
{
	if (data->len < 16)
	{
		ft_strdel(&data->text);
		ft_print("error reading input file\n");
		return (1);
	}
	if (ft_memequ(data->text, "Salted__", 8) == 0)
	{
		ft_strdel(&data->text);
		ft_print("bad magic number\n");
		return (1);
	}
	ft_memcpy(data->flag.salt8, data->text + 8, 8);
	data->len -= 16;
	ft_memcpy(data->text, data->text + 16, data->len);
	return (0);
}

int		ft_des_decrypt_if_password(t_des *data)
{
	data->flag.fd_input = ft_make_input_fd(data->flag.name_input);
	if (data->flag.fd_input == -1)
		return (1);
	data->flag.fd_output = ft_make_output_fd(data->flag.name_output);
	if (data->flag.fd_output == -1)
		return (1);
	data->text = ft_read_from(data->flag.fd_input, &data->len);
	if (data->flag.a)
		data->text = ft_b64_decode(data->text, &data->len);
	if (ft_des_decrypt_process_salt(data))
		return (1);
	if (ft_des_process_key_n_vector_if_password(data))
	{
		ft_strdel(&data->text);
		return (1);
	}
	return (0);
}

int		ft_des_decrypt_if_key(t_des *data)
{
	data->flag.fd_input = ft_make_input_fd(data->flag.name_input);
	if (data->flag.fd_input == -1)
		return (1);
	data->flag.fd_output = ft_make_output_fd(data->flag.name_output);
	if (data->flag.fd_output == -1)
		return (1);
	if (ft_des_process_vector_if_key(data))
		return (1);
	if (ft_hex_to_ascii(data->flag.key8, data->flag.key, data->key_len))
	{
		ft_print("invalid hex key value\n");
		return (1);
	}
	data->text = ft_read_from(data->flag.fd_input, &data->len);
	if (data->flag.a)
		data->text = ft_b64_decode(data->text, &data->len);
	return (0);
}

int		ft_des_decrypt_process_flags(t_des *data)
{
	int			error;

	if (data->flag.key)
		error = ft_des_decrypt_if_key(data);
	else if (data->flag.password)
		error = ft_des_decrypt_if_password(data);
	else
	{
		if (ft_des_read_password(data))
			return (1);
		error = ft_des_decrypt_if_password(data);
		ft_strdel(&data->flag.password);
	}
	if (error)
		return (1);
	(data->make_keys_fun)((uint8_t *)data->flag.keys16_48, data->flag.key8);
	ft_des_decrypt_make_output(data);
	return (0);
}
