/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_make_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 05:05:29 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 20:50:23 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

void		ft_md5_output(t_alg *my, t_md5_flags *flags, char *file)
{
	char		output[128 + 1];
	t_md5_data	data;
	int			fd;

	fd = ft_make_input_fd(file);
	if (fd == -1)
		return ;
	data.text = ft_read_from(fd, &(data.len));
	ft_close_fd(fd);
	(my->alg_pointer)((void *)&data);
	ft_ascii_to_hex(output, (char *)data.hash, data.hash_len);
	output[data.hash_len * 2] = 0;
	if (flags->q)
		ft_print_fd(1, "%s\n", output);
	else if (flags->r)
		ft_print_fd(1, "%s %s\n", output, file);
	else
		ft_print_fd(1, "%s (%s) = %s\n", my->name_big, file, output);
	ft_strdel(&data.text);
}

void		ft_md5_output_flag_s(t_alg *my, t_md5_flags *flags, char *text)
{
	char			output[128 + 1];
	t_md5_data		data;
	int			fd;

	data.text = text;
	data.len = ft_strlen(text);
	(my->alg_pointer)((void *)&data);
	ft_ascii_to_hex(output, (char *)data.hash, data.hash_len);
	output[data.hash_len * 2] = 0;
	if (flags->q)
		ft_print_fd(1, "%s\n", output);
	else if (flags->r)
		ft_print_fd(1, "%s \"%s\"\n", output, text);
	else
		ft_print_fd(1, "%s (\"%s\") = %s\n", my->name_big, text, output);
}

void		ft_md5_output_flag_p(t_alg *my)
{
	char			output[128 + 1];
	t_md5_data		data;
	int			fd;

	fd = ft_make_input_fd(NULL);
	if (fd == -1)
		return ;
	data.text = ft_read_from(fd, &(data.len));
	ft_close_fd(fd);
	(my->alg_pointer)((void *)&data);
	ft_ascii_to_hex(output, (char *)data.hash, data.hash_len);
	output[data.hash_len * 2] = 0;
	ft_print_fd(1, "%s%s\n", data.text, output);
	ft_strdel(&data.text);
}

void		ft_md5_output_noflags(t_alg *my)
{
	char			output[128 + 1];
	t_md5_data		data;
	int			fd;

	fd = ft_make_input_fd(NULL);
	if (fd == -1)
		return ;
	data.text = ft_read_from(0, &(data.len));
	ft_close_fd(fd);
	(my->alg_pointer)((void *)&data);
	ft_ascii_to_hex(output, (char *)data.hash, data.hash_len);
	output[data.hash_len * 2] = 0;
	ft_print_fd(1, "%s\n", output);
	ft_strdel(&data.text);
}
