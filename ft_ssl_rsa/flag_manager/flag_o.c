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



int			ft_rsa_make_flag_o(t_rsa *data)
{
	if (data->flag.text)
	{
		if (ft_get_data(&data->data, data->text, data->len))
		{
			ft_print("error\n");
			//ft_strdel(&text);
			return (1);
		}
		ft_strdel(&data->text);
		ft_print_data(&data->data);
	}
	return (0);
}




int		ft_rsa_check_flag_o(int *i, int ac, char **av, t_rsa_flag *flag)
{
	if (++(*i) == ac)
	{
		ft_print("ft_ssl: missing file argument for %s\n", av[*i - 1]);
		return (1);
	}
	flag->out = av[*i];
	return (0);
}
