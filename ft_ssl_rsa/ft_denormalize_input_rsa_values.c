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
	if (a->value)
	{
		if (a->value[a->size - 1] == 0)
			a->size--;
	}
}

void		ft_denormalize_input_rsa_values(t_rsa *rsa)
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
