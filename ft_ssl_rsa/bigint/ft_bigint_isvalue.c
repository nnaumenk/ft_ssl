/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_isvalue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/27 18:39:59 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

int		ft_bigint_isvalue(t_bigint *a, unsigned char value)
{
	if (a->size == 0)
		return (0);
	if (a->value[0] != value)
		return (0);
	a->value++;
	a->size--;
	if (ft_bigint_isnull(a))
	{
		a->value--;
		a->size++;
		return (1);
	}
	a->value--;
	a->size++;
	return (0);
}
