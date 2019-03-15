/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:48 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_make_flag_in(t_rsa *rsa)
{
	int		fd;

	fd = ft_make_input_fd(rsa->flag.in);
	if (fd == -1)
		return (1);
	rsa->text = ft_read_from(fd, &rsa->len);
	ft_close_fd(fd);
	return (0);
}

int		ft_rsa_check_flag_in(int *i, int ac, char **av, t_rsa_flag *flag)
{
	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing file argument for %s\n", av[*i - 1]);
		return (1);
	}
	flag->in = av[*i];
	return (0);
}
