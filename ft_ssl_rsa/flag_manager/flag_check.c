/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 00:26:21 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static void	ft_check_values2(t_rsa_data *data, int *fail)
{
	if (ft_check_private_exponent(data))
	{
		ft_printf("RSA key error: d e not congruent to 1\n");
		*fail = 1;
	}
	if (ft_check_exp(data->exponent1, data->private_exponent, data->prime1))
	{
		ft_printf("RSA key error: dmp1 not congruent to d\n");
		*fail = 1;
	}
	if (ft_check_exp(data->exponent2, data->private_exponent, data->prime2))
	{
		ft_printf("RSA key error: dmq1 not congruent to d\n");
		*fail = 1;
	}
	if (ft_check_coefficient(data))
	{
		ft_printf("RSA key error: iqmp not inverse of q\n");
		*fail = 1;
	}
}

static void	ft_check_values1(t_rsa_data *data, int *fail)
{
	if ((data->public_exponent.value[0] & 0x01) == 0)
	{
		ft_printf("RSA key error: bad e value\n");
		*fail = 1;
	}
	if (ft_check_primality(data->prime1))
	{
		ft_printf("RSA key error: p not prime\n");
		*fail = 1;
	}
	if (ft_check_primality(data->prime2))
	{
		ft_printf("RSA key error: q not prime\n");
		*fail = 1;
	}
	if (ft_check_modulus(data))
	{
		ft_printf("RSA key error: n does not equal p * q\n");
		*fail = 1;
	}
}

int			ft_rsa_make_flag_check(t_rsa *rsa)
{
	int		fail;

	if (rsa->flag.check)
	{
		if (rsa->flag.pubin)
		{
			ft_printf("Only private keys can be checked\n");
			return (0);
		}
		fail = 0;
		ft_check_values1(&rsa->data, &fail);
		ft_check_values2(&rsa->data, &fail);
		if (fail)
			return (1);
		ft_printf("RSA key ok\n");
	}
	return (0);
}

int			ft_rsa_check_flag_check(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->check = 1;
	return (0);
}
