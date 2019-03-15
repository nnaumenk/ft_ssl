/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 09:54:05 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

static void	ft_init(t_bigint *p, t_bigint *r, t_bigint *m)
{
	p->size = m->size;
	r->size = m->size;
	p->value = (unsigned char *)malloc(m->size);
	r->value = (unsigned char *)malloc(m->size);
	ft_bzero(p->value, m->size);
	ft_bzero(r->value, m->size);
	ft_bigint_increment(p);
}

static void	ft_iteration(t_bigint *p, t_bigint *r, t_bigint *a, t_bigint *mod)
{
	t_bigint	integer;
	t_bigint	remainder;
	t_bigint	mul;

	ft_bigint_div(&integer, &remainder, a, mod);
	ft_bigint_mul(&mul, r, &integer);
	ft_bigint_add(&mul, p);
	ft_bigint_del(p);
	*p = mul;
	ft_bigint_del(a);
	*a = remainder;
	ft_bigint_del(&integer);
}

static int	ft_algor(t_bigint *p, t_bigint *r, t_bigint a, t_bigint mod)
{
	while (ft_bigint_isnull(&a) == 0 && ft_bigint_isnull(&mod) == 0)
	{
		if (ft_bigint_equ_bigger(&a, &mod))
			ft_iteration(p, r, &a, &mod);
		else if (ft_bigint_isvalue(&a, 1))
		{
			ft_bigint_decrement(&mod);
			ft_iteration(r, p, &mod, &a);
			ft_bigint_increment(&mod);
		}
		else
			ft_iteration(r, p, &mod, &a);
	}
	if (ft_bigint_isvalue(&mod, 1) == 0)
	{
		ft_bigint_del(&a);
		ft_bigint_del(&mod);
		return (1);
	}
	ft_bigint_del(&a);
	ft_bigint_del(&mod);
	return (0);
}

int			ft_mod_inverse(t_bigint *inverse, t_bigint *a, t_bigint *mod)
{
	t_bigint		p;
	t_bigint		r;
	
	ft_init(&p, &r, mod);
	if (ft_algor(&p, &r, ft_bigint_dup(a), ft_bigint_dup(mod)))
	{
		ft_bigint_del(&r);
		ft_bigint_del(&p);
		return (1);
	}
	*inverse = ft_bigint_dup(mod);
	ft_bigint_sub(inverse, &r);
	ft_bigint_del(&r);
	ft_bigint_del(&p);
	ft_bigint_normalize(inverse);
	return (0);
}
