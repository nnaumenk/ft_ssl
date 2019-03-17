/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_input_rsa_values.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/16 22:52:20 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

static void	ft_value(t_bigint *a)
{
	t_bigint	new;

	if (a->value)
	{
		if (a->value[a->size - 1] >= 0x80)
		{
			new.size = a->size + 1;
			new.value = (unsigned char *)malloc(new.size);
			ft_memcpy(new.value, a->value, a->size);
			new.value[a->size] = 0;
			ft_bigint_del(a);
			*a = new;
		}
	}
}

void	ft_normalize_input_rsa_values(t_rsa *rsa)
{
	ft_value(&rsa->data.modulus);
	ft_value(&rsa->data.public_exponent);
	ft_value(&rsa->data.private_exponent);
	ft_value(&rsa->data.prime1);
	ft_value(&rsa->data.prime2);
	ft_value(&rsa->data.exponent1);
	ft_value(&rsa->data.exponent2);
	ft_value(&rsa->data.coefficient);
}
