/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/16 13:24:34 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_make_flag_out(t_rsa *rsa)
{
	int		fd;

	fd = ft_make_output_fd(rsa->flag.out);
	if (fd == -1)
		return (1);
	write(fd, rsa->text, rsa->len);
	ft_close_fd(fd);
	return (0);
}

int		ft_rsa_check_flag_out(int *i, int ac, char **av, t_rsa_flag *flag)
{
	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing file argument for %s\n", av[*i - 1]);
		return (1);
	}
	flag->out = av[*i];
	return (0);
}
