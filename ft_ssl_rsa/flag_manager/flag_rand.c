/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_rand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:01:12 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_make_flag_rand(char *file)
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
		file = "/dev/urandom";
		fd = open(file, O_RDONLY);
	}
	if (read(fd, 0, 0) == -1)
	{
		ft_print_fd(2, "ft_ssl: error in reading '%s'\n", file);
		return (-1);
	}
	return (fd);
}

int		ft_rsa_check_flag_rand(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	USE(flag);
	flag->in = NULL;
	return (0);
}
