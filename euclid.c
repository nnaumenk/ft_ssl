/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 16:53:13 by nnaumenk         ###   ########.fr       */
                                                                            
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

static int	ft_algor(t_bigint p, t_bigint r, t_bigint a, t_bigint mod)
{
	while (ft_bigint_notnull(&a) && ft_bigint_notnull(&mod))
	{
		ft_bigint_print("a", &a);
		ft_bigint_print("b", &mod);
		if (ft_bigint_equ_bigger(&a, &mod))
		{
			// ft_bigint_sub(&a, &mod);
			// ft_bigint_add(&p, &r);
			p = p + r * (a / mod);
			a = a % mod;

		}
		else
		{
			// ft_bigint_sub(&mod, &a);
			// ft_bigint_add(&r, &p);
			r = r + p * (mod / a);
			mod = mod % a;
		}
	}
	if (ft_bigint_equ_value(&mod, 1) == 0)
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
	if (ft_algor(p, r, ft_bigint_dup(a), ft_bigint_dup(mod)))
	{
		ft_bigint_del(&r);
		ft_bigint_del(&p);
		return (1);
	}
	*inverse = ft_bigint_dup(mod);
	ft_bigint_sub(inverse, &r);
	ft_bigint_del(&r);
	ft_bigint_del(&p);
	return (0);
}
