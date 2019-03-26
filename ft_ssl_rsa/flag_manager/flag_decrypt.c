/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_decrypt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/26 18:55:55 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	(*g_encrypt[])(t_rsa *) =
{
	ft_rsa_make_encrypt,
	ft_rsa_make_decrypt
};

int		ft_rsa_make_flag_decrypt(t_rsa *rsa)
{
	if (g_encrypt[rsa->flag.decrypt](rsa))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	return (0);
}

int		ft_rsa_check_flag_decrypt(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->decrypt = 1;
	return (0);
}
