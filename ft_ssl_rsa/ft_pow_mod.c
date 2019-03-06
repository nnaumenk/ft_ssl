/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/27 18:44:55 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

static void	ft_is_even(t_bigint *r, t_bigint *mod)
{
	t_bigint	mul;
	t_bigint	integer;
	t_bigint	remainder;

	ft_bigint_mul(&mul, r, r);
	ft_bigint_del(r);
	ft_bigint_div(&integer, &remainder, &mul, mod);
	*r = remainder;
	ft_bigint_del(&integer);
	ft_bigint_del(&mul);
}

static void ft_is_odd(t_bigint *r, t_bigint *num, t_bigint *mod)
{
	t_bigint	mul;
	t_bigint	integer;
	t_bigint	remainder;

	ft_bigint_div(&integer, &remainder, num, mod);
	ft_bigint_mul(&mul, &remainder, r);
	ft_bigint_del(&integer);
	ft_bigint_del(&remainder);
	ft_bigint_del(r);
	ft_bigint_div(&integer, &remainder, &mul, mod);
	ft_bigint_del(&integer);
	ft_bigint_del(&mul);
	*r = remainder;
}

// size_t	ft_pow_mod_int(size_t num, size_t pow, size_t mod)
// {
// 	size_t	res;

// 	if (pow == 0)
// 		return (1);
// 	else if (pow % 2 == 0)
// 	{
// 		res = ft_pow_mod_int(num, pow / 2, mod);
// 		return ((res * res) % mod);
// 	}
// 	return (((num % mod) * ft_pow_mod_i(num, pow - 1, mod)) % mod);
// }


void		ft_pow_mod(t_bigint *r, t_bigint *num, t_bigint *pow, t_bigint *mod)
{
	if (ft_bigint_isnull(pow))
	{
		r->size = 1;
		r->value = (unsigned char *)malloc(1);
		r->value[0] = 1;
		return ;
	}
	else if ((pow->value[0] & 0x01) == 0)
	{
		ft_bigint_shr(pow, 1);
		ft_pow_mod(r, num, pow, mod);
		ft_is_even(r, mod);
		return ;
	}
	ft_bigint_decrement(pow);
	ft_pow_mod(r, num, pow, mod);
	ft_is_odd(r, num, mod);
	return ;
}
