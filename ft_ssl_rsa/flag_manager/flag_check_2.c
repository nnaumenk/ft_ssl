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
	if ((prime.value[0] & 0x01) == 0)
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

	if (ft_bigint_isvalue(&data->prime1, 1) ||
		ft_bigint_isvalue(&data->prime2, 1))
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

int		ft_check_exp(t_bigint exp, t_bigint private_exp, t_bigint prime)
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
