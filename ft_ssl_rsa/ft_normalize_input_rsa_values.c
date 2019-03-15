/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_encode_private_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:06:46 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

static void	ft_value(t_bigint *a)
{
	t_bigint	new;

	if (a->value[a->size - 1] >= 0x80)
	{
		new.size = a->size + 1;
		new.value = (unsigned char *)ft_memdup(a->value, a->size);
		new.value[a->size] = 0;
		ft_bigint_del(a);
		*a = new;
	}
}

void	ft_normalize_input_rsa_values(t_rsa *rsa)
{
	if (rsa->data.modulus.value)
		ft_value(&rsa->data.modulus);
	if (rsa->data.public_exponent.value)
		ft_value(&rsa->data.public_exponent);
	if (rsa->data.private_exponent.value)
		ft_value(&rsa->data.private_exponent);
	if (rsa->data.prime1.value)
		ft_value(&rsa->data.prime1);
	if (rsa->data.prime2.value)
		ft_value(&rsa->data.prime2);
	if (rsa->data.exponent1.value)
		ft_value(&rsa->data.exponent1);
	if (rsa->data.exponent2.value)
		ft_value(&rsa->data.exponent2);
	if (rsa->data.coefficient.value)
		ft_value(&rsa->data.coefficient);
}
