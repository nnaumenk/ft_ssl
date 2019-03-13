/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:58 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_make_flag_out(char *text, size_t len, char *flag_out)
{
	int		fd;

	fd = ft_make_output_fd(flag_out);
	write(fd, text, len);
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
