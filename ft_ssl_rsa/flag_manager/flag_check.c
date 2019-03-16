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

int		ft_check_primality(t_bigint prime)
{
	if (ft_bigint_isvalue(&prime, 2))
		return (0);
	if (ft_bigint_isvalue(&prime, 3))
		return (0);
	if (ft_bigint_isvalue(&prime, 0))
		return (1);
	if (ft_bigint_isvalue(&prime, 1))
		return (1);
	if (prime.value[0] & 0x01 == 0)
		return (1);
	if (ft_is_composit_by_miller_rabin(&prime, 2))
		return (1);
	return (0);
}

int		ft_check_modulus(t_rsa_data *data)
{
	t_bigint	mul;

	ft_bigint_mul(&mul, &data->prime1, &data->prime2);
	if (ft_bigint_equal(&data->modulus, &mul) == 0)
	{
		ft_bigint_del(&mul);
		return (1);
	}
	ft_bigint_del(&mul);
	return (0);
}

int		ft_check_private_exponent(t_rsa_data *data)
{
	t_bigint	eiler;
	t_bigint	integer;
	t_bigint	remainder;
	t_bigint	mul;

	if (ft_bigint_isvalue(&data->prime1, 1) || ft_bigint_isvalue(&data->prime2, 1))
		return (1);
	ft_bigint_decrement(&data->prime1);
	ft_bigint_decrement(&data->prime2);
	ft_bigint_mul(&eiler, &data->prime1, &data->prime2);
	ft_bigint_increment(&data->prime1);
	ft_bigint_increment(&data->prime2);
	ft_bigint_mul(&mul, &data->private_exponent, &data->public_exponent);
	ft_bigint_div(&integer, &remainder, &mul, &eiler);
	ft_bigint_del(&integer);
	ft_bigint_del(&eiler);
	ft_bigint_del(&mul);
	if (ft_bigint_isvalue(&remainder, 1) == 0)
	{
		ft_bigint_del(&remainder);
		return (1);
	}
	ft_bigint_del(&remainder);
	return (0);
}

// 	RSA key error: bad e value
// RSA key error: p not prime
// RSA key error: n does not equal p q
// RSA key error: d e not congruent to 1
// RSA key error: dmp1 not congruent to d
// RSA key error: dmq1 not congruent to d
// RSA key error: iqmp not inverse of q

//zrobur ft_bigint_div_

int		ft_check_exponent(t_bigint exp, t_bigint private_exp, t_bigint prime)
{
	t_bigint	integer;
	t_bigint	remainder;

	if (ft_bigint_isvalue(&prime, 1))
		return (1);
	ft_bigint_decrement(&prime);
	ft_bigint_div_safe(&integer, &remainder, &private_exp, &prime);
	ft_bigint_increment(&prime);
	ft_bigint_del(&integer);
	if (ft_bigint_equal(&remainder, &exp) == 0)
	{
		ft_bigint_del(&remainder);
		return (1);
	}
	ft_bigint_del(&remainder);
	return (0);
}

int		ft_check_coefficient(t_rsa_data *data)
{
	t_bigint	coefficient;

	if (ft_mod_inverse(&coefficient, &data->prime2, &data->prime1))
		return (1);
	if (ft_bigint_equal(&coefficient, &data->coefficient) == 0)
	{
		ft_bigint_del(&coefficient);
		return (1);
	}
	ft_bigint_del(&coefficient);
	return (0);
}

int		ft_check_values(t_rsa_data *data)
{
	int		fail;

	fail = 0;
	if ((data->public_exponent.value[0] & 0x01) == 0)
	{
		ft_printf("RSA key error: bad e value\n");
		fail = 1;
	}
	if (ft_check_primality(data->prime1))
	{
		ft_printf("RSA key error: p not prime\n");
		fail = 1;
	}
	if (ft_check_primality(data->prime2))
	{
		ft_printf("RSA key error: q not prime\n");
		fail = 1;
	}
	if (ft_check_modulus(data))
	{
		ft_printf("RSA key error: n does not equal p * q\n");
		fail = 1;
	}
	if (ft_check_private_exponent(data))
	{
		ft_printf("RSA key error: d e not congruent to 1\n");
		fail = 1;
	}
	if (ft_check_exponent(data->exponent1, data->private_exponent, data->prime1))
	{
		ft_printf("RSA key error: dmp1 not congruent to d\n");
		fail = 1;
	}
	if (ft_check_exponent(data->exponent2, data->private_exponent, data->prime2))
	{
		ft_printf("RSA key error: dmq1 not congruent to d\n");
		fail = 1;
	}
	if (ft_check_coefficient(data))
	{
		ft_printf("RSA key error: iqmp not inverse of q\n");
		fail = 1;
	}
	return (fail);
}

int		ft_rsa_make_flag_check(t_rsa *rsa)
{
	if (rsa->flag.check)
	{
		if (rsa->flag.pubin)
		{
			ft_printf("Only private keys can be checked\n");
			return (0);
		}
		if (ft_check_values(&rsa->data))
			return (1);
		ft_printf("RSA key ok\n");
	}
	return (0);
}

int		ft_rsa_check_flag_check(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->check = 1;
	return (0);
}
