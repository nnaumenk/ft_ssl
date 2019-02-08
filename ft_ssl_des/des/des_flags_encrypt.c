/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_flags_encrypt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:40:04 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 01:40:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

int		ft_des_read_password_verify(t_des *data)
{
	char	*password;

	password = getpass("Enter des encryption password:");
	if (password[0] == 0)
	{
		ft_print("bad password read\n");
		return (1);
	}
	password = ft_strdup(password);
	data->flag.password =
	getpass("Verifying - enter des encryption password:");
	if (data->flag.password[0] == 0)
	{
		ft_print("bad password read\n");
		ft_strdel(&password);
		return (1);
	}
	if (ft_strequ(password, data->flag.password) == 0)
	{
		ft_strdel(&password);
		ft_print("Verify failure\nbad password read\n");
		return (1);
	}
	ft_strdel(&password);
	return (0);
}

int		ft_des_encrypt_process_salt(t_des *data)
{
	char	output_salt[16];

	if (data->flag.salt == NULL)
		ft_generate_random((char *)data->flag.salt8, 8);
	else if (ft_strlen(data->flag.salt) > 16)
	{
		ft_print("hex string is too long\n");
		ft_print("invalid hex salt value\n");
		return (1);
	}
	else if (ft_hex_to_ascii(data->flag.salt8, data->flag.salt, 8))
	{
		ft_print("invalid hex salt value\n");
		return (1);
	}
	if (data->flag.a == 0)
	{
		ft_memcpy((void *)output_salt, (void *)"Salted__", 8);
		ft_memcpy((void *)&output_salt[8], (void *)data->flag.salt8, 8);
		write(data->flag.fd_output, output_salt, 16);
		data->is_salt_to_output = 0;
		return (0);
	}
	data->is_salt_to_output = 1;
	return (0);
}

int		ft_des_encrypt_if_password(t_des *data)
{
	data->flag.fd_input = ft_make_input_fd(data->flag.name_input);
	if (data->flag.fd_input == -1)
		return (1);
	data->flag.fd_output = ft_make_output_fd(data->flag.name_output);
	if (data->flag.fd_output == -1)
		return (1);
	if (ft_des_encrypt_process_salt(data))
		return (1);
	if (ft_des_process_key_n_vector_if_password(data))
		return (1);
	data->text = ft_read_from(data->flag.fd_input, &data->len);
	return (0);
}

int		ft_des_encrypt_if_key(t_des *data)
{
	data->is_salt_to_output = 0;
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
	return (0);
}

int		ft_des_encrypt_process_flags(t_des *data)
{
	int				error;

	if (data->flag.password)
		error = ft_des_encrypt_if_password(data);
	else if (data->flag.key == NULL)
	{
		if (ft_des_read_password_verify(data))
			return (1);
		error = ft_des_encrypt_if_password(data);
	}
	else
		error = ft_des_encrypt_if_key(data);
	if (error)
		return (1);
	(data->make_keys_fun)((uint8_t *)data->flag.keys16_48, data->flag.key8);
	ft_des_encrypt_make_output(data);
	return (0);
}
