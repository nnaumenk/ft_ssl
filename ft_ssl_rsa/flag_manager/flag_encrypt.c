/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_encrypt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:44 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	(*g_encrypt[])(t_rsa *) =
{
	ft_rsa_make_decrypt,
	ft_rsa_make_encrypt
};

int		ft_rsa_make_flag_encrypt(t_rsa *rsa)
{
	if (g_encrypt[rsa->flag.encrypt](rsa))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	return (0);
}

int		ft_rsa_check_flag_encrypt(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->encrypt = 1;
	return (0);
}
