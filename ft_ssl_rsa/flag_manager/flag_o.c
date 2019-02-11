/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:58 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_make_flag_o(t_rsa *data)
{
	int		fd;

	fd = ft_make_output_fd(data->flag.o);
	if (fd == -1)
		return (1);
	write(fd, data->text, data->len);
	if (fd != 1)
		close(fd);
	return (0);
}

int		ft_rsa_check_flag_o(int *i, int ac, char **av, t_rsa_flag *flag)
{
	if (++(*i) == ac)
	{
		ft_print("ft_ssl: missing file argument for %s\n", av[*i - 1]);
		return (1);
	}
	flag->o = av[*i];
	return (0);
}
