/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_decode_public_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:06:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_asn1_get_value(t_bigint *a, char tag, char **ptr, size_t *len)
{
	if (*len < 1 || **ptr != tag)
		return (1);
	*len -= 1;
	(*ptr) += 1;
	if (ft_asn1_get_size(&a->size, ptr, len))
		return (1);
	if (*len < a->size)
		return (1);
	a->value = (unsigned char *)ft_memdup(*ptr, a->size);
	ft_memrev(a->value, a->size);
	*len -= a->size;
	*ptr += a->size;
	return (0);
}
