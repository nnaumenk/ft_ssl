/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:47:55 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 19:09:39 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

#define READ_BUF 1000

void	ft_close_fd(int fd)
{
	if (fd == 0 || fd == 1 || fd == 2)
		return ;
	close(fd);
}

char	*ft_read_from(int fd, size_t *len)
{
	char		*str;
	char		buf[READ_BUF];
	size_t		buf_len;

	str = ft_strnew(0);
	*len = 0;
	while (1)
	{
		buf_len = read(fd, buf, READ_BUF);
		str = ft_memjoin_del(str, buf, *len, buf_len);
		*len += buf_len;
		if (buf_len == 0)
			break ;
	}
	return (str);
}

int		ft_make_input_fd(char *file)
{
	int fd;

	if (file)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			ft_print_fd(2, "ft_ssl: '%s' %s\n", file, "is not a file");
			return (-1);
		}
	}
	else
	{
		file = "STDIN";
		fd = 0;
	}
	if (read(fd, 0, 0) == -1)
	{
		ft_print_fd(2, "ft_ssl: error in reading '%s'\n", file);
		return (-1);
	}
	return (fd);
}

int		ft_make_output_fd(char *file)
{
	int fd;

	if (file)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
		if (fd == -1)
		{
			ft_print_fd(2, "ft_ssl: '%s' %s\n", file, "is not a file");
			return (-1);
		}
	}
	else
	{
		file = "STDOUT";
		fd = 1;
	}
	if (write(fd, 0, 0) == -1)
	{
		ft_print_fd(2, "ft_ssl: error in reading '%s'\n", file);
		return (-1);
	}
	return (fd);
}
