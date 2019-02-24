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

static void	ft_delete(t_bigint *a2, t_bigint *m2, t_bigint *p, t_bigint *r)
{
	ft_bigint_del(a2);
	ft_bigint_del(m2);
	ft_bigint_del(p);
	ft_bigint_del(r);
}

static void	ft_algor(t_bigint *a2, t_bigint *m2, t_bigint *p, t_bigint *r)
{
	while (ft_bigint_notnull(a2) && ft_bigint_notnull(m2))
	{
		if (ft_bigint_equ_bigger(a2, m2))
		{
			ft_bigint_sub(a2, m2);
			ft_bigint_add(p, r);
		}
		else
		{
			ft_bigint_sub(m2, a2);
			ft_bigint_add(r, p);
		}
	}
}

int			ft_gcdex(t_bigint *rev, t_bigint *a, t_bigint *m)
{
	t_bigint		a2;
	t_bigint		m2;
	t_bigint		p;
	t_bigint		r;
	
	m2 = ft_bigint_dup(m);///poprobuvat napriamu otpravyt
	a2 = ft_bigint_dup(a);///poprobuvat napriamu otpravyt
	ft_init(&p, &r, m);
	ft_algor(&a2, &m2, &p, &r);
	if (ft_bigint_equ_value(&m2, 1) == 0)
	{
		ft_delete(&a2, &m2, &r, &p);
		return (1);
	}
	*rev = ft_bigint_dup(m);
	ft_bigint_sub(rev, &r);
	ft_delete(&a2, &m2, &r, &p);
	return (0);
}
