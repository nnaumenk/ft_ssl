/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:30:00 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 00:46:51 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

int		ft_check_flag_k(int *i, int ac, char **av, t_des *data)
{
	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing key argument for %s\n", av[*i - 1]);
		return (1);
	}
	data->flag.key = av[*i];
	return (0);
}

int		ft_check_flag_v(int *i, int ac, char **av, t_des *data)
{
	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing IV argument for %s\n", av[*i - 1]);
		return (1);
	}
	data->flag.vector = av[*i];
	return (0);
}

int		ft_check_flag_p(int *i, int ac, char **av, t_des *data)
{
	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing source argument for %s\n", av[*i - 1]);
		return (1);
	}
	data->flag.password = av[*i];
	return (0);
}

int		ft_check_flag_s(int *i, int ac, char **av, t_des *data)
{
	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing salt argument for %s\n", av[*i - 1]);
		return (1);
	}
	data->flag.salt = av[*i];
	return (0);
}

int		ft_check_flag_pbkdf2(int *i, int ac, char **av, t_des *data)
{
	USE(i);
	USE(ac);
	USE(av);
	data->flag.pbkdf2 = 1;
	return (0);
}
