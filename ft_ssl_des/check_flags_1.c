/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:28:05 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/20 13:31:36 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

int		ft_check_flag_i(int *i, int ac, char **av, t_des *data)
{
	if (++(*i) == ac)
	{
		ft_print("ft_ssl: missing file argument for %s\n", av[*i - 1]);
		return (1);
	}
	data->flag.name_input = av[*i];
	return (0);
}

int		ft_check_flag_o(int *i, int ac, char **av, t_des *data)
{
	if (++(*i) == ac)
	{
		ft_print("ft_ssl: missing file argument for %s\n", av[*i - 1]);
		return (1);
	}
	data->flag.name_output = av[*i];
	return (0);
}

int		ft_check_flag_e(int *i, int ac, char **av, t_des *data)
{
	USE(i);
	USE(ac);
	USE(av);
	data->flag.decrypt = 0;
	return (0);
}

int		ft_check_flag_d(int *i, int ac, char **av, t_des *data)
{
	USE(i);
	USE(ac);
	USE(av);
	data->flag.decrypt = 1;
	return (0);
}

int		ft_check_flag_a(int *i, int ac, char **av, t_des *data)
{
	USE(i);
	USE(ac);
	USE(av);
	data->flag.a = 1;
	return (0);
}
