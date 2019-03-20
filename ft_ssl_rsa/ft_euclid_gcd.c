/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_euclid_gcd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 09:54:02 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

static void	ft_algor(t_bigint *gcd, t_bigint *a, t_bigint *b)
{
	t_bigint	tmp;
	t_bigint	integer;
	t_bigint	remainder;

	while (ft_bigint_isnull(a) == 0)
	{
		if (ft_bigint_bigger(b, a))
		{
			ft_bigint_div(&integer, &remainder, b, a);
			ft_bigint_del(&integer);
			ft_bigint_del(b);
			*b = *a;
			*a = remainder;
		}
		else
		{
			tmp = *b;
			*b = *a;
			*a = tmp;
		}
	}
	ft_bigint_del(a);
	*gcd = *b;
}

void		ft_euclid_gcd(t_bigint *gcd, t_bigint *a, t_bigint *b)
{
	t_bigint	buf1;
	t_bigint	buf2;

	buf1 = ft_bigint_dup(a);
	buf2 = ft_bigint_dup(b);
	ft_algor(gcd, &buf1, &buf2);
}
